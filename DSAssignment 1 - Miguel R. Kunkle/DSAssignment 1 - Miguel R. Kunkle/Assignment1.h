#pragma once
#ifndef ASSIGNMENT1_H_
#define ASSIGNMENT1_H_

void arrayIncrease(int*& values, int& size, int addition);

void arrayDecrease(int*& values, int& size, int removalIndex);

void fileRead(int values[]);

int searchArray(int array[], int size, int num);

void modifyArray(int array[], int size);

void printMenu();

void printArray(int values[], int size);

#endif