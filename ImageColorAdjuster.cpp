#include "ImageColorAdjuster.h"
#include<iostream>
using namespace std;


cv::Mat ImageColorAdjuster::RemapColorCurve1(const cv::Mat& image)
{
	cv::Mat newImage = cv::Mat(image.size(), image.type());

	int width = image.cols;
	int height = image.rows;
	for (int h = 0; h < height; ++h) {
		for (int w = 0; w < width; ++w) {
			cv::Vec3b pcolor = image.at<cv::Vec3b>(h, w);

			float Y = 0.299 * pcolor[2] + 0.587 * pcolor[1] + 0.114 * pcolor[0];
			float Cb = 0.568 * (pcolor[0] - Y) + 128;
			float Cr = 0.713 * (pcolor[2] - Y) + 128;

			float newY = pow(Y, 0.85);

			/*uchar newR = max((uchar)0, min((uchar)255, (uchar)(newY + 1.371 * (Cr - 128))));
			uchar newG = max((uchar)0, min((uchar)255, (uchar)(newY - 0.698 * (Cr - 128) - 0.336 * (Cb - 128))));
			uchar newB = max((uchar)0, min((uchar)255, (uchar)(newY + 1.732 * (Cb - 128))));*/

			uchar newR = newY + 1.371 * (Cr - 128);
			uchar newG = newY - 0.698 * (Cr - 128) - 0.336 * (Cb - 128);
			uchar newB = newY + 1.732 * (Cb - 128);

			newImage.at<cv::Vec3b>(h, w) = cv::Vec3b(newB, newG, newR);


			// Add you implementation here.
			// ---------------------------------------------------------------.
			// Get pixel color.

			// RGB to YCbCr (please use the formula on slides).

			// Scale the luminance channel.
			// Y' = Y^{0.85}.

			// YCbCr to RGB.

			// Write the new color to newImage.

		}
	}
	return newImage;
}


cv::Mat ImageColorAdjuster::RemapColorCurve2(const cv::Mat& image)
{
	cv::Mat newImage = cv::Mat(image.size(), image.type());

	int width = image.cols;
	int height = image.rows;
	for (int h = 0; h < height; ++h) {
		for (int w = 0; w < width; ++w) {
			cv::Vec3b pcolor = image.at<cv::Vec3b>(h, w);

			float Y = 0.299 * pcolor[2] + 0.587 * pcolor[1] + 0.114 * pcolor[0];
			float Cb = 0.568 * (pcolor[0] - Y) + 128;
			float Cr = 0.713 * (pcolor[2] - Y) + 128;

			float newY = pow(Y, 1.50);

			uchar newR = max((uchar)0, min((uchar)255, (uchar)(newY + 1.371 * (Cr - 128))));
			uchar newG = max((uchar)0, min((uchar)255, (uchar)(newY - 0.698 * (Cr - 128) - 0.336 * (Cb - 128))));
			uchar newB = max((uchar)0, min((uchar)255, (uchar)(newY + 1.732 * (Cb - 128))));

			newImage.at<cv::Vec3b>(h, w) = cv::Vec3b(newB, newG, newR);



			// Add you implementation here.
			// ---------------------------------------------------------------.
			// Get pixel color.

			// RGB to YCbCr (please use the formula on slides).

			// Scale the luminance channel.
			// Y' = Y^{1.50}.

			// YCbCr to RGB.

			// Write the new color to newImage.

		}
	}
	return newImage;
}