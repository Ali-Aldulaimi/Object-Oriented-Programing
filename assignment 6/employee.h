#include "constants.h"

using namespace std;
class Employee {
	char name[LEN];
	int id;
	double salary;

public:
	void set_values(char*, int, double);
	char* get_name();
	int get_id();
	double get_salary();
	Employee* search_employee(int);
	void copy_values(Employee);

};
