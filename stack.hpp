#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:
// Updated:    Spring 2021
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>

////////////////////////////////////////////////////////////////////////////
//
template<typename T>
class Node {
public:
    Node() {
        Node next(0);
    }
    //Node() : data(), next(0) {};
    //Node(T item) {
    //    Node data(item);
    //    Node next(0);
    //}
    Node(T item) : data(item), next(0) {};

    T data;
    Node<T>* next;
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//
template <typename T>
class stack {
public:
    stack();
    //stack() : tos(0) {}; //default constructor
    stack(const stack<T>&); //copy constructor
    ~stack(); //destructor
    void      swap(stack<T>&); //time swap
    stack<T>& operator= (stack<T>); //assignment
    bool      empty() const;
    bool      full() const;
    T         top() const;
    T         pop();
    void      push(const T&);

private:
    Node<T>* tos; //top of stack
};

#endif