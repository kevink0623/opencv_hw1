#include "ImageFilter.h"


cv::Mat GaussianFilter::Filter(const cv::Mat& img)
{
	int radius = (int)ceil(2 * spatialSigma);

	cv::Mat fltImg = cv::Mat(img.size(), img.type());

	for (int y = 0; y < img.rows; ++y) {
		for (int x = 0; x < img.cols; ++x) {
			cv::Vec3f sum = cv::Vec3f(0.0f, 0.0f, 0.0f);
			float weightSum = 0.0;

			for (int ky = -radius; ky <= radius; ++ky) {
				for (int kx = -radius; kx <= radius; ++kx) {
					int nx = x + kx;
					int ny = y + ky;

					if (nx >= 0 && nx < img.cols && ny >= 0 && ny < img.rows) {
						float weight = GaussianKernel(kx, ky, spatialSigma);
						sum += weight * img.at<cv::Vec3f>(ny, nx);
						weightSum += weight;
					}
				}
			}

			fltImg.at<cv::Vec3f>(y, x) = sum / weightSum;
			uchar b = std::min(std::max(fltImg.at<cv::Vec3f>(y, x)[0], 0.0f), 255.0f);
			uchar g = std::min(std::max(fltImg.at<cv::Vec3f>(y, x)[1], 0.0f), 255.0f);
			uchar r = std::min(std::max(fltImg.at<cv::Vec3f>(y, x)[2], 0.0f), 255.0f);
			fltImg.at<cv::Vec3b>(y, x) = cv::Vec3b(b, g, r);
		}
	}

	/// Add your implementation for Gaussian filtering here.
	// -----------------------------------------------------------------------.
	// These lines use OpenCV's built-in function.
	// Please comment or remove them when you start to implement.
	/*int kernelSize = 2 * radius + 1;
	cv::GaussianBlur(img, fltImg, cv::Size(kernelSize, kernelSize), spatialSigma);*/


	return fltImg;
}


cv::Mat BilateralFilter::Filter(const cv::Mat& img)
{
	int radius = (int)ceil(2 * spatialSigma);

	cv::Mat fltImg = cv::Mat(img.size(), img.type());

	for (int y = 0; y < img.rows; ++y) {
		for (int x = 0; x < img.cols; ++x) {
			cv::Vec3f sum = cv::Vec3f(0.0f, 0.0f, 0.0f);
			float weightSum = 0.0;

			for (int ky = -radius; ky <= radius; ++ky) {
				for (int kx = -radius; kx <= radius; ++kx) {
					int nx = x + kx;
					int ny = y + ky;

					if (nx >= 0 && nx < img.cols && ny >= 0 && ny < img.rows) {
						float spatial_weight = GaussianKernel(kx, ky, spatialSigma);
						float intensity_weight = IntensityKernel(img.at<cv::Vec3b>(y, x), img.at<cv::Vec3b>(ny, nx), rangeSigma);
						float weight = spatial_weight * intensity_weight;

						sum += weight * img.at<cv::Vec3f>(ny, nx);
						weightSum += weight;
					}
				}
			}

			fltImg.at<cv::Vec3f>(y, x) = sum / weightSum;
			uchar b = std::min(std::max(fltImg.at<cv::Vec3f>(y, x)[0], 0.0f), 255.0f);
			uchar g = std::min(std::max(fltImg.at<cv::Vec3f>(y, x)[1], 0.0f), 255.0f);
			uchar r = std::min(std::max(fltImg.at<cv::Vec3f>(y, x)[2], 0.0f), 255.0f);
			fltImg.at<cv::Vec3b>(y, x) = cv::Vec3b(b, g, r);
		}
	}

	/// Add your implementation for bilateral filtering here.
	// -----------------------------------------------------------------------.
	// This line copies the original image to the destination.
	// Please comment or remove it when you start to implement.
	//fltImg = img.clone();

	return fltImg;
}

float ImageFilter::GaussianKernel(int x, int y, float sigma)
{
	float coeff = 1.0 / (2.0 * CV_PI * sigma * sigma);
	float exponent = -(x * x + y * y) / (2.0 * sigma * sigma);
	return coeff * exp(exponent);
}

float ImageFilter::IntensityKernel(const cv::Vec3b& p1, const cv::Vec3b& p2, float sigma)
{
	float diff = sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) + pow(p1[2] - p2[2], 2));
	return exp(-(diff * diff) / (2 * sigma * sigma));
}
