//Tyler Petrow
//ID: 011118169
//Scripting and Programming - Applications - C867
//JYM1 — JYM1 TASK 1: CLASS ROSTER
	//VERSION 1.1 - (Revised 11/19)

#include "Roster.h"
using std::string;

int main() {
//Section F - Part 1
	//Personal submission info
	std::cout << "Course Title: Scripting and Programming - Applications - C867" << std::endl;
	std::cout << "Program Language: C++" << std::endl;
	std::cout << "Student ID: 011118169" << std::endl;
	std::cout << "Student Name: Tyler Petrow" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

//Section F - Part 2
		//create a new classRoster
	Roster* classRoster = new Roster;

//Section F - Part 3
	//add new Student Objects to the classRoster Array		
		//Note: Student Class has ID, First, Last, Email, Age, CourseDays Array[3 ints], Program enum
	classRoster->add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
	classRoster->add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
	classRoster->add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
	classRoster->add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
	classRoster->add("A5", "Tyler", "Petrow", "tpetrow@wgu.edu", 25, 19, 40, 70, SOFTWARE);
	
//Section F - Part 4
		//print all
	classRoster->printAll();
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	
		//print invalid emails
	std::cout << "Invalid Emails: " << std::endl;
	std::cout << "\n";
	classRoster->printInvalidEmails();
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

		//print all averages by ID number in loop
	std::cout << "Class Days Averages: " << std::endl;
	std::cout << "\n";
	int size = sizeof(classRoster->classRosterArray) / sizeof(classRoster->classRosterArray[0]);
	Student* pointer = new Student;
	string tempID;
	for (int i = 0; i < size; ++i)
	{
		if (classRoster->classRosterArray[i] != 0)
		{
			pointer = classRoster->classRosterArray[i];
			tempID = pointer->GetId();
			std::cout << tempID << " ";
			classRoster->printAverageDaysInCourse(tempID);
		}
	}
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

		//print degree program SOFTWARE
	std::cout << "Students in Degree Program SOFTWARE: " << std::endl;
	std::cout << "\n";
	classRoster->printByDegreeProgram(SOFTWARE);
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	
		//remove A3 and print
	classRoster->remove("A3");
	std::cout << "Student List After Removing ID \"A3\": " << std::endl;
	std::cout << "\n";
	classRoster->printAll();
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

		//try removing A3 again
	classRoster->remove("A3");

	return 0;
}