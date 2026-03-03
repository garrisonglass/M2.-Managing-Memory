// M2. Managing Memory.cpp : Reverse Array

#include <iostream>

using namespace std;
/*
	Function:       ReverseArray

	Purpose:        Dynamically allocates a new array and fills it
			        with the contents of the original array in
			        reverse order.

	Input:          arr[] - the original array (read-only)
			        size  - number of elements in arr
	
	Preconditions:  size > 0, arr contains valid integers
	
	Postconditions: Returns a pointer to a new dynamically
					allocated array. Caller is responsible
					for deleting this memory using delete[].
*/
int* ReverseArray(const int arr[], int size);
/*
	Function:       print

	Purpose:        Displays the contents of an integer array.

	Input:          arr[] - array to print
			        size  - number of elements

	Preconditions:  size >= 0
	Postconditions: None (output only)
*/
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
	int* rev = new int[size];//Dynamically allocate memory for the reversed array

	for (int i = 0; i < size; i++)
	{
		rev[i] = arr[size - 1 - i];//Fill the reversed array. I used the [size-1-i] from a previous project
	}
	return rev;//Returns the pointer to the reversed array
}

void print(const int arr[], int size)
{
	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}