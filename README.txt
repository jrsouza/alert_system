1) To execute the alert_usr you must have ROS and ORB_SLAM2 installed.

2) We use this version of the ORB_SLAM2: https://github.com/raulmur/ORB_SLAM2

3) Extract the alert_usr and compile package using "catkin_make".

4) After compiling go to "alert_usr/src" and copy the file "beep-02.wav" to the folder catkin/devel/lib/alert_usr/src

5) Run ROS using "roscore", after run ORB_SLAM2 with the correct calibration files. In our case, we use the calibration file "ardrone.yaml" and the camera topic was "ardrone/front/image_raw"

6) Run ORB_SLAM2 with the following command: rosrun ORB_SLAM2 Mono Vocabulary/ORBvoc.txt Examples/Monocular/ardrone.yaml/camera/image_raw:=/ardrone/front/image_raw

7) Run the alert_usr by accessing "catkin/devel/lib/alert_usr" and execute "./alerta_usr" Then, will be shown on the terminal after executing the alert_usr, messages that show the Euclidean distance between the AR.Drone 2.0 and the starting point, and after passing the distance set in the code will beep.