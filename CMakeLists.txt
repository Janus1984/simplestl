cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -fsanitize=address")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "CXX flags: ${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(XXX LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(ncnn_stl STATIC src/simplestl.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC ncnn_stl)

enable_testing()

add_executable(unit_test test/unit_test.cpp)
find_package(GTest CONFIG REQUIRED)
target_link_libraries(unit_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
target_link_libraries(unit_test PRIVATE ncnn_stl)

add_test(AllTestsInMain unit_test)