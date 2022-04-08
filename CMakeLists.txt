cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 17)
project(
        cmake_header_only
        VERSION 0.1
        DESCRIPTION "my amazing project"
        LANGUAGES CXX)

#load Catch2 v3.0.0-preview4
Include(FetchContent)
FetchContent_Declare(Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v3.0.0-preview4)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
enable_testing()
include(CTest)
include(Catch)


#Iron headeronly project
project(iron
        VERSION 0.1
        DESCRIPTION "header only library"
        LANGUAGES CXX
        )

include_directories(iron)
add_library(iron INTERFACE)
target_include_directories(iron INTERFACE iron/)
#ref https://cmake.org/cmake/help/latest/command/add_library.html#id4
# tutorial http://mariobadr.com/creating-a-header-only-library-with-cmake.html


#Iron-test catch2 project
project(iron-test LANGUAGES CXX)
add_executable(iron-test iron/test/factories.cxx)
target_link_libraries(iron-test
        PRIVATE
        Catch2::Catch2WithMain
        )
target_link_libraries(iron-test INTERFACE iron)
catch_discover_tests(iron-test)
