//
// Created by dacru on 6/5/2024.
//
#include <iostream>
#include "DoubleLinkedList.h"

    // Constructor
    DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), selectedNode(nullptr) {}

    // Destructor to clean up memory
    DoublyLinkedList::~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function to add a node at the end
    void DoublyLinkedList::addNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;

        if (head == nullptr) {
            head = newNode;
            selectedNode = newNode;
        }
    }

    // Function to remove a node by value
    void DoublyLinkedList::removeNode(int data) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == data) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;

                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                std::cout << "Successfully removed node with data " << data << "." << std::endl;
                return;
            }
            current = current->next;
        }
        std::cout << "Node with data " << data << " not found." << std::endl;
    }

    //Transverse forward in list
    void DoublyLinkedList::moveNext() {
        if (selectedNode != nullptr && selectedNode->next != nullptr) {
            selectedNode = selectedNode->next;
            std::cout << "Moving forward one node." << std::endl;
        } else {
            std::cout << "Cannot move forward, already at the end or no node selected." << std::endl;
        }
    }
    void DoublyLinkedList::moveBack() {
        if (selectedNode != nullptr && selectedNode->prev != nullptr) {
            selectedNode = selectedNode->prev;
            std::cout << "Moving back one node." << std::endl;
        } else {
            std::cout << "Cannot move back, already at the beginning or no node selected." << std::endl;
        }
    }
    void DoublyLinkedList::printSelectedNode() const {
        if (selectedNode != nullptr) {
            std::cout << "Current selected node data: " << selectedNode->data << "." << std::endl;
        } else {
            std::cout << "No node is currently selected." << std::endl;
        }
    }

    // Function to print the list forward
    void DoublyLinkedList::printLinkedList() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }


//This is commented out as to use the main within the Unit tests.
//Please switch the commented main if you would like to run the original main used
//to build out the requested functionality.

// int main() {
//     DoublyLinkedList list;
//
//     // Add nodes to the linked list
//     list.addNode(1);
//     list.addNode(2);
//     list.addNode(3);
//     list.addNode(4);
//     list.addNode(5);
//
//     std::cout << "List printed: "  << std::endl;
//     list.printLinkedList();
//
//     // Remove node
//     std::cout << "Removing node with data 3." << std::endl;
//     list.removeNode(3);
//
//     std::cout << "List printed after removal: " << std::endl;
//     list.printLinkedList();
//
//     //Print current selected Node
//     list.printSelectedNode();
//
//     //Transverse List forward
//     list.moveNext();
//     list.printSelectedNode();
//
//     //Transverse List back
//     list.moveBack();
//     list.printSelectedNode();
//
//     return 0;
// }
