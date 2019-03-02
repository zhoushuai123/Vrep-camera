#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdlib>
#include<chrono>
#include<cmath>
#include<memory>
#include<vector>
#include<math.h>
#include<chrono>
#include<thread>


extern "C" {
	#include "extApi.h"
	}
#include<extApiPlatform.h>
#include<v_repConst.h>
#include<string>
//#include<Jacobian_Pseudoinverse.h>


#include <unistd.h>

#include <cstdio>
#include <ctime>

//define the opencv package
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

//define the PCL package
//#include <pcl/visualization/cloud_viewer.h>
//#include <pcl/common/common_headers.h>
//#include <pcl/ModelCoefficients.h>

//include some other headers
#include "../src/manyImshow.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

float position_object[] = {0,0,0};
float orientation_object[] = {0,0,0};
float position_camera[] = {0,0,0.7};
float orientation_camera[] = {3.14,0,3.14};



void CameraPoseSet(int clientID, std::vector<int> camera_pose_range, int camera_handle){


    float position[] = {0.0,0.0,0.0};
    float rotation[] = {0.0,0.0,0.0};

    position[0] = float(rand() % (2*camera_pose_range[0]) - camera_pose_range[0])/1000+position_camera[0];
    position[1] = float(rand() % (2*camera_pose_range[1]) - camera_pose_range[1])/1000+position_camera[1];
    position[2] = float(rand() % (2*camera_pose_range[2]) - camera_pose_range[2])/1000+position_camera[2];

    rotation[0] = float(rand() % (2*camera_pose_range[3]) - camera_pose_range[3])*3.14/180+orientation_camera[0];
    rotation[1] = float(rand() % (2*camera_pose_range[4]) - camera_pose_range[4])*3.14/180+orientation_camera[1];
    rotation[2] = float(rand() % (2*camera_pose_range[5]) - camera_pose_range[5])*3.14/180+orientation_camera[2];

    simxSetObjectPosition(clientID,  camera_handle, -1, position, simx_opmode_oneshot);
    simxSetObjectOrientation(clientID,  camera_handle, -1, rotation, simx_opmode_oneshot);
    std::cout<<"Camera position :"<<position[0]<<";"<<position[1]<<";"<<position[2]<<";"<<" Camera rotation :"<<rotation<<std::endl;
}

