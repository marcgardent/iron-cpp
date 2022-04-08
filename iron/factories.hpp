#pragma once

#include <iostream>
#include "option.hpp"

namespace iron {
    template<class T>
    Option<T> Some(T value) {

        return Option<T>(value, true, "");
    }

    template<class T>
    Option<T> Fail(string message) {
        std::cout << "EDIT SOURCE 3" << std::endl;
        return Option<T>(T(), false, message);
    }
}