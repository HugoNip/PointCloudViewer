cmake_minimum_required(VERSION 3.0)
project(ch5)

set(CMAKE_CXX_STANDARD 11)

# Eigen
find_package(Eigen3 3.3.0 REQUIRED)
message("Eigen3 Version: ${Eigen3_VERSION}")
include_directories(${EIGEN3_INCLUDE_DIR})

# OpenGL
find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDES_DIRS})

# Executable
add_executable(imageBasic imageBasic.cpp)
target_link_libraries(imageBasic ${OpenCV_LIBS})

add_executable(undistortImage undistortImage.cpp)
target_link_libraries(undistortImage ${OpenCV_LIBS})

add_executable(stereoVision stereoVision.cpp)
target_link_libraries(stereoVision ${OpenCV_LIBS} ${Pangolin_LIBRARIES})

add_executable(jointMap jointMap.cpp)
target_link_libraries(jointMap ${OpenCV_LIBS} ${Pangolin_LIBRARIES})