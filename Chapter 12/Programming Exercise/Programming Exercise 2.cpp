/******************************************************************************
	Author: Saifur Rahman

	Purpose: 2. Redo Programming Exercise 6 of Chapter 8 using dynamic arrays.
	Input Parameters: InputStudentAnswer.txt
	Output Parameters: OutputResult.txt

********************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const int maxAns = 20;
char Grade(int percent);

int main()
{
	char correctAnswers[maxAns];
	char stuResponse[maxAns + 1];
	string stdId;
	int i;

	ifstream inputFile;
	inputFile.open("InputStudentAnswer.txt");
	ofstream outputFile;
	outputFile.open("OutputResult.txt");

	// Store the correctAnswers in a variable
	for (i = 0; i < maxAns; i++)
	{
		inputFile.get(correctAnswers[i]);
	}

	while (!inputFile.eof())
	{
		int score = 0;
		double possiblePoints = 40.0;
		double percent = 0.0;

		//Pull the students id from the start of the line.
		inputFile >> stdId;

		//Pull the space from start of correctAnswers.
		inputFile.get();

		//Pull the students correctAnswers.
		for (i = 0; i < maxAns + 1; i++)
		{
			inputFile.get(stuResponse[i]);
		}

		// Check students choices with the correct Answers and adjust score accordingly.

		for (i = 0; i < maxAns; i++)
		{
			outputFile << "Correct Answer  : " << correctAnswers[i] << endl;
			outputFile << "Student's Answer: " << stuResponse[i] << endl;
			
			if (correctAnswers[i] == stuResponse[i])
			{
				//Add two points.
				score = score + 2;
			}
			else if (correctAnswers[i] = ' ')
			{
				//No points deducted.
				score = score;
			}
			else if (correctAnswers[i] != stuResponse[i])
			{
				//Deduct one point.
				score = score - 1;
			}
		}

		/* Output the student's ID, 
					  CorrectAnswers,
					  Test score,
					  Test grade 
		*/

		outputFile << "\nStudent ID    : " << stdId << endl;
		outputFile << "Correct Answers: ";
		
		for (i = 0; i < maxAns; i++)
		{
			outputFile << stuResponse[i];
		}

		outputFile << "\nTest Score    : " << score << "/" <<possiblePoints << endl;
		percent = (score / possiblePoints) * 100;
		outputFile << "Percentage     : " << percent << "%" << endl;
		outputFile << "Grade          : " << Grade(percent) << endl;
		outputFile << "\n************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}


//Calculate grades obtained.
char Grade(int percent)
{
	if (percent >= 90)
		return 'A';
	else if (percent >= 80)
		return 'B';
	else if (percent >= 70)
		return 'C';
	else if (percent >= 60)
		return 'D';
	else
		return 'F';
}