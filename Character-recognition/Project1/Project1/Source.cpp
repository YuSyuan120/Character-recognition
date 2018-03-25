// PlayVideoFileCpp.sln
// main.cpp
//#include<opencv2\opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
using namespace cv;
using namespace std;


int main(void)
{
	//image source
	Mat num_img = imread("C:\\Users\\昱軒\\Desktop\\高三下\\人工智慧\\test2.jpg", CV_LOAD_IMAGE_UNCHANGED);
	if (num_img.empty()) { cout << "no num_img " << endl; }
	else {
		imshow("number_test", num_img);
	}
	Point start(num_img.rows, num_img.cols),final(0,0);
	for (int y = 0; y < num_img.rows; y++) {
		for (int x = 0; x < num_img.cols; x++) {
			if (num_img.at<Vec3b>(y, x).val[0]  > 127) { num_img.at<Vec3b>(y, x).val[0] = 255; }
			else{ num_img.at<Vec3b>(y, x).val[0] = 0; }
			if (num_img.at<Vec3b>(y, x).val[0] ==0) {
				if (start.x > x) { start.x = x; }
				if (start.y > y) { start.y = y; }
				if (final.x < x) { final.x = x; }
				if (final.y < y) { final.y = y; }
			}
		}
	}
	vector<int>linex,liney;
	bool no_black = true;
	for (int x = start.x; x < final.x; x++) {
		no_black = true;
		for (int y = start.y; y < final.y; y++) {
			if (num_img.at<Vec3b>(y, x).val[0] == 0) { no_black = false; }
		}
		if(no_black==true){ liney.push_back(x); }
	}
	for (int y = start.y; y < final.y; y++) {
		no_black = true;
		for (int x = start.x; x < final.x; x++) {
			if (num_img.at<Vec3b>(y, x).val[0] == 0) { no_black = false; }
		}
		if (no_black == true) { linex.push_back(y); }
	}
//	start.x -= 3; start.y -= 3; final.x += 3; final.y += 3;
	cout << int(start.x) << "," << int(start.y) << endl << int(final.x) << "," << int(final.y);
	for (int i = 0; i < liney.size(); i++) {
		line(num_img,Point(liney[i],start.y),Point(liney[i], final.y), Scalar(0, 0, 255), 1);
	}
	for (int i = 0; i < linex.size(); i++) {
		line(num_img, Point(start.x,linex[i]), Point(final.x, linex[i]), Scalar(0, 0, 255), 1);
	}
	rectangle(num_img, start,final, Scalar(0, 0, 255), 1);
	imshow("number_test2", num_img);
	waitKey(0);
	return 0;
}




