// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Person {

public:
	int age = 0;
	string name = "";
	virtual void getdata() = 0;
	virtual void putdata() = 0;
};

class Professor : public Person {
public:
	int pubs;
	int cur_id;

	void getdata() {
		//should get the input from the user: the name, age and publications of the professor.
		cin >> name >> age >> pubs;
	}

	void putdata() {
		//should print the name, age, publications and the cur_id of the professor.
		cout << name << " " << age << " " << pubs << " " << cur_id;
	}
};

class Student : public Person {
public:
	int marks[6];
	int cur_id;

	void getdata() {
		//should get the input from the user: the name, age, and the marks of the student in  subjects.
		cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
	}

	void putdata() {
		//should print the name, age, sum of the marks and the cur_id of the student.
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += marks[i];
		}
		cout << name << " " << age << " " << sum;
	}
};

int main() {

	int n, val;
	cin >> n; //The number of objects that is going to be created.
	Person *per[3];

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i<n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;

}


