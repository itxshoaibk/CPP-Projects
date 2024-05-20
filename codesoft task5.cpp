#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat image, processedImage;

void showMenu() {
    cout << "\nImage Processing Tool\n";
    cout << "1. Load Image\n";
    cout << "2. Display Image\n";
    cout << "3. Apply Grayscale Filter\n";
    cout << "4. Apply Blur Filter\n";
    cout << "5. Apply Sharpen Filter\n";
    cout << "6. Adjust Brightness\n";
    cout << "7. Adjust Contrast\n";
    cout << "8. Crop Image\n";
    cout << "9. Resize Image\n";
    cout << "10. Save Image\n";
    cout << "11. Exit\n";
    cout << "Enter your choice: ";
}

void loadImage() {
    string path;
    cout << "Enter image path: ";
    cin >> path;
    image = imread(path);
    if (image.empty()) {
        cout << "Could not open or find the image.\n";
    } else {
        processedImage = image.clone();
        cout << "Image loaded successfully.\n";
    }
}

void displayImage(const Mat& img) {
    if (img.empty()) {
        cout << "No image to display.\n";
    } else {
        imshow("Display Image", img);
        waitKey(0); // Wait for a keystroke in the window
        destroyWindow("Display Image");
    }
}

void applyGrayscale() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    cvtColor(processedImage, processedImage, COLOR_BGR2GRAY);
    cout << "Applied grayscale filter.\n";
}

void applyBlur() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    blur(processedImage, processedImage, Size(5, 5));
    cout << "Applied blur filter.\n";
}

void applySharpen() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    Mat kernel = (Mat_<float>(3, 3) <<
                  0, -1, 0,
                  -1, 5, -1,
                  0, -1, 0);
    filter2D(processedImage, processedImage, -1, kernel);
    cout << "Applied sharpen filter.\n";
}

void adjustBrightness() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    double alpha;
    cout << "Enter brightness factor (positive for brighter, negative for darker): ";
    cin >> alpha;
    processedImage.convertTo(processedImage, -1, 1, alpha);
    cout << "Adjusted brightness.\n";
}

void adjustContrast() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    double alpha;
    cout << "Enter contrast factor (greater than 1 for higher contrast, between 0 and 1 for lower contrast): ";
    cin >> alpha;
    processedImage.convertTo(processedImage, -1, alpha, 0);
    cout << "Adjusted contrast.\n";
}

void cropImage() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    int x, y, width, height;
    cout << "Enter top-left x coordinate: ";
    cin >> x;
    cout << "Enter top-left y coordinate: ";
    cin >> y;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    Rect roi(x, y, width, height);
    processedImage = processedImage(roi);
    cout << "Image cropped.\n";
}

void resizeImage() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    int width, height;
    cout << "Enter new width: ";
    cin >> width;
    cout << "Enter new height: ";
    cin >> height;
    resize(processedImage, processedImage, Size(width, height));
    cout << "Image resized.\n";
}

void saveImage() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    string path;
    cout << "Enter path to save image: ";
    cin >> path;
    imwrite(path, processedImage);
    cout << "Image saved.\n";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                loadImage();
                break;
            case 2:
                displayImage(processedImage);
                break;
            case 3:
                applyGrayscale();
                break;
            case 4:
                applyBlur();
                break;
            case 5:
                applySharpen();
                break;
            case 6:
                adjustBrightness();
                break;
            case 7:
                adjustContrast();
                break;
            case 8:
                cropImage();
                break;
            case 9:
                resizeImage();
                break;
            case 10:
                saveImage();
                break;
            case 11:
                cout << "Exiting Image Processing Tool.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
