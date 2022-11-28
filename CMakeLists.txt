cmake_minimum_required(VERSION 3.23)
project(UofACampusMap)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(UofACampusMap
        include/disjoint_set.hpp
        include/graph.hpp
        include/sort.hpp
        src/algorithms/dijkstra.cpp
        src/algorithms/kruskal.cpp
        src/algorithms/prim.cpp
        src/data_structures/disjoint_set.cpp
        src/sort/msort.cpp
        src/graph.cpp
        src/main.cpp)
