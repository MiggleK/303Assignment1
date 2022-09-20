
#include <iostream>
#include <fstream>

void arrayIncrease(int* oldValues, int& size, int addition)
{
	size++;

	int* newValues = new int[size];

	for (int i = 0; i < size; i++)
	{
		newValues[i] = oldValues[i];
	}

	newValues[size - 1] = addition;

	newValues = oldValues;
	oldValues = NULL;

}

void arrayDecrease(int* oldValues, int& size, int addition)
{
	size++;

	int* newValues = new int[size];

	for (int i = 0; i < size; i++)
	{
		newValues[i] = oldValues[i];
	}

	newValues[size - 1] = addition;

	newValues = oldValues;
	oldValues = NULL;

	delete[]oldValues;

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

	return size + 1;

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

	std::cout << "Old value: " << oldNum << std::endl;
	std::cout << "New Value: " << newValue << std::endl;
}

void printMenu()
{
	std::cout << "\n1. Look for number in array.\n2. Modify number in array";
	std::cout << "\n3. Add new number to array\n4. Remove number from array" << std::endl;
}


int main()
{
	int size = 100;
	int addition = 0;
	int* values = new int[size];

	bool runProgram = true;
	int choice = 0;

	fileRead(values);
	for (int i = 0; i < 50; i++)
	{
		std::cout << *(values + i) << " ";
	}

	while (runProgram)
	{
		printMenu();
		
		
	}

	


	delete []values;
}
