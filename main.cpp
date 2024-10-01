#include <iostream>
#include "linkedlist.h"
#include "stacks.h"

using namespace std;

int main() {
	/*Single_Linked_List<int> lll;
	lll.push_front(1);
	lll.push_front(2);
	lll.push_back(3);
	lll.push_back(4);
	lll.push_front(5);
	//lll.display();
	//lll.info();

	lll.pop_front();
	lll.pop_back();
	//lll.display();
	//lll.info();

	//lll.front();
	//lll.back();
	///lll.empty();
	//lll.display();
	//lll.info();

	lll.insert(1, 5);
	//lll.display();
	//lll.info();

	lll.remove(2);
	//lll.display();
	//lll.info();
	cout << "The index of 2 is: " << lll.find(2) << endl;
	cout << "The index of 3 is: " << lll.find(3) << endl;
	lll.display();
	lll.info();
	*/

	Stack s;

	/*if (s.isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "Stack is not empty" << endl;
	}
	*/


	//s.display();

	s.push(10);
	s.push(20);
	s.push(30);
	//s.display();

	/*if (s.isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "Stack is not empty" << endl;
	}
	*/

	s.pop();
	//s.display();

	//cout << s.top();
	//s.display();

	double avg = s.average();

	cout << "The average of the stack is: " << avg << endl;
	
	return 0;
};
