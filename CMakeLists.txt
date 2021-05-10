cmake_minimum_required(VERSION 3.5)

project(giggle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(giggle main.cpp testcase.cpp)

target_compile_options(giggle PRIVATE -Wall -Wextra -pedantic -Wconversion)
#-Werror
add_compile_definitions(VERBOSE)

install(FILES
    small-testdata.in
    DESTINATION
    ${CMAKE_SOURCE_DIR}/build)
