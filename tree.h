#pragma once

#include <iostream>

template <typename T>
class Node
{
    public:
        T data;
        Node* left;
        Node* right;
        
        Node(T value) : data(value), left(nullptr), right(nullptr){}
};

template <typename T>
class Tree
{


    public:
        Tree() : root(nullptr){}

        void Insert(T value);
        void PrintInAscendingOrder() const;

    private:
        Node<T>* root;

        void InsertRecursive(Node<T>*&, T);
        void InOrderPrintRecursive(Node<T>*) const;

};

template <typename T>
void Tree<T>::Insert(T value)
{
    InsertRecursive(root, value);
}

template <typename T>
void Tree<T>::InsertRecursive(Node<T>*& node, T value)
{
    if (node == nullptr)
    {
        node = new Node<T>(value);
        return;
    }

    if (value <= node->data)
        InsertRecursive(node->left, value);
    else  
        InsertRecursive(node->right, value);
}

template <typename T>
void Tree<T>::PrintInAscendingOrder() const
{
    InOrderPrintRecursive(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::InOrderPrintRecursive(Node<T>* node) const
{
    if (node == nullptr)
        return;

    InOrderPrintRecursive(node->left);

    std::cout << node->data << " ";

    InOrderPrintRecursive(node->right);
}
