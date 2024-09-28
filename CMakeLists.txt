cmake_minimum_required(VERSION 3.16)
project(VulkanRenderer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "C:\\VulkanSDK\\1.3.290.0")

find_package(Vulkan REQUIRED)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES main.cpp src/app.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

if(TARGET SDL2::SDL2main)
    target_link_libraries(VulkanRenderer SDL2::SDL2main)
endif()

target_link_libraries(VulkanRenderer SDL2::SDL2)

target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)