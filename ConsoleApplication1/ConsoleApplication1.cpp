// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <math.h> //to use sqrt and pow
using namespace std;

int main()
{
	float ulstrength, sigmaX, sigmaY, sigmaZ, planeXY, planeYZ, planeZX, eff_str, safty;
	cout << "Enter the ultomate strength of the material:" << endl;
	cin >> ulstrength;
	cout << "Enter the stress in X direction:" << endl;
	cin >> sigmaX;
	cout << "Enter the stress in Y direction:" << endl;
	cin >> sigmaY;
	cout << "Enter the stress in X direction:" << endl;
	cin >> sigmaZ;
	cout << "Enter stress in XY plane:" << endl;
	cin >> planeXY;
	cout << "Enter stress in YZ plane:" << endl;
	cin >> planeYZ;
	cout << "Enter stress in ZX plane:" << endl;
	cin >> planeZX;
	eff_str = 0.70710678118655*sqrt(pow((sigmaX - sigmaY), 2) + pow((sigmaY - sigmaZ), 2) + pow((sigmaZ - sigmaX), 2) + 6 * (pow(planeXY, 2) + pow(planeYZ, 2) + pow(planeZX, 2)));
	cout << "Von Mises Theory(Distortion Energy Theory) says that the effective stress is:" << eff_str << endl;
	safty = ulstrength / eff_str;
	if (safty > 1) {
		cout << "The factor of safty is:" << safty << endl << "Your design is pefect";
	}
	
	if (safty < 1) {
		cout << "The factor of safty is:" << safty << endl << "You are in the failure criteria so you should chosse another material with higher ultimate strength or remodel your Design";
	}
	return 0;
}

