// Package Phantoms Drone Service - Version 1

//include our libraries
#include <iostream>
#include "main.h"

//main function
int main()
{
	// Displays title and description
	DisplayIntro();

	// Seeds a random number generator
	// This resets the seed so the random number sequence is always different
	/* unsigned int - was to fix an unknown issue. */
	srand((unsigned int)time(NULL));

	// Variables for creating a virtual grid of squares with a high and low number.
	// Grid can be interchangeable to test with.
	int scanGridHighNum = 36;
	int scanGridLowNum = 1;

	// Int variable to hold the random drop off location on our virtual grid.
	// The Phantom DOL will not know the location off the start, it will have to look for it.
	// NOTE: Grid is 6x6 which is 36 squares
	// Formula for random number between 1 and 36
	int dropOffPoint = rand() % scanGridHighNum + scanGridLowNum;

	// Variable that stores the number of scans the Phantom DOL makes
	int phantomDOLScans = 0;

	// Created and set a bool variable to keep the loop running while locating the drop of point.
	bool dropOffLocated = false;
	//start of main simulation loop
	while (dropOffLocated == false)
	{
		// Displays the current scan grid low and high numbers
		std::cout << "\nCurrent lowest number of Scan Grid: " << scanGridLowNum << std::endl;
		std::cout << "Current highest number of Scan Grid: " << scanGridHighNum << std::endl;

		// Algorithm to 'scan' for the drop off point
		// This will let us know if the drop off point is higher or lower than the previous scan.
		int estimatedDropOffPoint = ((scanGridHighNum - scanGridLowNum) / 2) + scanGridLowNum;

		std::cout << "\n\n*********************************************************************\n";
		std::cout << "\nPhantom DOL Ping: " << estimatedDropOffPoint << std::endl;

		// Increase scan count
		phantomDOLScans++;


		//evaluate the data from the Phantom DOL Ping
		if (estimatedDropOffPoint > dropOffPoint)
		{
			/* Since the estimatedDropOffPoint is > than the dropOffPoint, there is no need to scan
			at or above the estimatedDropOffPoint anymore.*/
			// Because of this, the scan grid high number gets reset.
			scanGridLowNum = estimatedDropOffPoint - 1;

			// Print out the new high number
			std::cout << "The estimated drop off point: " << estimatedDropOffPoint << ", was higher than the actual drop off point: " << dropOffPoint << "." << std::endl;
			std::cout << "The new highest number of the scan grid is " << scanGridHighNum << "." << std::endl;

			// Display that the scan grid got smaller
			std::cout << "\n** SCAN AREA NARROWED DOWN **\n";

			// Displays the current scan grid low and high numbers
			std::cout << "\nCurrent lowest number of Scan Grid: " << scanGridLowNum << std::endl;
			std::cout << "Current highest number of Scan Grid: " << scanGridHighNum << std::endl;
		}
		else if (estimatedDropOffPoint < dropOffPoint)
		{
			/* Since the estimatedDropOffPoint is < than the dropOffPoint, there is no need to scan
			at or below the estimatedDropOffPoint anymore.*/
			// Because of this, the scan grid low number gets reset.
			scanGridLowNum = estimatedDropOffPoint + 1;

			// Print out the new low number
			std::cout << "The estimated drop off point: " << estimatedDropOffPoint << ", was lower than the actual drop off point: " << dropOffPoint << "." << std::endl;
			std::cout << "The new lowest number of the scan grid is " << scanGridLowNum << "." << std::endl;

			// Print out that the scan grid got smaller
			std::cout << "\n** SCAN AREA NARROWED DOWN **\n";

			// Displays the current scan grid low and high numbers
			std::cout << "\nCurrent lowest number of Scan Grid: " << scanGridLowNum << std::endl;
			std::cout << "Current highest number of Scan Grid: " << scanGridHighNum << std::endl;
		}
		else if (estimatedDropOffPoint == dropOffPoint)
		{
			//display the estimated location
			std::cout << "\nEstimated drop off point: " << estimatedDropOffPoint << ".\n";

			/* If the estimatedDropOffPoint is same as dropOffPoint, it means the Phantom DOL
			has located the drop off point. */
			std::cout << "\nThe Phantom D.O.L System has located the package drop off point at " << dropOffPoint << ".\n";
			std::cout << "\nPhantom Drop Off Locator found the drop off point in " << phantomDOLScans << " scans." << std::endl;

			// Set the dropOffLocated bool to true to exit the loop.
			dropOffLocated = true;
		}
		else
		{
			//something was gone wrong with the Phantom Drones' software
			//print out an error message
			std::cout << "\nERROR: The Phantom Drop Off Locator system has failed." << std::endl;
			std::cout << "\nPlease try again after drone has returned to base." << std::endl;

			// Set the dropOffLocated boolean to true to exit the loop.
			dropOffLocated = true;
		}
	}


	// Print out end of simulator message to user.
	std::cout << "\n\n\t*** Phantom D.O.L executed it's task. The drone has been navigated to the packages drop off point. ***\n\n" << std::endl;
	system("pause");

	//takes user out of program
	//returns 0 to the operating system
	return 0;

}

/// <summary>
/// Function that prints out the title and description
/// </summary>
void DisplayIntro()
{
	// Title
	std::cout << "\n\n\t*** Welcome to Package Phantoms! ***\n\n" << std::endl;

	// Description
	std::cout << "Package Phantoms is a delivery service which makes its deliveries using Phantom Drones.";
	std::cout << "\nThese drones run off the Phantom Drop Off Locator (DOL) system that navigates them to ";
	std::cout << "\ntheir packages drop off point.\n" << std::endl;

	// Instructions
	std::cout << "\nToday you have been given the honor of initializing a drones DOL system.\n";
	std::cout << "To start the drone's Phantom D.O.L, ";
	system("pause");
}
