#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <stdio.h>
#include <sys/time.h>
#include <ctime>

using namespace cv;
using namespace std;

uint64 getTime64();

int main()
{

  IplImage *cvImg; // Objeto usado para armazenar a imagem
  CvSize imgSize;
  int i1 = 0, j1 = 0;
  imgSize.width = 1280;
  imgSize.height = 720;  
 
  cvImg = cvCreateImage( imgSize, 8, 1 );

  for ( i1 = 0; i1 < imgSize.width; i1++ )
      for ( j1 = 0; j1 < imgSize.height; j1++ )
          ((uchar*)(cvImg->imageData + cvImg->widthStep*j1))[i1] = ( char ) ( ( i1 * j1 ) % 256 );

  uint64 r1 = getTime64();
  cout<< "Erre1 = " << r1 << endl;

  cvNamedWindow( "Abrindo a Imagem Gerada...", 1 );
  cvShowImage( "Abrindo a Imagem Gerada...", cvImg );
  cvWaitKey(4000);
  cvDestroyWindow( "image" );
  cvReleaseImage( &cvImg );

  return 0;
}  

uint64 getTime64()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  uint64 ret = tv.tv_usec;

  /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
  ret /= 1000;
  /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
  ret += (tv.tv_sec * 1000);

  return ret;
}

