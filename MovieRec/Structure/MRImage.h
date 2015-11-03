//
//  MRImage.h
//  MovieRec
//
//  Created by Anton Krasnokutskiy on 03.11.15.
//  Copyright (c) 2015 Anton Krasnokutskiy. All rights reserved.
//

#ifndef __MovieRec__MRImage__
#define __MovieRec__MRImage__

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cvaux.hpp>
#include <opencv2/core/core.hpp>

class MRImage
{
public:
    const float normalizeMean = 127;
    
    cv::Mat image;
    
private:
    float getIntensity(cv::Vec3b);
    
public:
    MRImage();
    
    MRImage(cv::Mat image) : image(image) { };
    
    // Splits image to 8x8 rectangles and calculates the mean value of
    // intensity. In case it more than 127 the corresponding bit - 1, otherwise
    // - 0.
    unsigned long long getHash();
    
    ~MRImage();
};

#endif /* defined(__MovieRec__MRImage__) */
