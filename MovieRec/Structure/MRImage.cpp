//
//  MRImage.cpp
//  MovieRec
//
//  Created by Anton Krasnokutskiy on 03.11.15.
//  Copyright (c) 2015 Anton Krasnokutskiy. All rights reserved.
//

#include "MRImage.h"

MRImage::MRImage()
{
    
}

float MRImage::getIntensity(cv::Vec3b pixel)
{
    return .0722 * pixel[0] + .7152 * pixel[1] + .2126 * pixel[2];
}

unsigned long long MRImage::getHash()
{
    int colsDiv = image.cols / 8;
    int rowsDiv = image.rows / 8;
    
    float sum[64] = {};
    int count[64] = {};
    
    for (int i = 0; i < image.cols; i++)
    {
        for (int j = 0; j < image.rows; j++)
        {
            int i1 = fmin(i / colsDiv, 7);
            int j1 = fmin(j / rowsDiv, 7);
            int index = i1 * 8 + j1;
            sum[index] += getIntensity(image.at<cv::Vec3b>(j, i));
            count[index]++;
        }
    }
    float mean = 0;
    for (int i = 0; i < 64; i++)
        mean += sum[i];
    mean /= image.cols * image.rows;
    for (int i = 0; i < 64; i++) {
        sum[i] *= normalizeMean / mean;
        sum[i] /= count[i];
    }
    unsigned long long currentHash = 0;
    for (int i = 0; i < 64; i++) {
        if (sum[i] > 127)
            currentHash |= 1 << i;
    }
    return currentHash;
}

MRImage::~MRImage()
{
    image.release();
}