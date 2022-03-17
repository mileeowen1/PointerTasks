/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: January 30, 2020
Programming Assignment: PA2
Description: Create a program that investigates how much "work" is done by different sorting routines, depending on the input size and order of data. Work done is recorded in output CSV files with various plots for result visuals.
Notes: Main function cpp file
*/
#include "PA3.h"
int main() {
	// this should be the ONLY call to srand() in PA3
	srand(time(0));
	
	// run task 1
	runTask1();
	// run task 2
	runTask2();
	// run task 3
	runTask3();
	return 0;
}
/*
git clone <url>
cd pa3-username
mkdir build
cd build
cmake ..
make
./runPA3
./test/runTests */
