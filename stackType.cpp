#include "stackType.h"
#include <iostream>
#include <string>
using namespace std;

 //Added on 04/02 for StackLab
 //Operator overload to compare two stacks
 template<class Type>
 bool stackType<Type>::operator ==(const stackType<Type>& s){
	//Make two stacks replicating current stack and stack s
	stackType<Type> firstack = stackType<Type>(stackTop, maxStackSize, list);
	stackType<Type> secstack = stackType<Type>(s);
	//Pop thru the replica stacks and compare values along the way. If they're ever not the same value, the stacks are unequal
	while (!(firstack.isEmptyStack()) || !(secstack.isEmptyStack())){
		if (firstack.top()==secstack.top()){
			firstack.pop();
			secstack.pop();
		}
		else {
			return false;
		}
	}
	return true;
 };
 
//Function to take in a stack, and fill it with the reverse contents of current stack
 template<class Type>
 void stackType<Type>::reverseStack(const stackType<Type>& otherStack){
	 //Make dummy stack of current stack and initialize passed stack
	 stackType<Type> ogDummy = stackType<Type>(stackTop, maxStackSize, list);
	 otherStack.initializeStack();
	 //Push elements from current stack onto passed stack
	 while (!ogDummy.isEmptyStack()){
		 otherStack.push(ogDummy.top());
		 ogDummy.pop();
	 }
 };

 //Function to check if stack is empty
 template<class Type>
 bool stackType<Type>::isEmptyStack() const{
	 //If the top of the stack is position 0, the stack is empty
	 return (stackTop == 0);
 };
 
//Function to check if stack is full
 template<class Type>
 bool stackType<Type>::isFullStack() const{
	 //If the top of the stack is at the max position of the stack, stack is full
	 return (stackTop==maxStackSize);
 };

//Function to initialize stack 
 template<class Type>
 void stackType<Type>::initializeStack(){
	 //Set the top of the stack to 0 (essentially abandoning anything previously in the array list
	 stackTop=0;
 };
 
//Function to return the element at the top of the stack
 template<class Type>
 Type stackType<Type>::top()const{
	 //If the stack is not empty, return the element, else return false
	 if(!isEmptyStack()){
		return list[stackTop-1];
	 }
	 else
		 return false;
 };
 
//Function to add an element to the top of the stack
 template<class Type>
 void stackType<Type>::push(const Type& t){
	 //If the stack is not full, add the element to the top of the stack, and add 1 to the stackTop
	 if (!isFullStack()){
		 list[stackTop] = t;
		 stackTop++;
	 }
 };
 
//Funciton to remove an element from the top of the stack
 template<class Type>
 void stackType<Type>::pop(){
	 //If the list is not already empty, reduce the stackTop, thus "forgetting" the top element
	 if(!isEmptyStack()){
		 stackTop--;
	 }
 };
 
//Function to take in a stack, and copy its contents to current stack
 template<class Type>
 void stackType<Type>::copyStack(const stackType<Type>& s){
	 //Match all properties
	 this->maxStackSize = s.maxStackSize;
	 this->stackTop = s.stackTop;
	 Type *newlist = new Type[maxStackSize];
	 for (int i = 0; i<stackTop; i++){
		 newlist[i] = s.list[i];
	 }
	 delete[] this->list;
	 this->list = newlist;
 };
 
//Default Constructor - makes a stack of size 'size' and initializes all other relevant values
 template<class Type>
 stackType<Type>::stackType(int size){
	 maxStackSize = size;
	 stackTop = 0;
	 list = new Type[maxStackSize];
 };
 
//Non-Default constructor - makes a stack based on passes stack 's'
 template<class Type>
 stackType<Type>::stackType(const stackType<Type>& s){
	 maxStackSize = s.maxStackSize;
	 stackTop = s.stackTop;
	 list = s.list;
 };
 
//Alternate constructor -  allows better control of stack by allowing user to pass specific members of stack
//Not sure why I made this, but I recall needing it for something...
 template<class Type>
 stackType<Type>::stackType(int sT, int mSS, const Type *l){
	 stackTop = sT;
	 maxStackSize = mSS;
	 list = l;
 }
 
//Operator overload for extremely easy stack copying
 template<class Type>
 const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& s){
	 copyStack(s);
	 return (*this);
 }
 
//Destructor. Mostly just here to free up the list pointer
 template<class Type>
 stackType<Type>::~stackType(){
	 delete[] list;
 }
