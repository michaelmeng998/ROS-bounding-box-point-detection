#include "ros/ros.h"
#include "points_in_bound/Num.h"
#include "points_in_bound/array.h"
#include "geometry_msgs/Point32.h"

#include <cstdlib>


void chatterCallback(const points_in_bound::array::ConstPtr& arr){

/*first create a random bounding box sqaure starting from a point on +ve
x,y plane and then growing in positive direction by a random factor
*/
    geometry_msgs::Point32 rand_pnt1;
    geometry_msgs::Point32 rand_pnt2;
    geometry_msgs::Point32 rand_pnt3;
    geometry_msgs::Point32 rand_pnt4;

    geometry_msgs::Point32 factor;


    rand_pnt1.x = std::rand() % 100 + (std::rand()/((float)RAND_MAX+1));
    rand_pnt1.y = std::rand() % 100 + (std::rand()/((float)RAND_MAX+1));

    factor.z = std::rand() % 100 + (std::rand()/((float)RAND_MAX+1));

    rand_pnt2.x = rand_pnt1.x;
    rand_pnt2.y =  rand_pnt1.y + factor.z;

    rand_pnt3.x = rand_pnt1.x + factor.z;
    rand_pnt3.y = rand_pnt1.y + factor.z;

    rand_pnt4.x = rand_pnt1.x + factor.z;
    rand_pnt4.y = rand_pnt1.y;


    ROS_INFO("1 = ([%f], [%f] \n", rand_pnt1.x, rand_pnt1.y);
    ROS_INFO("2 = ([%f], [%f] \n", rand_pnt2.x, rand_pnt2.y);
    ROS_INFO("3 = ([%f], [%f] \n", rand_pnt3.x, rand_pnt3.y);
    ROS_INFO("4 = ([%f], [%f] \n", rand_pnt4.x, rand_pnt4.y);


int count = 0;

points_in_bound::Num temp;

for(int i = 0; i < 20; i++){

temp.x = arr->info_array[i].x;
temp.y = arr->info_array[i].y;

if(temp.x >= rand_pnt1.x && temp.x <= rand_pnt4.x){
  if(temp.y >= rand_pnt1.y && temp.y <= rand_pnt2.y){
      count++;
      ROS_INFO("point x -[%f] and y - [%f] is in the box", temp.x, temp.y);
    }
  }
}

ROS_INFO("number of points in the bounding box is [%d] \n\n\n\n", count);

}

int main(int argc, char **argv){

ros::init(argc, argv, "listener");

ros::NodeHandle n;

ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

ros::spin();

return 0;


}
