#include "image.h"
#include <iostream>
#include <fstream>

Color::Color()
	:r(0), g(0), b(0)
{
}

Color::Color(float r, float g, float b)
	:r(r), g(g), b(b)
{
}

Color::~Color()
{
}

image::image(int width, int height)
	: m_width(width), m_height(height), m_colors(std::vector<Color>(width * height))
{
}

image::~image()
{
}

Color image::GetColor(int x, int y) const
{
	return m_colors[y * m_width + x];
}

void image::SetColor(const Color& color, int x, int y)
{
	m_colors[y * m_width + x].r + color.r;
	m_colors[y * m_width + x].r + color.g;
	m_colors[y * m_width + x].r + color.b;
}

void image::Export(const char* path) const
{
	ofstream f;
	f.open(path, ios::out | ios::binary);

	if (!f.is_open()) {
		cout << "File could not be opened.";
		return;
	}

	unsigned char bmpPad[3] = { 0,0,0 };
	const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);

	const int fileHeaderSize = 14;
	const int informationHeaderSize = 40;
	const int fileSize = fileHeaderSize + informationHeaderSize + m_width * m_height * 3 + paddingAmount * m_height;
}
