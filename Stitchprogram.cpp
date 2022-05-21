#include <iostream>
#include <fstream>

// Include header files from OpenCV directory
// required to stitch images.
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

Stitched::Mode mode = Stitched::PANORAMA;

// This will be our array for the images that we will have
vector<Mat> images;

int main(int argc, char *argv[])
{

    for (int i = 1; i < argc; ++i)
    {
        // Read the ith argument or image
        // and push into the image array
        Mat img = imread(argv[i]);
        if (img.empty())
        {
            // Exit if image is not present
            cout << "Sorry. Unable to read image. Please try again '" << argv[i] << "'\n";
            return -1;
        }
        images.push_back(img);