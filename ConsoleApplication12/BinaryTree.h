#pragma once
#include <iostream>

template<typename T>
class BinaryTree
{
private:
	class Node
	{
	public:
		T data;
		Node* left;
		Node* right;

		Node(T value) {
			data = value;
			left = nullptr;
			right = nullptr;
		}
	};

	Node* root;

	void insert(Node*& node, T value) {
		if (node == nullptr) {
			node = new Node(value);
		}
		else if (value < node->data) {
			insert(node->left, value);
		}
		else {
			insert(node->right, value);
		}
	}

	Node* findMin(Node* node) {
		while (node->left != nullptr) {
			node = node->left;
		}

		return node;
	}

	Node* remove(Node* node, T value) {
		if (node == nullptr) {
			return nullptr;
		}
		if (value < node->data) {
			node->left = remove(node->right, value);
		}
		else if (value > node->data) {
			node->right = remove(node->right, value);
		}
		else {
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				return nullptr;
			}
			else if (node->left == nullptr) {
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr) {
				Node* temp = node->left;
				delete node;
				return temp;
			}
			else {
				Node* temp = findMin(node->right);
				node->data = temp->data;
				node->right = remove(node->right, temp->data);
			}
		}
		return node;
	}

	void inorder(Node* node) {
		if (node != nullptr)
		{
			inorder(node->left);
			std::cout << node->data << " "; 
			inorder(node->right);
		}
	}

	void preorder(Node* node) {
		if (node != nullptr)
		{
			std::cout << node->data << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}

	void postorder(Node* node) {
		if (node != nullptr)
		{
			postorder(node->left);
			postorder(node->right);
			std::cout << node->data << " ";
		}
	}

	Node* search(Node* node, T value) {
		if (node == nullptr || node->data == value)
		{
			return node;
		}
		if (value < node->data) {
			return search(node->left, value);
		}
		else
		{
			return search(node->right, value);
		}
	}

	void clear(Node* node) {
		if (node != nullptr)
		{
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	void copy(Node*& node, Node* otherNode) {
		if (otherNode == nullptr) {
			node = nullptr;
			return;
		}
		node = new Node(otherNode->data);
		copy(node->left, otherNode->left);
		copy(node->right, otherNode->right);
	}

public:
	BinaryTree() {
		root = nullptr;
	}

	BinaryTree(const BinaryTree& other) : root(nullptr) {
		copy(root, other.root);
	}

	BinaryTree(BinaryTree&& other) noexcept : root(other.root) {
		other.root = nullptr;
	}

	BinaryTree& operator=(const BinaryTree& other) {
		if (this != &other) {
			clear(root);
			copy(root, other.root);
		}
		return *this;
	}

	~BinaryTree() {
		clear(root);
	}

	void insert(T value) {
		insert(root, value);
	}

	void remove(T value) {
		root = remove(root, value);

	}

	bool search(T value) {
		return search(root, value) != nullptr;
	}

	void inorder() {
		inorder(root);
		std::cout << std::endl;
	}

	void preorder() {
		preorder(root);
		std::cout << std::endl;
	}

	void postorder() {
		postorder(root);
		std::cout << std::endl;
	}
		
};



