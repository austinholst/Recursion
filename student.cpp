#include <iostream>
#include "Student.h"

//Student constructor
Student::Student(int newID, char* newFName, char* newLName, float newGPA) {
  id = newID;
  fname = newFName;
  lname = newLName;
  gpa = newGPA;
}

//Returns the students id
int Student::getID() {
  return id;
}

//Returns the students first name
char* Student::getFName() {
  return fname;
}

//Returns the students last name
char* Student::getLName() {
  return lname;
}

//Returns the students GPA
float Student::getGPA() {
  return gpa;
}
