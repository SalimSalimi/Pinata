#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <random>
using namespace cv;
using namespace std;
static int nb;


int main()
{
	VideoCapture cap(0);
	Mat img = imread("pinata.png");
	//Mat img = imread("pinata.png", IMREAD_UNCHANGED);
	resize(img, img, Size(100, 100));

	if (!cap.isOpened()) {
		cout << "erreur";
		return -1;

	}
	cap.set(CAP_PROP_FRAME_WIDTH, 1200);
	cap.set(CAP_PROP_FRAME_HEIGHT, 850);

	while (1) {
		Mat frame;
		cap >> frame;
		
		if (frame.empty())
			break;

		img.copyTo(frame(cv::Rect(120, 30, img.cols, img.rows)));

		namedWindow("frame", 1);
		

		//setMouseCallback("My Window", CallBackFunc, NULL);
		imshow("frame", frame);

		char c = (char)waitKey(1);
		if (c == 27) break;
	}
}