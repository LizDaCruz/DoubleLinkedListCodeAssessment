//
// Created by dacru on 6/5/2024.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

// Define a Node for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class DoublyLinkedList {
private:
    Node* head;
    Node* selectedNode;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addNode(int data);
    void removeNode(int data);
    void moveNext();
    void moveBack();
    void printSelectedNode() const;
    void printLinkedList() const;
    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }
    Node* getSelectedNode() const { return selectedNode; }
};

#endif //DOUBLELINKEDLIST_H