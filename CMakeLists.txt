cmake_minimum_required(VERSION 3.29.0)
project(planning)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)  # 所有可执行文件和动态库存放 bin 目录

# 收集 src 目录下的所有 .cpp 文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS)

# 定义共享库 common
add_library(common SHARED ${SRC_LISTS})

# 让 common 目标包含 include 目录的头文件
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 定义可执行文件 planning_main
add_executable(planning_main planning_main.cpp)

# 让 planning_main 目标包含 include 目录的头文件
target_include_directories(planning_main PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 链接 common 库到 planning_main
target_link_libraries(planning_main PUBLIC common)
