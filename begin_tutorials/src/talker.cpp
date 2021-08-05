#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64MultiArray.h"
// ~~
#include <vector>
// #include "std_msgs/msg/float64_multi_array.hpp"

#include <sstream>

void fakefunction(){}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Float64MultiArray>("/joint_angles", 1000);
  // TODO: need a subscriber

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::Float64MultiArray msg;c // create new msg \ head \ data <- vector

    std::vector<double> state = {1.0, 10.0, 5.0}; // 

    // TODO: compute pho
      // recive a path
      // use fake function to compute new pho

    // put in msg
    state[0] = count;
    state[1] = count;
    state[2] = count;

    msg.data = state;

    // publish msg
    chatter_pub.publish(msg);

    // spin msg once
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}