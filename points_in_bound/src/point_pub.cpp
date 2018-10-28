# include "ros/ros.h"
#include "std_msgs/String.h"
#include "points_in_bound/Num.h"
#include "points_in_bound/array.h"
#include <cstdlib>
#include <sstream>
#include <vector>


int main(int argc, char **argv){

ros::init(argc, argv, "talker");


ros::NodeHandle n;

ros::Publisher chatter_pub = n.advertise<points_in_bound::array>("chatter", 1000);

ros::Rate loop_rate(1);

int count = 0;

while(ros::ok()){

//first need point generator, then make array of points
points_in_bound::array arr;

points_in_bound::Num info;

//generate 20 random points on +ve x,y coordinate plane
for(int i = 0; i < 20; i++){

  info.x = (std::rand() % 100 + (std::rand()/((float)RAND_MAX+1)));
  info.y = (std::rand() % 100 + (std::rand()/((float)RAND_MAX+1)));

  arr.info_array.push_back(info);

}

for (int i = 0; i < 20; i++){
  ROS_INFO("array element: [%d], is = [%f] and [%f]", i+1, arr.info_array[i].x, arr.info_array[i].y);
}
  ROS_INFO("\n\n");

chatter_pub.publish(arr);

ros::spinOnce();

loop_rate.sleep();
++count;

}


return 0;

}