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
    lib
  CATKIN_DEPENDS
    roscpp
    sensor_msgs
  LIBRARIES 
    comm_lib
)

###########
## Build ##
###########

add_subdirectory(lib)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


# Declare a C++ executable
add_executable(${PROJECT_NAME}
  src/comm_lib_interface_node.cpp
)

# Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME} PUBLIC
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
comm_lib
)

# Third party dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE
fastcdr 
fastrtps
)


#############
## Install ##
#############

# Mark executables for installation
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


# Mark other files for installation (e.g. launch and bag files, etc.)
# install(DIRECTORY launch config rviz
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )
