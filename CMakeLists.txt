cmake_minimum_required(VERSION 3.6)
project(intlist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES IntList.cpp IntList.h main.cpp)
add_executable(intlist ${SOURCE_FILES})