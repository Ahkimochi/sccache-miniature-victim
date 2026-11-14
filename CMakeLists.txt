cmake_minimum_required(VERSION 3.20)
project(sccache_miniature CXX)

# Deterministic compilation unit: fixed flags + fixed build dir (see
# ../RUNBOOK.md) keep the sccache key identical between the fork run and
# the trusted run. The executable simply prints what marker_value()
# returns, so a cache-restored object is observable end-to-end (exit
# code + stdout).
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(marker STATIC marker.cpp)
add_executable(mini main.cpp)
target_link_libraries(mini PRIVATE marker)
