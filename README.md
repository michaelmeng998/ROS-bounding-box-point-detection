# ROS-bounding-box-point-detection
This is a ROS publisher/subscriber which generates a random bounding box (in the +ve x,y coordinate) and also generates 20 random x,y coordinate points. Then the program determines how many points are detected inside that randomly generated bounding box.

The random points are generated at the publisher, and the subsriber generates the random bounding box and through subscribing to the publisher it takes the 20 random points and determines how many are inside the bounding box.
