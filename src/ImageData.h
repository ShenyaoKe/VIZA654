//
//  ImageData.h
//
//  Created by Shenyao Ke on 10/11/14.
//  Copyright (c) 2014 Shenyao Ke. All rights reserved.
//
#pragma once
#ifndef __ImageData__
#define __ImageData__

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
//#include <math.h>

#include "MemoryControl.h"
//#include "Math/CGVector.h"
#include "ColorData.h"

//read image files
#include <FreeImage.h>
using namespace std;

const int default_resX = 640;
const int default_resY = 480;


class ImageData {
protected:
	unsigned int width, height, bpp;
	ColorRGBA **pixels;
public:
	ImageData();
	//ImageData(ppmImage &ppmData);
	ImageData(int wd = default_resX, int ht = default_resY);
	ImageData(int wd, int ht, double* &pixMap);//pixMap stores rgb data
	ImageData(int wd, int ht, unsigned char* &pixMap);//pixMap stores rgb data
	ImageData(const string &filename);
	ImageData(const ImageData& src);
	virtual~ImageData();
    
	const int getWidth() const { return width; }
	const int getHeight() const { return height; }
	const int getBPP() const { return bpp; }
	const ColorRGBA& getRGBA(int x, int y) const;
	const ColorRGBA& getRGBA(int idx) const;
	void setRGBA(int x, int y, const ColorRGBA& color);
	void getPixels(unsigned char* &pixMap) const;
	int** genHist() const;//Generate histogram
	double** getLuma() const;// Generate Luma
	
	void printRGBA(int x, int y) const;
	void resize(int x, int y);
	//const ColorRGBA& bilinearPixel(double x, double y) const;
	//const ColorRGBA& bicubicPixel(double x, double y) const;
	bool writeFile(const string &filename) const;
	//ColorRGB bicubicPixel(double x, double y);
	//void convert2PPM(ppmImage &ppmData);

	//friend const ImageData& downsampling(const ImageData& src);
};
#endif /* defined(__ImageData__) */
