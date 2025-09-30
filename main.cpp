#include <iostream>
#include "image.h"

using namespace std;

int main() {

	const int width = 640;
	const int height = 480;

	image Image(width,height);

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {
			Image.SetColor(Color((float)x / (float)width, 1.0f -((float)x / (float)width), (float)y /(float)height), x,y);
		}
	}
	//Currently doesn't work, only displays black
	Image.Export("image.bmp");
}
