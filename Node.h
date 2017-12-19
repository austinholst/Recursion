//header guards
#ifndef NODE_H
#define NODE_H

//include libraries and h files
#include <iostream>
#include "Student.h"

using namespace std;

//node class
class Node {
 public: //function declarations
  Node(Student*);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);
 protected: //variables
  Student* s;
  Node* n;
};
#endif
