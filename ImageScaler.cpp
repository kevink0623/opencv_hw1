#include "ImageScaler.h"

#include <iostream>
using namespace std;


cv::Mat ImageScaler::Resize(const cv::Mat& origImg, const int newWidth, const int newHeight)
{
    cv::Size newSize(newWidth, newHeight);
    cv::Mat editImg = cv::Mat(newSize, origImg.type());

    float x_ratio = static_cast<float>(origImg.cols - 1) / (newWidth);
    float y_ratio = static_cast<float>(origImg.rows - 1) / (newHeight);

    for (int y = 0; y < newHeight; ++y)
    {
        for (int x = 0; x < newWidth; ++x)
        {
            float orig_x = x * x_ratio;
            float orig_y = y * y_ratio;

            int x1 = static_cast<int>(orig_x);
            int y1 = static_cast<int>(orig_y);
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            if (x2 >= origImg.cols) x2 = origImg.cols - 1;
            if (y2 >= origImg.rows) y2 = origImg.rows - 1;

            float x_diff = orig_x - x1;
            float y_diff = orig_y - y1;

            // Bilinear interpolation
            cv::Vec3b tl = origImg.at<cv::Vec3b>(y1, x1);
            cv::Vec3b tr = origImg.at<cv::Vec3b>(y1, x2);
            cv::Vec3b bl = origImg.at<cv::Vec3b>(y2, x1);
            cv::Vec3b br = origImg.at<cv::Vec3b>(y2, x2);

            cv::Vec3b interpolated_pixel =
                tl * (1 - x_diff) * (1 - y_diff) +
                tr * x_diff * (1 - y_diff) +
                bl * (1 - x_diff) * y_diff +
                br * x_diff * y_diff;

            editImg.at<cv::Vec3b>(y, x) = interpolated_pixel;
        }
    }

    // Add your implementation for image scaling here.
    // -----------------------------------------------------------------------.
    // This line uses OpenCV's built-in function.
    // Please comment or remove it when you start to implement.
    //cv::resize(origImg, editImg, newSize);


    return editImg;
}

