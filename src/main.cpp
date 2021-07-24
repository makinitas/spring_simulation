#include <iostream>
#include <iomanip>
#include "../include/pbPlots.hpp"
#include "../include/supportLib.hpp"

using namespace std;

int main ()
{
	// Input
	int n;
	cout << "enter duration of experiment\nduration: ";
	cin >> n;

	// Variable Declaration
	double m = 1.0;
	double k = 20.0;
	double h = 0.001;

	double x[n];
	x[0] = 1.0;
	float v[n];
	v[0] = 0.0;
	double a[n];
	a[0] = -20.0;
	double t[n];
	t[0] = 0.0;

	// Algorithm
	for (int i = 1; i < n; i++)
	{
		t[i] = t[i - 1]+h;
		//x[i] = x[i - 1] + (v[i - 1] * h);
		x[i] = (x[i - 1] * ((k * (h * h)) / (4 * m))) + ((h * v[i - 1]) / (1 + ((k * (h * h)) / (4 * m))));
		//v[i] = v[i - 1] + (a[i - 1] * h);
		v[i] = ((-(k * h / m) / (1 + ((k * (h * h)) / (4 * m)))) * x[i - 1]) + ((1 + ((k * (h * h)) / (4 * m))) / (1 - ((k * (h * h)) / (4 * m))) * v[i - 1]);
		a[i] = -k * x[i];
	}

	// Output
	vector<double> plotX;
	vector<double> plotY;

	for (int i = 0; i < n; i++)
	{
		plotX.push_back(t[i]);
		plotY.push_back(x[i]);
	}

	RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
	DrawScatterPlot(imageRef, 600, 400, &plotX, &plotY);
	vector<double> *pngData  = ConvertToPNG(imageRef->image);
	WriteToFile(pngData, "plot.png");
	DeleteImage(imageRef->image);
	
	return 0;
}
