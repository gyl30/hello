cmake_minimum_required(VERSION 3.19)

project(hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_DEBUG_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost)

set(BOOST_INCLUDE_DIR )
set(RAPIDJSON_DIR third/rapidjson/include)
set(RANGE_DIR third/range-v3/include)


include_directories(
        ${Boost_INCLUDE_DIRS}
        ${RAPIDJSON_DIR}
        ${RANGE_DIR}
)

set(PROJECT_SOURCES
        main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})


target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_LIBRARIES} Threads::Threads)
