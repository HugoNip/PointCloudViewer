# Stereo Vision Display
## Introduction
The RGBD vision and stereo vision display in the SLAM.  
Besides, this project also contains files showing several simple operations of OpenCV package and image undistorting.

## Requirements
### OpenCV
#### Required Packages
OpenCV
OpenCV Contrib

### Eigen Package (Version >= 3.0.0)
#### Source
http://eigen.tuxfamily.org/index.php?title=Main_Page

#### Compile and Install
```
cd [path-to-Eigen]
mkdir build
cd build
cmake ..
make 
sudo make install 
```

#### Search Installing Location
```
sudo updatedb
locate eigen3
```

default location "/usr/include/eigen3"


### OpenGL Package (use pangolin)
#### Download
https://github.com/HugoNip/Pangolin

#### Install the dependency for pangolin (mainly the OpenGL)
```
sudo apt-get install libglew-dev
```

### Sophus Package
#### Download
https://github.com/HugoNip/Sophus

#### Compile and Install
```
cd [path-to-pangolin]
mkdir build
cd build
cmake ..
make 
sudo make install 
```

## Compile this Project
```
mkdir build
cd build
cmake ..
make 
```

## Run
```
./imageBasic
./jointMap
./stereoVision
./undistortImage
```
## Reference
[Source](https://github.com/HugoNip/slambook2/tree/master/ch4)
