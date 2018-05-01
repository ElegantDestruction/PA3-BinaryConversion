#ifndef STACKTYPE_H
#define STACKTYPE_H
#include <iostream>
#include <string>
using namespace std;

template<class Type>
class stackType{
private:
	//Capacity of Stack, and number of elements currently in the stack
	int maxStackSize, stackTop;
	//Holds the list (array?)
	Type *list;
	void copyStack(const stackType<Type>& s);
public:
	const stackType<Type>& operator=(const stackType<Type>& s);
	//Added on 04/02 for StackLab
	bool operator==(const stackType<Type>& s);
	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;
	void push(const Type&);
	Type top() const;
	void pop();
	void reverseStack(const stackType<Type> &otherStack);
	stackType(int size=100);
	stackType(const stackType<Type>& s);
	stackType(int sT, int mSS, const Type *l);
	~stackType();
};
#endif