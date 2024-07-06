#pragma once
#ifndef ROSTERH
#define ROSTERH
#include "Student.h"

using std::string;

//Section E - Part 1
	//Create a "Roster" class that contains an array of Students
class Roster {

public:
	//creates empty roster array
	Student* classRosterArray[5] = { 0 };

	//function to add students to roster array
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	//function to remove students from roster array
	void remove(string studentID);

	//loop function to print all students currently in roster array
	void printAll();

	//funtion to calculate and print the average of the three integers in courseDays array
	void printAverageDaysInCourse(string studentID);

	//function to check for valid emails and print emails with errors
	void printInvalidEmails();

	//function to print students only in a specific degree program (enum)
	void printByDegreeProgram(DegreeProgram degreeProgram);
	
	//destructor
	~Roster();

};


#endif