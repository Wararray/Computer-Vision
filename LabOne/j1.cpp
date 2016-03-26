#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <sys/time.h>
#include <ctime>

using namespace cv;
using namespace std;


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

int main()
{

   IplImage *cvImg; // Objeto usado para armazenar a imagem
   CvSize imgSize;
   int i1 = 0, j1 = 0;
   imgSize.width = 640;
   imgSize.height = 480;  
 
   cvImg = cvCreateImage( imgSize, 8, 1 );


   for ( i1 = 0; i1 < imgSize.width; i1++ )
       for ( j1 = 0; j1 < imgSize.height; j1++ )
           ((uchar*)(cvImg->imageData + cvImg->widthStep*j1))[i1] = ( char ) ( ( i1 * j1 ) % 256 );


  uint64 r1 = getTime64();
  cout<< "r1 = " << r1 << endl;

   cvNamedWindow( "Abrindo a Imagem Gerada...", 1 );
   cvShowImage( "Abrindo a Imagem Gerada...", cvImg );
   cvWaitKey( 2 );
   cvDestroyWindow( "image" );
   cvReleaseImage( &cvImg );


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

  cout<< r2-r1 << endl;
}