// Example showing how to read and write images
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <cstring>
#include "Structure/MRImage.h"
#include <vector>

using namespace std;
using namespace cv;

const char* contentPath = "/Users/antonk/Resources/";


const char* getAbsolutePath(const char* relativePath)
{
    return ((string)contentPath + (string)relativePath).c_str();
}

void logHash(unsigned long long hash)
{
    for (int i = 0; i < 64; i++) {
        cout << ((hash & (1 << i)) ? 1 : 0);
    }
    cout << endl;
}

vector<string> pathes = {"my_image.jpg", "my_image_contrast.jpg", "my_image2.jpg", "my_image3.jpg", "my_image4.jpg"};

int main(int argc, char** argv)
{
    for (int i = 0; i < (int) pathes.size(); i++)
    {
        Mat image;
        image = imread(getAbsolutePath(pathes[i].c_str()), CV_LOAD_IMAGE_COLOR);
        
        if(image.empty())
        {
            cout <<  "Could not open or find the image " << pathes[i] << std::endl ;
            continue;
        }
        MRImage mrImg(image);
        cout << pathes[i] << ": ";
        logHash(mrImg.getHash());
    }
    return 0;
}