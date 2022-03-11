cmake_minimum_required(VERSION 3.16)
project(comm_lib_interface)
set(CMAKE_CXX_STANDARD 17)

# use C++11
add_compile_options(-std=c++11)

# Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs 
)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS
  CATKIN_DEPENDS
    roscpp
    sensor_msgs
)


###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_subdirectory(src)



#############
## Install ##
#############

# Mark executables for installation
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)