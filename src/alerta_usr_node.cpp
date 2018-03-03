#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "geometry_msgs/PoseStamped.h"
#include <bits/stdc++.h>

double xi,yi,zi;
double xf,yf,zf;
double soma_dist = 0.0;
int cont = 0;

// Fazer a diferença nos três eixos (x, y, z) de valores da posição atual com a posição anterior

void poseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg)
{	

	if(cont == 0)
	{
		xi = msg->pose.position.x; // x anterior
		yi = msg->pose.position.y;
		zi = msg->pose.position.z;
		cont = 1;
	}

	xf =msg->pose.position.x; // x atual
	yf = msg->pose.position.y;
	zf = msg->pose.position.z;
	
	double diff_x = (xf-xi);
	double diff_y = (yf-yi);
	double diff_z = (zf-zi);
	soma_dist = pow(diff_x, 2.0) + pow(diff_y, 2.0) + pow(diff_z, 2.0); // somatorio das distâncias
    //ROS_INFO("Inicial %lf %lf %lf", xi, yi, zi);

    //ROS_INFO("Euclidiana %lf", sqrt(soma_dist));
    ROS_INFO("Dist %lf\n",sqrt(soma_dist) );
    if (sqrt(soma_dist) > 0.50) 
    {
    	system("canberra-gtk-play -f beep-02.wav");
    }
    	

}

int main(int argc, char **argv)
{
 

  ros::init(argc, argv, "alerta_usr");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/orb_slam2/pose", 1000, poseCallback);

  ros::spin();
}