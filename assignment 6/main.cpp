/*Write a C++ program in which you define class employeeand necessary functions for reading employees
' information and saving them to an array of class employee. The member variables of the class should be: name, id and salary. 
The member functions of the class should be set_values(), print_values() and search_employee(). The function search_employee() should return 
a pointer to the object if the id it receives as parameter is the same as the id of the object.
Declare all variables as private and use only functions for manipulating them. The program must print to the standard output a menu, 
from which user can choose the following actions:
A : add new employee information
R : remove employee's information
S : search based on employee's ID
Q : quit
The program must print to the standard output and update a counter which shows the number of employees whose information are saved in the 
database.The program must keep on showing the menu and letting the user to make a choice as long as Q is not pressed.*/

#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "constants.h"
#include "employee.h"


#pragma once


using namespace std;

Employee* enlarge_array(Employee* emp, int* size) {
	Employee* temp=NULL;
	(*size)++;
	try {
		temp = new Employee[*size];
	}
	catch (bad_alloc xa) {
		cout << "\nAllocation failure\n";
	}
	
	for (int j = 0; j < *size - 1; j++)

		temp[j + 1] = emp[j];

	delete emp ;

	return temp;


}


Employee* remove_employee(Employee* emps, int index, int* size) {

	Employee* temp = new Employee[*size - 1];
	int counter = 0;
	for (int i = 0;i < *size;i++) {

		if (i != index) {
			temp[counter].copy_values(emps[i]);

			counter++;
		}
	}

	delete emps;
	(*size)--;


	return temp;


}









char menu();
Employee* search(Employee* emp, int id, int size);
void init_object(Employee* emp);
Employee* enlarge_array(Employee* emp, int* size);





int main() {
int size = 0;
int i;


	//Here we declare Employee pointer.
Employee* employees = NULL;

	char choice;
	char answer;
	choice = 'y';

	do {
		char option = menu();


		if (option == 'A') {

			do {

				cout << "Enter Employee data: " << endl;
				employees = enlarge_array(employees, &size);
				init_object(employees);
				cin.get();
				cout << "---------------------------------------------------" << endl;


				for (i = 0; i < size; i++) {
					cout << i+1 << endl;
					cout << "Name : " << employees[i].get_name() << endl; 
					cout << "ID : " << employees[i].get_id() << endl;
					cout << "Salary : " << employees[i].get_salary() << endl;
					cout << endl;

				}
				cout << "---------------------------------------------------" << endl;
				cout << "Do you want to continue? (y/n) ";
				cin.get(choice);

			} while (choice == 'y');
		}


		if (option == 'R') {

			do {
				int id;
				char choice;
				cout << "Enter employee ID" << endl;
				cin >> id;
				cout << " Are you sure you want to remove this employee ? (y/n)" << endl;
				cin >> choice;

				Employee* temp = search(employees, id, size);
				if (temp) {
					if (choice == 'y') {
						int index = -1;
						Employee* e = NULL;
						if (employees != NULL) {
							for (i = 0;i < size;i++) {

								e = employees[i].search_employee(id);
								if
									(e != NULL) {
									index = i;
									break;

								}
							}
						}
							if (index != -1) {

							employees = remove_employee(employees, index, &size);
						}
					}
				}
				else cout << "There is no mathced result !" << endl;
					cin.get();
				
					cout << "Do you want to continue? (y/n) ";
					cin.get(answer);
					getchar();

				} while (answer == 'y');
			
			}



		if (option == 'S') {

			do {

				int id;

				cout << "Please enter the Employee's ID : " << endl;
				cin >> id;
				cin.get();
				Employee* temp =search(employees, id, size);
				if (temp != NULL) {
					cout <<"Name :" << temp->get_name() << endl;
					cout <<"ID :" << temp->get_id() << endl;
					cout <<"Salary :"<< temp->get_salary() << endl;
				}
				else cout << "There is no mathced result !" << endl;

				cout << "Do you want to continue? (y/n) ";
				cin.get(answer);
				getchar();
			} while (answer == 'y');




		}




			if (option == 'L') {
				cout << "currrent size" << size<<endl;
				cout << "---------------------------------------------------" << endl;
				for (i = 0; i < size; i++) {
					cout << i+1 << endl;
					cout << "Name : " << employees[i].get_name() << endl;
					cout << "ID : " << employees[i].get_id() << endl;
					cout << "Salary : " << employees[i].get_salary() << endl;
					cout << endl;

				}
				cout << "---------------------------------------------------" << endl;
			}

			if (option == 'Q') {

				cout << "Goodbye !!" << endl;
				break;
			}



	} while (choice == 'n');

	

	//Here we delete reserved memory.
		delete[] employees;
		return 0;

	}