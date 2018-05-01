#include "stackType.h"
#include "stackType.cpp"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//THIS LITTLE GUY IS A TEST COMMENT TO SEE IF MY PUSH WORKED
int main(){
	//String to hold user input
	string entered_number;
	//Holds the number to check input before pushing to stack
	int hold_num;
	//Stack to hold the user input for conversion
	stackType<int> mainStack;

	//Main loop
	while (true){
		//bool to help verify user input
		bool correct_input = true;
		//total holds decimal value of output
		int total = 0;
		//count counts up for purposes of 2^n multiplication
		int count = 0;

		//Request user input binary number
		cout << "Enter a binary number to convert to decimal, or enter -9 to quit:" << endl;
		//Take in user entry as string
		cin >> entered_number;
		
		//Condition to see if user would like to exit loop
		if (entered_number[0] == '-' && entered_number[1] == '9'){
			cout << "Exiting Program" << endl;
			return 0;
		}


		//for loop to push all parts of user entry onto stack
		for (int i = 0; i < entered_number.length() && correct_input; i++){
			//Convert the char at position i to int
			hold_num = entered_number[i] - '0';
			
			//If the number is a useful binary number, continue with program. If not, signal incorrect input
			if (hold_num == 0 || hold_num == 1){
				mainStack.push(hold_num);
			}
			else {
				correct_input = false;
			}
		}

		//If input is valid, proceed with conversion, if not, reset loop
		if (correct_input){
			//While loop to multiply out every binary number the user entered
			while (!mainStack.isEmptyStack()){
				total += mainStack.top()*(pow(2,count));
				count++;
				mainStack.pop();
			}
			//Print out conversion
			cout << entered_number << " in decimal is " << total << endl << endl;
		}
		else{
			//Inform user they entered incorrect input
			cout << entered_number << " is not in the correct binary input format" << endl << endl;
		}
	}
	return 0;
}
