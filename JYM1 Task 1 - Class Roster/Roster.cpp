#include "Roster.h"

using std::string;

//Functions

//function to add students to roster array
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int courseDays[ARR_SIZE] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	Student* newStudent = new Student;

	newStudent->SetId(studentID);
	newStudent->SetFirst(firstName);
	newStudent->SetLast(lastName);
	newStudent->SetEmail(emailAddress);
	newStudent->SetAge(age);
	newStudent->SetCourseDays(courseDays);
	newStudent->SetProgram(degreeProgram);

	int size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	
	for (int i = 0; i < size; ++i)
	{
		if (classRosterArray[i] == 0)
		{
			classRosterArray[i] = newStudent;
			break;
		}	
	}
}

//function to remove students from roster array
void Roster::remove(string studentID)
{
	Student* pointer = new Student;
	int size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	bool found = false;
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		if (classRosterArray[i] != 0)
		{
			pointer = classRosterArray[i];
			if (pointer->GetId() == studentID)
			{
				classRosterArray[i] = 0;
				found = true;
			}
		}
	}

	if (found == false)
	{
		std::cout << "Error: Student with ID \"" <<studentID << "\" Not Found" << std::endl;
	}
}

//loop function to print all students currently in roster array
void Roster::printAll()
{
	int size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	Student* pointer = new Student;

	for (int i = 0; i < size; ++i)
	{
		if (classRosterArray[i] != 0)
		{
			pointer = classRosterArray[i];
			pointer->print();
		}
	}
}

//funtion to calculate and print the average of the three integers in courseDays array
void Roster::printAverageDaysInCourse(string studentID)
{
	Student* pointer = new Student;
	int size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	bool found = false;
	const int* avgArray;
	int avg;

	for (int i = 0; i < size; i++)
	{
		if (classRosterArray[i] != 0)
		{
			pointer = classRosterArray[i];
			if (pointer->GetId() == studentID)
			{
				avgArray = pointer->GetCourseDays();
				avg = (avgArray[0] + avgArray[1] + avgArray[2]) / 3;
				std::cout << "Average Days: " << avg << std::endl;
				found = true;
			}
		}
	}

	if(found == false)
	{
		std::cout << "Error: Student ID Not Found" << std::endl;
	}
}

//function to check for valid emails and print emails with errors
void Roster::printInvalidEmails()
{
	Student* pointer = new Student;
	int size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	string temp;
	bool found = false;

	for (int i = 0; i < size; ++i)
	{
		if (classRosterArray[i] != 0)
		{
			pointer = classRosterArray[i];
			temp = pointer->GetEmail();
			if (temp.find('@') == string::npos || temp.find(' ') != string::npos || temp.find('.') == string::npos)
			{
				std::cout << temp << std::endl;
				found = true;
			}
		}
	}

	if (found == false)
		std::cout << "No Invalid Emails Found" << std::endl;
}

//function to print students only in a specific degree program (enum)
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	int size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	Student* pointer = new Student;
	bool found = false;

	for (int i = 0; i < size; ++i)
	{
		if (classRosterArray[i] != 0)
		{
			pointer = classRosterArray[i];
			if (pointer->GetProgram() == degreeProgram)
			{
				pointer->print();
				found = true;
			}
		}
	}

	if (found == false)
	{
		std::cout << "Error: Degree Program Not Found" << std::endl;
	}
}

//Section F - Part 5
//destructor to free dynamically allocated memory
Roster::~Roster()
{
	delete classRosterArray;
}