#pragma once

#include <string>
#include <utility>

using namespace std;

namespace iron {
    template<class T>
    struct Option {
    public:
        const T value;
        const bool hasValue;
        const string message;

        Option(T value, bool hasValue, string message) :
                value(value),
                hasValue(hasValue),
                message(std::move(message)) {}
    };
}