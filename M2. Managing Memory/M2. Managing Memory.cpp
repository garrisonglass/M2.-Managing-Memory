// M2. Managing Memory.cpp : Course-Grades

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Student
{
    string lastName;
    int    studentID;
    double* scores;
    double average;
    char   grade;
};


// Functions

double GetAvg(const double scores[], int numTests);
char GetLetterGrade(double average);
void printReport(const Student student[], int count);

//Opens file, reads the number of students and tests, and creates a dynamically sized array of Student records.
//For each student, main reads identifying information and test scores, allocates a dynamic array to store those scores. 
//Then omputes both the average and letter grade using functions.
//After all student data is processed, main prints a formatted grade report. 
//Then releases all dynamically allocated memory before ending.

int main()
{
    ifstream inFile("student_data.txt");
    if (!inFile)
    {
        cout << "Error opening file!" << endl;
        return 0;
    }

    int numStudents, numTests;
    inFile >> numStudents >> numTests;

    Student* students = new Student[numStudents];
   
    for (int i = 0; i < numStudents; i++)
        {
            inFile >> students[i].lastName;
            inFile >> students[i].studentID;

            students[i].scores = new double[numTests];

            for (int t = 0; t < numTests; t++)
            {
                inFile >> students[i].scores[t];
            }
            students[i].average = GetAvg(students[i].scores, numTests);
            students[i].grade   = GetLetterGrade(students[i].average);
        }
           
        inFile.close();

        printReport(students, numStudents);

        for (int i = 0; i < numStudents; i++)
            delete[] students[i].scores;

        delete[] students;

    return 0;
}

//Calculates the average score for a student
double GetAvg(const double scores[], int numTests)
{
    double sum = 0;
    for (int i = 0; i < numTests; i++)
    {
        sum += scores[i];
    }
    return sum / numTests;
}

//Assigns letter grade based on the students average
char GetLetterGrade(double average)
{
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else                    return 'F';
}

//Prints formatted grade report
void printReport(const Student students[], int count)
{
    cout << left
        << setw(12) << "Names"
        << setw(12) << "ID"
        << setw(11) << "Averages"
        << setw(10) << "Grades"
        << endl;

    cout << "------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        cout << left
            << setw(12) << students[i].lastName
            << setw(12) << students[i].studentID
            << setw(11) << fixed << setprecision(2) << students[i].average
            << setw(10) << students[i].grade
            << endl;
    }
}
