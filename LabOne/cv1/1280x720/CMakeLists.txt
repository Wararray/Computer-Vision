cmake_minimum_required(VERSION 2.8)
project( cv1_1280x720 )
find_package( OpenCV REQUIRED )
add_executable( cv1_1280x720 cv1_1280x720.cpp )
target_link_libraries( cv1_1280x720 ${OpenCV_LIBS} )