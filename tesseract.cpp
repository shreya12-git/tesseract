#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>

int main() {
    // Initialize Tesseract
    tesseract::TessBaseAPI api;
    if (api.Init(NULL, "eng")) { // "eng" indicates the English language model
        std::cerr << "Could not initialize Tesseract." << std::endl;
        return 1;
    }

    // Open an image
    Pix* image = pixRead("your_image.png"); // Replace "your_image.png" with the path to your image
    api.SetImage(image);

    // Perform OCR
    char* outText = api.GetUTF8Text();
    if (outText) {
        std::cout << "OCR Result:" << std::endl;
        std::cout << outText << std::endl;

        // Additional processing can be done here with the recognized text

        // Clean up
        delete[] outText;
        pixDestroy(&image);
    } else {
        std::cerr << "OCR failed." << std::endl;
    }

    return 0;
}
