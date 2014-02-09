cmake_minimum_required(VERSION 2.8)
project(postgreconnectionintarface)

add_executable(postgreconnectionintarface main.cpp)
target_link_libraries(postgreconnectionintarface pq pqxx)
