#pragma once
#include <iostream>

template<typename T>
class SinglyList {
private:
    struct Node {
        T value;
        Node* next;

        Node(T val, Node* next = nullptr) : value(val), next(next) {}
    };

    Node* head;

    void Copy(const SinglyList& other) {
        if (other.head == nullptr) {
            head = nullptr;
            return;
        }

        head = new Node{ other.head->value, nullptr };
        Node* current = head;
        Node* otherCurrent = other.head->next;

        while (otherCurrent != nullptr) {
            current->next = new Node{ otherCurrent->value, nullptr };
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

public:
    SinglyList() : head(nullptr) {}

    SinglyList(const SinglyList& other) {
        head = nullptr;
        Copy(other);
    }

    SinglyList(SinglyList&& other) noexcept {
        head = other.head;
        other.head = nullptr;
    }

    SinglyList& operator=(const SinglyList& other) {
        if (this != &other) {
            clear();
            Copy(other);
        }
        return *this;
    }

    ~SinglyList() {
        clear();
    }

    void PushFront(const T& value) {
        Node* new_node = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }

    void PushBack(const T& value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void Remove(const T& value) {
        Node* previous = nullptr;
        Node* current = head;

        while (current != nullptr) {
            if (current->value == value) {
                if (previous != nullptr) {
                    previous->next = current->next;
                }
                else {
                    head = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void popFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void popBack() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void printList() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void clear() {
        while (head) {
            popFront();
        }
    }
};