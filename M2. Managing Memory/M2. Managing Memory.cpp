// M2. Managing Memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Student
{
    string lastName;
    int    studentID;
    double scores;
    double average;
    char   grade;
};

// Constants
const int MAX_CLASS_SIZE = 150;
const int NUM_TEST_SCORES = 5;

// Functions
int  ReadData(string names[], double scores[][NUM_TEST_SCORES]);
double GetAvg(const double scores[], int size);
char GetLetterGrade(double average);
void printReport(const string names[], const double averages[], const char grades[], int count);

int main()
{
    string names[MAX_CLASS_SIZE];
    double scores[MAX_CLASS_SIZE][NUM_TEST_SCORES];
    double averages[MAX_CLASS_SIZE];
    char   grades[MAX_CLASS_SIZE];

    int studentCount = ReadData(names, scores);

    for (int i = 0; i < studentCount; i++)
    {
        averages[i] = GetAvg(scores[i], NUM_TEST_SCORES);
        grades[i] = GetLetterGrade(averages[i]);
    }
    printReport(names, averages, grades, studentCount);

    return 0;
}

// Reads data from file and returns number of students read
int ReadData(string names[], double scores[][NUM_TEST_SCORES])
{
    ifstream inFile("StudentGrades.txt");
    if (!inFile)
    {
        cout << "Error opening file!" << endl;
        return 0;
    }

    int count = 0;
    while (count < MAX_CLASS_SIZE && inFile >> names[count])
    {
        for (int i = 0; i < NUM_TEST_SCORES; i++)
        {
            inFile >> scores[count][i];
        }
        count++;
    }

    inFile.close();

    return count;
}

// Calculates the average score for a student
double GetAvg(const double scores[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }
    return sum / size;
}

// Assigns letter grade based on the students average
char GetLetterGrade(double average)
{
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else                    return 'F';
}

// Prints formatted grade report
void printReport(const string names[], const double averages[], const char grades[], int count)
{
    cout << left
        << setw(12) << "Names"
        << setw(11) << "Averages"
        << setw(10) << "Grades"
        << endl;

    cout << "------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        cout << left
            << setw(12) << names[i]
            << setw(11) << fixed << setprecision(2) << averages[i]
            << setw(10) << grades[i]
            << endl;
    }
}
