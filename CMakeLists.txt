cmake_minimum_required(VERSION 3.10)
project(linked_hash_map)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(linked_hash_map
        linked_hash_map.hpp
        test.cpp)
