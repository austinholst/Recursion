#include <iostream>

using namespace std;

class Student {
 public:
  Student(int id, char* fname, char* lname, float gpa);
  int getID();
  char* getFName();
  char* getLName();
  float getGPA();
 private:
  int id;
  char* fname;
  char* lname;
  float gpa;
};
