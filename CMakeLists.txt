cmake_minimum_required(VERSION 2.6)
project(file)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")
 
add_executable(file main.cpp)
