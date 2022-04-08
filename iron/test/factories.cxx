#include <catch2/catch_test_macros.hpp>
#include <utility>
#include "factories.hpp"

#define DEFAULT "default value"
#define CUSTOM "custom value"
using namespace iron;

class MySuperClass{
    public:
        const std::string field;
        explicit MySuperClass(std::string field) : field(std::move(field)){
        }
        MySuperClass() : field(DEFAULT){

        }
};


SCENARIO("Use Options"){
    WHEN("Some"){
        auto target = Some<MySuperClass>(MySuperClass(CUSTOM));
        THEN("it has value"){
            CHECK(target.hasValue == true);
            CHECK(target.value.field == CUSTOM);
        }
    }
    WHEN("None"){
        auto target = Fail<MySuperClass>("test");
        THEN("it has no values"){
            CHECK(target.hasValue == false);
            CHECK(target.value.field == DEFAULT);
        }
    }
}