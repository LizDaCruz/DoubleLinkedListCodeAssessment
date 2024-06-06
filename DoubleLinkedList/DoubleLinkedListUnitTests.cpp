//
// Created by dacru on 6/5/2024.
//
#include "DoubleLinkedList.h"
#include <iostream>
#include <cassert>

void testAddNode() {
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    assert(list.getHead() != nullptr);
    assert(list.getHead()->data == 1);
    assert(list.getHead()->next != nullptr);
    assert(list.getHead()->next->data == 2);
    assert(list.getHead()->next->next != nullptr);
    assert(list.getHead()->next->next->data == 3);
    assert(list.getHead()->next->next->next == nullptr);

    assert(list.getTail() != nullptr);
    assert(list.getTail()->data == 3);
    assert(list.getTail()->prev != nullptr);
    assert(list.getTail()->prev->data == 2);
    assert(list.getTail()->prev->prev != nullptr);
    assert(list.getTail()->prev->prev->data == 1);
    assert(list.getTail()->prev->prev->prev == nullptr);

    std::cout << "testAddNode passed!" << std::endl;
}

void testRemoveNode() {
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    list.removeNode(2);

    assert(list.getHead() != nullptr);
    assert(list.getHead()->data == 1);
    assert(list.getHead()->next != nullptr);
    assert(list.getHead()->next->data == 3);
    assert(list.getHead()->next->next == nullptr);

    assert(list.getTail() != nullptr);
    assert(list.getTail()->data == 3);
    assert(list.getTail()->prev != nullptr);
    assert(list.getTail()->prev->data == 1);
    assert(list.getTail()->prev->prev == nullptr);

    std::cout << "testRemoveNode passed!" << std::endl;
}

void testRemoveHeadNode() {
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    list.removeNode(1);

    assert(list.getHead() != nullptr);
    assert(list.getHead()->data == 2);
    assert(list.getHead()->next != nullptr);
    assert(list.getHead()->next->data == 3);
    assert(list.getHead()->next->next == nullptr);

    assert(list.getTail() != nullptr);
    assert(list.getTail()->data == 3);
    assert(list.getTail()->prev != nullptr);
    assert(list.getTail()->prev->data == 2);
    assert(list.getTail()->prev->prev == nullptr);

    std::cout << "testRemoveHeadNode passed!" << std::endl;
}

void testRemoveTailNode() {
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    list.removeNode(3);

    assert(list.getHead() != nullptr);
    assert(list.getHead()->data == 1);
    assert(list.getHead()->next != nullptr);
    assert(list.getHead()->next->data == 2);
    assert(list.getHead()->next->next == nullptr);

    assert(list.getTail() != nullptr);
    assert(list.getTail()->data == 2);
    assert(list.getTail()->prev != nullptr);
    assert(list.getTail()->prev->data == 1);
    assert(list.getTail()->prev->prev == nullptr);

    std::cout << "testRemoveTailNode passed!" << std::endl;
}

void testMoveBack() {
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Move forward to the last node
    list.moveNext();
    list.moveNext();

    // Move back one node
    list.moveBack();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 2);

    // Move back to the head node
    list.moveBack();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 1);
    assert(list.getSelectedNode()->prev == nullptr);

    std::cout << "testMoveBack passed!" << std::endl;
}

void testMoveForward() {
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Initially selected node should be the head
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 1);

    // Move forward to the next node
    list.moveNext();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 2);

    // Move forward to the next node
    list.moveNext();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 3);

    // Try to move forward beyond the last node
    list.moveNext();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 3); // Should still be the last node

    std::cout << "testMoveForward passed!" << std::endl;
}

void testMoveBackPastHead() {
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Initially selected node should be the head
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 1);

    // Attempt to move back past the head node
    list.moveBack();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 1); // Should still be the head node

    std::cout << "testMoveBackPastHead passed!" << std::endl;
}

void testMoveForwardPastTail() {
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Initially selected node should be the head
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 1);

    // Move forward to the next node
    list.moveNext();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 2);

    // Move forward to the next node
    list.moveNext();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 3);

    // Attempt to move forward past the tail node
    list.moveNext();
    assert(list.getSelectedNode() != nullptr);
    assert(list.getSelectedNode()->data == 3); // Should still be the tail node

    std::cout << "testMoveForwardPastTail passed!" << std::endl;
}

int main() {
    //Run each test case
    testAddNode();
    testRemoveNode();
    testRemoveHeadNode();
    testRemoveTailNode();
    testMoveForward();
    testMoveBack();
    testMoveBackPastHead();
    testMoveForwardPastTail();

    //If all tests pass then this message will be seen.
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

