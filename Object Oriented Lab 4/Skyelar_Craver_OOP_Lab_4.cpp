/*
Skyelar Craver
Object Oriented Programming
Lab 4
Mansour, Fall 2017
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//prints array contents
void printArray(int myArray[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		cout << myArray[i] << " ";
	}
}

// reverses array symetrically
void reverseArray(int myArray[], size_t length) {
	for (size_t i = 0; i < (length / 2); i++) {
		int temp = myArray[i];
		myArray[i] = myArray[(length - 1) - i];
		myArray[(length -1 ) - i] = temp;
	}
	printArray(myArray, length);
}

//rotates array forward by one
void rotateArray(int myArray[], size_t length) {
	int *tempArray = new int[length];
	for (size_t i = 0; i < length; i++)
	{
		tempArray[i] = myArray[((i - 1) + length) % length];
	}
	for (size_t i = 0; i < length; i++)
	{
		myArray[i] = tempArray[i];
	}
	delete tempArray;
	printArray(myArray, length);
}

//re-writes the array as a fibbonacci sequence
void fibbonaciArray(int myArray[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		switch (i)
		{
		case 0:
		case 1:
			myArray[i] = 1;
			break;
		default:
			myArray[i] = (myArray[i - 1] + myArray[i - 2]);
			break;
		}
		cout << myArray[i] << " ";
	}
}

// fills the array with random numbers
void initializeArray(int myArray[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		myArray[i] = rand();
		cout << myArray[i] << " ";
	}
}

void main() {
	//define length variable
	size_t length;

	do { // ask the user for length until they submit a valid length

		cout << "\nhow large of an array do you want?\n";
		cin >> length;

	} while (length <= 0);

	//dynamically create an array in memory using the value the user input
	int *myArray = new int[length];

	cout << "\n\n";
	
	//fill the array with random numbers and display contents
	initializeArray(myArray, length);

	while (true) {// ask the user for operations until they decide to quit

	cout << "\nenter 'r' to reinitialize\n"
		<< "enter 'f' to initialize as fibbonacci\n"
		<< "enter 's' to reverse array\n"
		<< "enter 'o' to rotate array\n"
		<< "enter any other character to quit\n";

		//create a variable and use it to store the user's input
		char select;
		cin >> select;

		switch (select)
		{

		case 'r': //re-initialize
			initializeArray(myArray, length);
			break;

		case 's'://"swap" or reverse array
			reverseArray(myArray, length);			
			break;

		case 'f'://fill array with fibbonacci sequence
			fibbonaciArray(myArray, length);
			break;

		case 'o'://rotate array forward once
			rotateArray(myArray, length);
			break;

		default:
			delete myArray;
			return;
		}
	}
}