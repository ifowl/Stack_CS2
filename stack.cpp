//Isaac Fowler
//Stack Class Function Definitions
#include "stack.hpp"
#include <iostream>

template <typename T>
stack<T>::stack() {
    tos = 0;
}

//Checks if the stack is empty
template <typename T>
bool stack<T>::empty() const {
    return tos == 0;
}


//Copy constructor for copying stack
template <typename T>
stack<T>::stack(const stack<T>& rhs) {
    Node<T>* bottom = 0;
    Node<T>* tempTos = rhs.tos;
    Node<T> *tempNode;
    tos = 0;
    while (tempTos != 0) {
        tempNode = new Node<T>(tempTos->data);
        if (tos == 0) {
            tos = tempNode;
            bottom = tempNode;
        }
        else {
            bottom->next = tempNode;
            bottom = tempNode;
        }
        tempTos = tempTos->next;
    }
}

//Destructor
template <typename T>
stack<T>::~stack() {
    while (tos != 0) {
        Node<T>* temp = tos;
        tos = tos->next;
        delete temp;
    }
}

//Swaps stack with another stack
template <typename T>
void stack<T>::swap(stack<T>& rhs) {
    Node<T>* temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

//Assignment operator
template <typename T>
stack<T>& stack<T>::operator= (stack<T> rhs) {
    swap(rhs);
    return *this;
}

//Checks if stack is full
template <typename T>
bool stack<T>::full() const {
    Node<T>* check = new Node<T>;
    if (check == 0)
        return true;
    delete check;
    return false;
}

//Look at the top of stack and return its value
template <typename T>
T stack<T>::top() const {

    if (tos == 0) {
        return NULL;
    }
    else {
        return tos->data;
    }
}

//Grabs value of top, removes it, and makes node below it the new top.
template <typename T>
T stack<T>::pop() {
    Node<T>* temp = tos;
    T result = tos->data;
    tos = tos->next;
    delete temp;
    return result;
}

//Creates a new node as the top of stack and points to old tos
template <typename T>
void stack<T>::push(const T& x) {
    Node<T>* temp = new Node<T>(x);
    temp->next = tos;
    tos = temp;
}
