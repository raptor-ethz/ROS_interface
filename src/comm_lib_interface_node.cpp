#include <ros/ros.h>


#include "domain_participant.h"
#include "subscriber.h"

#include "MocapPubSubTypes.h"
#include "sensor_msgs/msgs/Mocap.h"

int main(int argc, char** argv) {
  //FastDDS init
  // Create participant. Arguments-> Domain id, QOS name
  DefaultParticipant dp(0, "mocap_subscriber");

  //subscriber message
  cpp_msg::Mocap mocap_msg;
  // Create publisher with msg type
  DDSSubscriber mocap_sub(idl_msg::MocapPubSubType(), &mocap_msg,
                          "mocap_srl_quad", dp.participant());

  //ROS init
  ros::init(argc, argv, "comm_lib_interface");
  ros::NodeHandle nodeHandle("~");

  while(true){

  }

  ros::spin();
  return 0;
}
