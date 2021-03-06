#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;

/*
	Implemt Stack using std::queue
	-push is more expensive
	queue methods: push, back, pop, front
	std queue does not have built-in iterator
*/
class Stack {
public:
	queue<int> * primary = new queue<int>();
	queue<int> * secondary = new queue<int>();

	void push(int val) {
		secondary->push(val);

		while (!(primary->empty())) {
			secondary->push(primary->front());
			primary->pop();
		}

		queue<int> * temp = primary;
		primary = secondary;
		secondary = temp;
	}

	void pop() {
		if (primary->empty())
			cout << "Stack is empty!" << endl;
		else {
			cout << primary->front() << endl;
			primary->pop();
		}
	}

	int size() {
		return primary->size();
	}

};


int main()
{
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);


	s.pop();
	s.pop();
	s.pop();

	string n;
	cin >> n;
	return 0;
}

