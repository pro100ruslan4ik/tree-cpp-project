#pragma once

#include <iostream>
#include <algorithm>

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
        ~Tree();

        void Insert(T);
        void PrintInAscendingOrder() const;
        void Clear();
        int Height();
        Node<T>* Find(T);

    private:
        Node<T>* root;

        void InsertRecursive(Node<T>*&, T);
        void InOrderPrintRecursive(Node<T>*) const;
        void ClearRecursive(Node<T>*&);
        int HeightRecursive(Node<T>*, int) const;
        Node<T>* FindRecursive(Node<T>*, T) const;

        

};



template <typename T>
void Tree<T>::ClearRecursive(Node<T>*& node)
{
    if (node == nullptr)
        return;

    ClearRecursive(node->left);
    ClearRecursive(node->right);
    
    delete node;
    node = nullptr;
}

template <typename T>
void Tree<T>::Clear()
{
    ClearRecursive(root);
    root = nullptr;
}

template <typename T>
Tree<T>::~Tree()
{
    ClearRecursive(root);
}



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



template <typename T>
int Tree<T>::Height()
{
    return HeightRecursive(root, 0);
}

template <typename T>
int Tree<T>::HeightRecursive(Node<T>* node, int currentHeight) const
{
    if (node == nullptr)
        return currentHeight;

    return std::max(HeightRecursive(node->left, currentHeight + 1),
               HeightRecursive(node->right, currentHeight + 1));
}



template <typename T>
Node<T>* Tree<T>::Find(T value)
{
    return FindRecursive(root, value);
}

template <typename T>
Node<T>* Tree<T>::FindRecursive(Node<T>* node, T value) const
{
    if (node == nullptr || node->data == value)
        return node;

    if (value < node->data)
        return FindRecursive(node->left, value);
    else
        return FindRecursive(node->right, value);
}
