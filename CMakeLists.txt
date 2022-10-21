cmake_minimum_required(VERSION 3.23)
project(Challenge)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
FILE(GLOB_RECURSE  MyCSources Src/*.cpp)
add_executable(example ${MyCSources})
#add_executable(example main.cpp Tests/Test.cpp Src/IList.h)
target_link_libraries(example gtest_main)
add_test(NAME example_test COMMAND example)

add_executable(Challenge main.cpp)

