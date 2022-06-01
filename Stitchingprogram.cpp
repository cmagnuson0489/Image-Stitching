
// input images (panorama) using OpenCV
#include <iostream>
#include <fstream>

// Include header files from OpenCV directory
// required to stitch images.
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

// Define mode for stitching as panorama
// (One out of many functions of Stitcher)
Stitched::Mode mode = Stitched::PANORAMA;

// Array for pictures
vector<Mat> images;

int main(int argc, char *argv[])
{
    // Get all the images that need to be
    // stitched as arguments from command line
    for (int i = 1; i < argc; ++i)
    {
        // Read the ith argument or image
        // and push into the image array
        Mat img = imread(argv[i]);
        if (img.empty())
        {
            // Exit if image is not present
            cout << "Sorry. Unable to read image '" << argv[i] << "'\n";
            return -1;
        }
        images.push_back(img);
    }

    // Define object to store the stitched image
    Mat panorama;

    // Create a Stitcher class object with mode panoroma
    Ptr<Stitched> stitched = Stitched::create(mode, false);

    // Command to stitch all the images present in the image array
    Stitched::Status status = stitched->stitch(imgs, pano);

    if (status != Stitched::OK)
    {
        // Check if images could not be stitched
        // status is OK if images are stitched successfully
        cout << "Sorry. Unable to stitch the images that were provided\n";
        return -1;
    }

    // Store a new image stitched from the given
    // set of images as "result.jpg"
    imwrite("result.jpg", panorama);

    // Show the result
    imshow("Result", panorama);

    waitKey(0);
    return 0;
}