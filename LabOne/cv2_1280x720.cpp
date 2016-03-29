#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <sys/time.h>
#include <ctime>

using namespace cv;
using namespace std;

int main()
{
  //Setting Sizes
  int height = 480;  
  int width  = 640;
  
  //Creating Image
  Mat Img( height, width, CV_8U);

  //Moving into Image and Changing values
  for(int i = 0; i < Img.rows; ++i)
    for(int j = 0; j < Img.cols; ++j)
      Img.at<uchar>(i,j) = (char) ( ( i * j ) % 256) ;

  uint64 r2 = getTime64();
  cout<< "r2 = " << r2 << endl;
  
  //Ending and Output
  namedWindow("Display Image", WINDOW_AUTOSIZE );
  imshow("Display Image", Img);
  waitKey(2);
}

uint64 getTime64(){
 struct timeval tv;
 gettimeofday(&tv, NULL);
 uint64 ret = tv.tv_usec;

 /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
 ret /= 1000;
 /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
 ret += (tv.tv_sec * 1000);

 return ret;
}