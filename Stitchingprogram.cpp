
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
    if (images.size() <2)
    {
        cout << "Warning. You need at least two images to stitch\n";
        return -1;
    }

    // Define object to store the stitched image
    Mat panorama;

    // Create a Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create(mode, false);

    // Command to stitch all the images present in the image array
    Stitched::Status status = stitcher->stitch(imgs, panorama);

    if (status != Stitcher::OK)
    {
        switch (status)
        {
        case Stitcher::ERR_NEED_MOREIMGS:
           cout << "Error: Please provide more images to perform stitiching.\n;"
           break;
        case Stitcher::ERR_HOMOGRAPHY_EST_FAIL:
           cout << "Error: Homogrpahy estimation has failed. This can happen if there is a lack of overlap between images or insufficient feature matching.\n";
           break;
        case Stitcher::ERR_CAMERA_PARAMS_ADJUST_FAIL:
            cout << "Error: Camera adjustment paramaters have failed. This may occur due to poor initial camera adjustments "
        }
        default:
            cout << "Sorry. The stitched image you provided was unable to be saved."
            return -1;

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