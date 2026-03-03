// M2. Managing Memory.cpp : Reverse Array

#include <iostream>

using namespace std;

int* ReverseArray(const int arr[], int size);

void print(const int arr[], int size);

int main()
{
	/* I typed int and this auto fill code showed up. 
	It even gave me this comment while typing about the auto fill *this code to test the ReverseArray function, but I will comment it out since the function is not implemented yet.
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Original array: ";
	print(arr, size);
	int* reversedArr = ReverseArray(arr, size);
	cout << "Reversed array: ";
	print(reversedArr, size);
	delete[] reversedArr; // Free the dynamically allocated memory
	return 0;
	*/

	const int SIZE = 10;
	int numbers[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Original array: ";
	print(numbers, SIZE);

	int* reversed = ReverseArray(numbers, SIZE);
	
	cout << "Reversed array: ";
	print(reversed, SIZE);

	delete[] reversed;//Clean-up *dynamically allocated memory* Auto suggested comment

	return 0;
}

int* ReverseArray(const int arr[], int size)
{
	int* rev = new int[size]; // Dynamically allocate memory for the reversed array

	for (int i = 0; i < size; i++)
	{
		rev[i] = arr[size - 1 - i]; // Fill the reversed array
	}
	return rev; // Return the pointer to the reversed array
}
void print(const int arr[], int size)
{
	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}