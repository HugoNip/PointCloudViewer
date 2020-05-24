#include <iostream>
#include <chrono>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

std::string image_file = "../data/testImage.jpg";

int main(int argc, char** argv) {
    // Read image
    cv::Mat image;
    image = cv::imread(image_file);

    if (image.data == nullptr) {
        std::cerr << "File " << image_file << " doesn't existed." << std::endl;
        return 0;
    }

    std::cout << "Width: " << image.cols
              << ", Height: " << image.rows
              << ", Channels: " << image.channels() << std::endl;

    cv::imshow("image", image);
    cv::waitKey(0);

    if (image.type() != CV_8UC1 && image.type() != CV_8UC3) {
        std::cout << "The type doesn't match." << std::endl;
        return 0;
    }

    // Read pixels
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    for (size_t y = 0; y < image.rows; y++) {
        unsigned char* row_ptr = image.ptr<unsigned char>(y);
        for (size_t x = 0; x < image.cols; x++) {
            unsigned char* data_ptr = &row_ptr[x * image.channels()];
            for (int c = 0; c < image.channels(); c++) {
                unsigned char data = data_ptr[c];
            }
        }
    }

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_used = std::chrono::duration_cast<std::chrono::duration<double>> (t2 - t1);
    std::cout << "The using time is " << time_used.count() << " s." << std::endl;

    // Copy image: use clone()
    cv::Mat image_clone = image.clone();
    image_clone(cv::Rect(0, 0, 100, 100)).setTo(255);
    cv::imshow("image_clone", image_clone);
    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}
