/*
* CS303
* Miguel R. Kunkle
* Created: 9/14/22
* 
* Description: Program that takes an array titled "numfile.txt" and
* allows the user to select options to manipulate the array
*/

#include <iostream>
#include <fstream>
#include "Assignment1.h"

void arrayIncrease(int*& values, int& size, int addition)
{
	int* newValues = new int[size];

	for (int i = 0; i < size; i++)
	{
		newValues[i] = values[i];
	}


	delete []values;

	values = newValues;
	newValues = NULL;

	values[size - 1] = addition;
}

void arrayDecrease(int*& values, int& size, int removalIndex)
{
	int* newValues = new int[size];

	for (int i = 0; i < size; i++)
	{
		if (i >= removalIndex)
		{
			newValues[i] = values[i + 1];
		}
		
		else
		{
			newValues[i] = values[i];
		}
	}
	delete[]values;

	values = newValues;
	newValues = NULL;
}

void fileRead(int values[])
{
	std::ifstream fin;

	int value;
	int i = 0;

	fin.open("numfile.txt");

	if (!fin.is_open())
	{
		std::cout << "Could not open the file." << std::endl;
	}

	while (fin >> value)
	{
		values[i] = value;
		i++;
	}
}

int searchArray(int array[], int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == num)
		{
			return i;
		}
	}

	return -1;
}

void modifyArray(int array[], int size)
{
	int oldNum;
	int index;
	int newValue;

	std::cout << "Enter the index you wish to modify: ";
	std::cin >> index;
	std::cout << "\n";

	oldNum = array[index];

	std::cout << "Enter the new value of this index: ";
	std::cin >> newValue; 

	array[index] = newValue;
	std::cout << "Old value: " << oldNum << std::endl;
	std::cout << "New Value: " << newValue << std::endl;
}

//this function prints the menu
void printMenu()
{
	std::cout << "1. Look for number in array.\n2. Modify number in array";
	std::cout << "\n3. Add new number to array\n4. Remove number from array" << std::endl;
	std::cout << "5. Print array\n6. Quit the program" << std::endl;
}

//this function is used for testing
void printArray(int values[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << *(values + i) << " ";
	}

	std::cout << std::endl;
}


int main()
{
	//Variable Decleration
	int size = 100;
	int* values = new int[size];

	bool runProgram = true;
	int choice = 0;

	//Gets Values from text file.
	fileRead(values);

	//Menu loop
	while (runProgram)
	{
		//Prints menu, and gets user's menu choice
		printMenu();
		std::cout << "\nPlease enter your choice:";
		std::cin >> choice;
		std::cout << "\n";

		//Array Search
		if (choice == 1)
		{
			int num;

			std::cout << "Please enter number to search for:";
			std::cin >> num;
			std::cout << "\n";

			int returnValue = searchArray(values, size, num);

			if (returnValue == -1)
			{
				std::cout << "Sorry, your number does not exist" << std::endl;
			}

			else
			{
				std::cout << "Success! Your number exists at index " << returnValue << std::endl;
				std::cout << "\n";
			}
		}

		//Array Modify
		else if (choice == 2)
		{
			modifyArray(values, size);

			std::cout << "\n";

		}

		//Array Addition
		else if (choice == 3)
		{
			int addition = 0;
			std::cout << "Please enter the number you wish to add: ";
			std::cin >> addition;
			std::cout << std::endl;

			size++;
			arrayIncrease(values, size, addition);
		}
		
		//Array Value Removal
		else if (choice == 4)
		{
			int removalIndex;
			std::cout << "Please enter the index you wish to remove: ";
			std::cin >> removalIndex;
			std::cout << std::endl;

			size--;
			arrayDecrease(values, size, removalIndex);
		}

		else if (choice == 5)
		{
			printArray(values, size);
		}

		//Program end
		else if (choice == 6)
		{
			runProgram = false;
			std::cout << "Ending program..." << std::endl;
		}

		//in case user inputs wrong number
		else
		{
			std::cout << "Improper input, please try again." << std::endl;
		}


	}

	//ending message
	std::cout << "Thank you! Program has ended." << std::endl;

	//deleting array
	delete []values;
}
