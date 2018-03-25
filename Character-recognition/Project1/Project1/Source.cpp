// PlayVideoFileCpp.sln
// main.cpp
//#include<opencv2\opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>           // it may be necessary to change or remove this line if not using Windows
using namespace cv;
using namespace std;


int main(void)
{
	
	Mat pic = imread("A.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	Mat pic2 = imread("Text with noise.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	Mat ero1, ero2;
	Mat dil1,dil2;
	Mat open1, open2;
	Mat close1, close2;
	Mat Struct1 = getStructuringElement(MORPH_RECT, Size(3, 3));
	/*
	erode(pic, ero1, Struct1);
	erode(pic2, ero2, Struct1);
	dilate(pic, dil1, Struct1);
	dilate(pic2, dil2, Struct1);
	imshow("origin_A.bmp", pic);
	imshow("dilate_A.bmp", dil1);
	imshow("erode_A.bmp", ero1);
	imshow("origin_Text with noise.bmp", pic2);
	imshow("dilate_Text with noise.bmp", dil2);
	imshow("erode_Text with noise.bmp", ero2);
	//*/

	/*
	morphologyEx(pic, open1, MORPH_OPEN, Struct1);
	morphologyEx(pic, close1, MORPH_CLOSE, Struct1);
	morphologyEx(pic2, open2, MORPH_OPEN, Struct1);
	morphologyEx(pic2, close2, MORPH_CLOSE, Struct1);
	imshow("open_A.bmp", open1);
	imshow("close1_A.bmp", close1);
	imshow("open_Text with noise.bmp", open2);
	imshow("close_Text with noise.bmp", close2);
	//*/

	///*
	VideoCapture capVideo;

	Mat imgFrame, imgFrame2, imgFrame3,origin,a, dilate_img;

	capVideo.open("testv.avi");
	capVideo.read(imgFrame);
	capVideo.read(imgFrame2);
	capVideo.read(imgFrame3);
	capVideo.read(origin);
	capVideo.read(a);
	//imshow("背景圖", a);
	char chCheckForEscKey = 0;
	int i=0;
	int i1=0;

	while (capVideo.isOpened() && i!=26)
	{
		for (int x = 0; x < imgFrame.rows; x++) {
			for (int y = 0; y < imgFrame.cols; y++) {
				int g1 = (abs(imgFrame.at<Vec3b>(x, y)[0] - a.at<Vec3b>(x, y)[0]) + abs(imgFrame.at<Vec3b>(x, y)[1] - a.at<Vec3b>(x, y)[1]) + abs(imgFrame.at<Vec3b>(x, y)[2] - a.at<Vec3b>(x, y)[2])) / 3 > 40 ? 1 : 0;
				imgFrame.at<Vec3b>(x, y)[0] = g1 == 0 ? 0 : imgFrame.at<Vec3b>(x, y)[0];
				imgFrame.at<Vec3b>(x, y)[1] = g1 == 0 ? 0 : imgFrame.at<Vec3b>(x, y)[1];
				imgFrame.at<Vec3b>(x, y)[2] = g1 == 0 ? 0 : imgFrame.at<Vec3b>(x, y)[2];
				int g = imgFrame.at<Vec3b>(x, y)[0] + imgFrame.at<Vec3b>(x, y)[1] + imgFrame.at<Vec3b>(x, y)[2] == 0 ? 0: 255;
				imgFrame2.at<Vec3b>(x, y)[0] =g;
				imgFrame2.at<Vec3b>(x, y)[1] =g;
				imgFrame2.at<Vec3b>(x, y)[2] =g;
				imgFrame3.at<Vec3b>(x, y)[0] = abs(i1 - g);
				imgFrame3.at<Vec3b>(x, y)[1] = abs(i1 - g);
				imgFrame3.at<Vec3b>(x, y)[2] = abs(i1 - g);
				i1 = g;
				
			}
		}
		imshow("原圖(灰階)", origin);
		imshow("背景相減", imgFrame);
		imshow("背景相減2", imgFrame2);
		imshow("相鄰相減", imgFrame3);

		if ((capVideo.get(CV_CAP_PROP_POS_FRAMES) + 1) < capVideo.get(CV_CAP_PROP_FRAME_COUNT)) {       // if there is at least one more frame
			capVideo.read(imgFrame);    
			capVideo.read(origin); // read it
		}
		else {                                                  // else
			std::cout << "end of video\n";                      // show end of video message
			break;                                              // and jump out of while loop
		}
		waitKey(1);
	}
	//*/
	waitKey(0);
	return(0);
}




