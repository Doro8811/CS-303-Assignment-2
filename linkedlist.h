#pragma once
#include <iostream>

using namespace std;

template<typename Item_Type> //template for ease of use
class Single_Linked_List { //declaration of the linked list class
private:
    struct Node { //declaration of node struct
        Item_Type data;
        Node* next;
        Node(const Item_Type& data_item, Node* next_ptr = nullptr)
            : data(data_item), next(next_ptr) {}
    };

    Node* head; //head and tail as well as the data for the node
    Node* tail;
    size_t size;

public: //constructor for the linked list
    Single_Linked_List() : head(nullptr), tail(nullptr), size(0) {}

    ~Single_Linked_List() { //destructor
        while (!empty()) {
            pop_front();
        }
    }

    // Push an item to the front of the list while also incrementing the size of the list
    void push_front(const Item_Type& item) {
        Node* new_node = new Node(item, head);
        head = new_node;
        if (tail == nullptr) {
            tail = head;
        }
        ++size;
    }

    // Push an item to the back of the list while also incrementing the size of the list
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (tail == nullptr) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        ++size;
    }

    // Pop an item from the front of the list, also decrements the list
    void pop_front() {
        if (empty()) {
            std::cerr << "List is empty\n";
            return;
        }
        Node* old_head = head;
        head = head->next;
        delete old_head;
        --size;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    // Pop an item from the back of the list also decrements the list
    void pop_back() {
        if (empty()) {
            std::cerr << "List is empty\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        --size;
    }

    // Get the front item
    Item_Type front() const { //returns the index 0 of the list, will throw an exception if empty
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        cout << "Front is: " << head->data << endl;
        return head->data;
    }

    // Get the back item
    Item_Type back() const { //return last index of the list, will throw exception
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        cout << "back is: " << tail->data << endl;
        return tail->data;
    }

    // Check if the list is empty
    bool empty() const { //short function for checking if list is empty
        return head == nullptr;
    }

    // Insert item at a specific index
    void insert(size_t index, const Item_Type& item) {
        if (index == 0) { //depending on index, will insert at front if index input is 0
            push_front(item);
        }
        else if (index >= size) { //will insert at the end of the list if index is greater
            push_back(item); //than the size of the list
        }
        else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* new_node = new Node(item, current->next);
            current->next = new_node;
            ++size;
        }
    }

    // Remove item at a specified index, will throw an error if input index is larger than list
    bool remove(size_t index) {
        if (index >= size) {
            return false;
        }
        if (index == 0) {
            pop_front();
        }
        else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) {
                tail = current;
            }
            delete temp;
            --size;
        }
        return true;
    }

    // Find the first occurrence of an item and returns the index of the item
    size_t find(const Item_Type& item) const {
        Node* current = head;
        size_t index = 0;
        while (current != nullptr) {
            if (current->data == item) {
                return index;
            }
            current = current->next;
            ++index;
        }
    }

    void info() const { //function for displaying front, back, and size
        if (empty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "Head: " << head->data << " ";
            cout << "Tail: " << tail->data << " ";
            cout << "Size: " << size << endl;
        }
    }
    void display() const { //function for displaying the whole list
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