void StartSimRandom(int clientID, int imsave_count,  std::vector<int> noise_param,  std::vector<int> camera_pose_range, int camera_handle){

    CameraPoseSet(clientID, camera_pose_range, camera_handle);
    // std::cout<<"output of the box";
    // set the camera position
    simxInt res[2];
    simxUChar *image;
    simxFloat *depth;
    simxGetVisionSensorImage(clientID,camera_handle,res,&image,0,simx_opmode_streaming);
    //use while loop to make sure that we can get correct res
    while(1){
        if(simxGetVisionSensorImage(clientID,camera_handle,res,&image,0,simx_opmode_buffer)==0){
            std::cout<<"image size is--res[0]:"<<res[0]<<"res[1]:"<<res[1]<<std::endl;
            break;
        }
    }
    cv::Mat ocvimage(res[1],res[0], CV_8UC3, cv::Scalar(0,0,0));
    cv::Mat depth_image_gray(res[1],res[0], CV_8UC3, cv::Scalar(0,0,0));
    cv::namedWindow( "Vision Sensor Image", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Vision Depth Image", cv::WINDOW_AUTOSIZE );
    int im_count = 0;
    simxGetVisionSensorDepthBuffer(clientID,camera_handle,res,&depth,simx_opmode_streaming);
    while(1){
        if(simxGetVisionSensorDepthBuffer(clientID,camera_handle,res,&depth,simx_opmode_buffer)==0){
                for (int i=0;i<res[1];i++){
                    for (int j=0;j<res[0];j++){
                        depth_image_gray.at<cv::Vec3b>(i,j)[0] = uchar(cvRound(depth[(res[1]-i-1)*res[0]+j]*255));//image[3*((res[1]-i)*res[0]+j)+2];
                        depth_image_gray.at<cv::Vec3b>(i,j)[1] = uchar(cvRound(depth[(res[1]-i-1)*res[0]+j]*255));//image[3*((res[1]-i)*res[0]+j)+2];
                        depth_image_gray.at<cv::Vec3b>(i,j)[2] = uchar(cvRound(depth[(res[1]-i-1)*res[0]+j]*255));//image[3*((res[1]-i)*res[0]+j)+2];
                    }
                }
        }


        if(simxGetVisionSensorImage(clientID,camera_handle,res,&image,0,simx_opmode_buffer)==0){
                for (int i=0;i<res[1];i++){
                    for (int j=0;j<res[0];j++){
                        ocvimage.at<cv::Vec3b>(i,j)[2] = image[3*((res[1]-i-1)*res[0]+j)+0];//image[3*((res[1]-i)*res[0]+j)+0];
                        ocvimage.at<cv::Vec3b>(i,j)[1] = image[3*((res[1]-i-1)*res[0]+j)+1];//image[3*((res[1]-i)*res[0]+j)+1];
                        ocvimage.at<cv::Vec3b>(i,j)[0] = image[3*((res[1]-i-1)*res[0]+j)+2];//image[3*((res[1]-i)*res[0]+j)+2];
                    }
            }

                //add noise to

                cv::Mat noise = cv::Mat(depth_image_gray.size(),depth_image_gray.type());
                cv::randn(noise,float(noise_param[0]),float(noise_param[1]));
                depth_image_gray+=noise;
                // Apply the colormap:
                // Show the result:
                cv::waitKey(5);
                cv::imshow("Vision Sensor Image", ocvimage);
                cv::imshow("Vision Depth Image", depth_image_gray);
                cv::waitKey(5);
               // std::cout<<"Receving the "<<im_count<<"th image"<<std::endl;
                im_count = im_count + 1;

        }
        //processing the ocvimage to obtain the box

        //usleep(10000000);


        if(im_count > 10){
            std::stringstream image_name;
            std::stringstream folder_name_depth;
            std::stringstream folder_name_RGB;
            // std::cout<<"Stop Receving images"<<std::endl;
            if(imsave_count<10){
                image_name << "00000" << imsave_count;
            }
            else if(imsave_count>9&&imsave_count<100){
                image_name << "0000" << imsave_count;
            }
            else if(imsave_count>99&&imsave_count<1000){
                image_name << "000" << imsave_count;
            }
            else if(imsave_count>999&&imsave_count<10000){
                image_name << "00" << imsave_count;
            }
            else if(imsave_count>9999&&imsave_count<100000){
                image_name << "0" << imsave_count;
            }
            else{
                image_name <<  imsave_count;
            }
            //uncomment this part if you want to save the image and depth image into disk
            /*
            folder_name_depth << "sim_data/Depth_image/" <<"image_"<<image_name.str()<<".png";
            folder_name_RGB << "sim_data/RGB_image/"  <<"image_"<<image_name.str()<<".png";
            std::cout<< "write image to " << folder_name_depth.str() << std::endl;
            cv::imwrite(folder_name_depth.str(), depth_image_gray );
            cv::imwrite(folder_name_RGB.str(),  ocvimage);
            */
            break;
        }
    }
    ocvimage.release();
    depth_image_gray.release();

}

int main(int argc, char* argv[])
{

    //using the boost library to read the data configur
    std::vector<std::string> name_of_object;
    std::vector<int> noise_param;
    std::vector<int> camera_pose_range;



    using boost::property_tree::ptree;
    ptree pt;

    int im_num;
    int box_max_num;
    std::vector<int> objects_control_rate;

    read_ini("config.ini", pt);

    for (auto& section : pt)
    {
        if(section.first=="NOISE"){
            for (auto& key : section.second){
                std::cout << key.first << "=" << key.second.get_value<std::string>() << "\n";
                noise_param.push_back(std::stoi(key.second.get_value<std::string>()));
            }
        }
        if(section.first=="NUM_OF_IMAGE"){
            for (auto& key : section.second){
                std::cout << key.first << "=" << key.second.get_value<std::string>() << "\n";
                im_num = std::stoi(key.second.get_value<std::string>());
            }
        }
        if(section.first=="CAMERA_POSE_RANGE"){
            for (auto& key : section.second){
                std::cout << key.first << "=" << key.second.get_value<std::string>() << "\n";
                camera_pose_range.push_back(std::stoi(key.second.get_value<std::string>()));
            }
        }

    }

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

        //Try to connect vrep in remote control mode
	int portNb = 19999;
        double time_waiting;
        int camera_handle;
        int clientID = simxStart((simxChar*)"127.0.0.1",portNb,true,true,2000,5);
        //calculate time until time exceeds or clientID >= 0
        while(1){
            std::chrono::steady_clock::time_point start_waiting_software = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed = start_waiting_software - start;
            time_waiting = (elapsed).count()*1000;
            if(clientID >= 0){
                break;
            }
            else if(time_waiting > 10000.0){
                std::cout<<"Time out! Waiting time exceeds 10 seconds!"<<std::endl;
                break;
            }
        }
        //if we find the clientID exits, we then start to connect
	if(clientID >= 0)
        {
            simxStartSimulation(clientID,simx_opmode_blocking);
            std::cout<<"Connected :) waiting time is "<< time_waiting<< "ms" << std::endl;
            //we obatin the camera pose here, afterwards, we will update the camera with ethe camera psoe range with the orignial camera pose
            simxGetObjectHandle(clientID,"VisionH",&camera_handle,simx_opmode_blocking);
            std::cout<<"Camera position :"<<position_camera[0]<<";"<<position_camera[1]<<";"<<position_camera[2]<<";"<<" Camera rotation :"<<std::endl;


            for(int i=0; i < im_num;i++){
                std::cout<<"Generating "<<i<<"th image"<<std::endl;
                StartSimRandom(clientID, i, noise_param , camera_pose_range, camera_handle);
            }
            simxFinish(clientID);
	}
        else{
            std::cout<<"Connection fails :(";
        }
	//std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end- start;
        std::cout<<"Elapsed time: " <<(elapsed).count()*1000<<"ms"<<std::endl;
return(0);
}

