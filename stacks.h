#pragma once
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Stack {
private:
    vector<int> stack;

public:
    // Check if the stack is empty
    bool isEmpty() const {
        return stack.empty();
    }

    // Push an integer onto the stack
    void push(int value) {
        stack.push_back(value);
    }

    // Pop an element from the stack
    void pop() {
        if (!isEmpty()) {
            stack.pop_back();
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }

    // Get the top element of the stack
    int top() const {
        if (!isEmpty()) {
            return stack.back();
        }
        else {
            cerr << "Stack is empty.\n";
            return -1; // Return an invalid value if the stack is empty
        }
    }

    // Calculate the average of the stack elements
    double average() const {
        if (!isEmpty()) {
            double sum = accumulate(stack.begin(), stack.end(), 0);
            return sum / stack.size();
        }
        else {
            cerr << "Stack is empty, cannot calculate average.\n";
            return 0.0; // Return 0 if the stack is empty
        }
    }

    // Display stack contents (for debugging purposes)
    void display() const {
        cout << "Current Stack: ";
        for (int elem : stack) {
            cout << elem << " ";
        }
        cout << std::endl;
    }
};

