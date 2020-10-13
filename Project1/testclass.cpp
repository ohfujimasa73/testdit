#include <string>
#include <iostream>
#include "./testclass.h"

testd::testd(int age, string name) {
	this->age = age;
	this->name = name;
}

void testd::show() {
	cout << "age:" <<this->age << endl;
	cout << "name:" <<this->name << endl;

}