#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"

/*
 *Author: Austin Holst (With significant help from Dieter)
 *Date: 1/25/2018
 *Code: A linked list using Nodes. Also uses a .o file so I couldn't change it
 */



using namespace std;

//Prototypes
void add(Student* newStudent, Node* newNode, Node* &head);
void recursiveAdd(Node* &head, Node* previous, Node* current, Node* newNode);
void print(Node* &head, Node* current);
void exterminate(Node* &head, Node* previous, Node* current, int id);
void average(Node* &head, Node* current, float combined, int total);

int main() {

  Node* head = NULL;
  bool running = true;

  //While the program is running
  while(running == true) {
    cout << "You can add, delete, print, average, or quit" << endl;
    char input[10];
    cin >> input;
    if(strcmp(input, "add") == 0) {
      int number = 0;
      char* fname = new char[100];
      char* lname = new char[100];
      float gpa = 0;
      cout << "What is the student's ID" << endl;
      cin >> number;
      cout << "What is the student's first name" << endl;
      cin >> fname;
      cout << "What is the student's last name" << endl;
      cin >> lname;
      cout << "What is the student's GPA" << endl;
      cin >> gpa;
      //Creating a new student
      Student* newStudent = new Student(number, fname, lname, gpa);
      //Creating a new node with the student in it
      Node* newNode = new Node(newStudent);
      add(newStudent, newNode, head);
    }
    else if(strcmp(input, "print") == 0) {
      Node* current = head;
      print(head, current);
    }
    else if(strcmp(input, "delete") == 0) {
      int id;
      cout << "What is the ID number of the student you wish to delete" << endl;
      cin >> id;
      exterminate(head, head, head, id);
    }
    else if(strcmp(input, "average") == 0) {
      Node* current = head;
      float combined = 0;
      int total = 0;
      average(head, current, combined, total);
    }
    else if(strcmp(input, "quit") == 0) {
      running = false;
    }
    else {
      cout << "That is not a valid command" << endl;
    }
  }
  return 0;
}

//Add function
void add(Student* newStudent, Node* newNode, Node* &head) {
  Node* current = head;
  Node* previous = head;
  //If there is no list of nodes yet
  if(current == NULL) {
    head = newNode;
  }
  //If the head nodes Id is greater than the new students
  else if (head->getStudent()->getID() > newStudent->getID()) {
    newNode->setNext(head); //put the new node in front of the head
    head = newNode; //set the new node to be the head of the list
  }
  else {
    //run the recursive add method
    recursiveAdd(head, previous, current, newNode);
  }
}
//Function for adding recursively
void recursiveAdd(Node* &head, Node* previous, Node* current, Node* newNode) { 
  //if you are at the end of the list
  if(current->getNext() == NULL) {
    //If the current node's ID is less than the new nodes ID
    if(current->getStudent()->getID() < newNode->getStudent()->getID()) {
      //put the new node after the current one
      current->setNext(newNode);
    }
    else {
      //put the new node before the current one
      previous->setNext(newNode);
      //set the new nodes next node to be current
      newNode->setNext(current);
    }
    return;
  }
  //if the current nodes ID is less than the new nodes ID
  if(current->getStudent()->getID() < newNode->getStudent()->getID() && current->getNext() != NULL) {
    //Run the recursive add again but with currents next node 
    recursiveAdd(head, current, current->getNext(), newNode);
    return;
  }
  else {
    //if the previous node is not the current one
    if(previous != current) {
      //set the previous's next node to be the new one
      previous->setNext(newNode);
      //set the new node's next node to current
      newNode->setNext(current);
      return;
    }
    else {
      //new nodes next node is head
      newNode->setNext(head);
      //head is the new node
      head = newNode;
    }
  }
}


//Print function
void print(Node* &head, Node* current) {
  //If there is no nodes
  if(current == NULL) {
    cout << "There is no list to check" << endl;
    return;
  }
  else {
    cout << current->getStudent()->getFName() << " ";
    cout << current->getStudent()->getLName() << ": ";
    cout << current->getStudent()->getID() << ", ";
    //setting the decimal point to read out to two places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << current->getStudent()->getGPA() << endl;
    print(head, current->getNext());
  }
}

//Delete function
void exterminate(Node* &head, Node* previous, Node* current, int id) {
  //If there is no nodes to delete
  if(current == NULL) {
    cout << "There is no list to delete from" << endl;
    return;
  }
  //if the currents ID is the id that the user inputed
  else if(current->getStudent()->getID() == id) {
    if(current == head) { //If that node is the head
      head = current->getNext();//set head to be the next node
      delete current; //delete the selected node
      return;
    }
    else {//If the selected node is not the head
      previous->setNext(current->getNext()); //set the previous's next node to currents next node 
      delete current;//delete the selected node
      return;
    }
  }
  else {
    //Run recursively for the next node
    exterminate(head, current, current->getNext(), id);
  }
  
}

//Average function
void average(Node* &head, Node* current, float combined, int total) {
  float result;
  if(current == NULL) {
    cout << "There is nothing to average" << endl;
  }
  //if at the end of the list
  else if(current->getNext() == NULL) {
    //add to the combined GPA total
    combined += current->getStudent()->getGPA();
    //add to total number of GPA's
    total++;
    //find the average
    result = (combined / total);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The average GPA of the students is: " << result << endl;
  }
  else {
    //add to the combined GPA total
    combined += current->getStudent()->getGPA();
    //Add to the total
    total++;
    //Run recurseively
    average(head, current->getNext(), combined, total);
  }
}

