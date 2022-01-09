#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "constants.h"
#include "employee.h"

using namespace std;
// Methods
void Employee::set_values(char* name, int id, double salary) {
	strcpy_s(this->name, name);
	this->id = id;
	this->salary = salary;

}
char* Employee::get_name() {
	return this->name;

};
int Employee::get_id() {
	return this->id;


};
double Employee::get_salary() {
	return this->salary;
};



Employee* Employee::search_employee(int id) {
	if (this->id == id)
		return this;
	else return NULL;

	}







// Funtions 

char menu() {
	char choice;
	cout << "A: Add new employee information" << endl;
	cout << "R: remove employee's information" << endl;
	cout << "S: search based on employee's ID" << endl;
	cout << "L: List the employees" << endl;
	cout << "Q: quit" << endl;
	cout << endl;
	cout << "Please choose an option : ";
	cin >> choice;
	getchar();
	return choice;
}

Employee* search(Employee* emp, int id, int size) {
	
	Employee* temp = NULL ;
	for (int i = 0; i < size;i++) {
		temp = emp[i].search_employee(id);
		
		if (temp != NULL)
			break;
	}

	return temp;
	
}

void init_object(Employee* emp) {
	char name[LEN];
	int id;
	float salary;
	cout << "Name: ";
	cin >> name;
	cout << "ID: ";
	cin >> id;
	cout << "Salary: ";
	cin >> salary;
	emp->set_values(name, id, salary);
}

void Employee::copy_values(Employee e) {
    this->id=e.id;
	this->salary= e.salary ;
	strcpy_s(this->name, LEN,e.name );



}








