#include "Student.h"

//using namespace std;
using std::string;


//Constructors
Student::Student() {	//default constructor
	id = "NONE";
	first = "n/a";
	last = "n/a";
	email = "n/a";
	age = 0;
	program = UNKNOWN;

	for (int i = 0; i < ARR_SIZE; ++i)
		{
			courseDays[i] = 0;
		}
};

Student::Student(string id, string first, string last, string email, int age, int* days[ARR_SIZE], DegreeProgram program) {
	this->id = id;
	this->first = first;
	this->last = last;
	this->email = email;
	this->age = age;
	this->program = program;

	for (int i = 0; i < ARR_SIZE; ++i)
	{
		courseDays[i] = *days[i];
	}
};

//Getters
	string Student::GetId() const {
		return id;
	}
	string Student::GetFirst() const {
		return first;
	}
	string Student::GetLast() const {
		return last;
	}
	string Student::GetEmail() const {
		return email;
	}
	int Student::GetAge() const {
		return age;
	}
	const int* Student::GetCourseDays() const {
		return courseDays;
	}

	DegreeProgram Student::GetProgram() const {
		return program;
	}

//Setters
	void Student::SetId(string userid) {
		id = userid;
	}
	void Student::SetFirst(string userfirst) {
		first = userfirst;
	}
	void Student::SetLast(string userlast) {
		last = userlast;
	}
	void Student::SetEmail(string useremail) {
		email = useremail;
	}
	void Student::SetAge(int userage) {
		age = userage;
	}
	void Student::SetCourseDays(int* days) {

		for (int i = 0; i < ARR_SIZE; ++i)
		{
			courseDays[i] = days[i];
		}
	}
	void Student::SetProgram(DegreeProgram userprogram) {
		program = userprogram;
	}

	//Print Function
	void Student::print() {
		if(program == 1)
		{
			std::cout << id << "\tFirst Name: " << first << "\tLast Name: " << last << "\tAge: " << age << "\tdaysInCourses: {" <<
				courseDays[0] << ", " << courseDays[1] << ", " << courseDays[2] << "}\tDegree Program: SECURITY" << std::endl;
		}
		else if(program == 2)
		{
			std::cout << id << "\tFirst Name: " << first << "\tLast Name: " << last << "\tAge: " << age << "\tdaysInCourses: {" <<
				courseDays[0] << ", " << courseDays[1] << ", " << courseDays[2] << "}\tDegree Program: NETWORK" << std::endl;
		}
		else if(program == 3)
		{
			std::cout << id << "\tFirst Name: " << first << "\tLast Name: " << last << "\tAge: " << age << "\tdaysInCourses: {" <<
				courseDays[0] << ", " << courseDays[1] << ", " << courseDays[2] << "}\tDegree Program: SOFTWARE" << std::endl;
		}
		else
		{
			std::cout << id << "\tFirst Name: " << first << "\tLast Name: " << last << "\tAge: " << age << "\tdaysInCourses: {" <<
				courseDays[0] << ", " << courseDays[1] << ", " << courseDays[2] << "}\tDegree Program: UNKNOWN" << std::endl;
		}
	}