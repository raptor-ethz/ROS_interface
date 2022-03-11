add_executable(${PROJECT_NAME}
  comm_lib_interface_node.cpp
)

add_subdirectory(communication_lib)


target_link_libraries(${PROJECT_NAME} PUBLIC
  ${catkin_LIBRARIES}
)


# Third party dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE
fastcdr 
fastrtps
comm_lib
)