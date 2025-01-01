#include <iostream>
#include "tree.h"

//TODO: Метод Find() 
//TODO: Метод Remove() 
//TODO: Метод Contains() 
//TODO: Метод Size() 
//TODO: Метод IsEmpty() 
//TODO: Метод Max() 
//TODO: Метод Min() 
//TODO: Метод IsBalanced() 
//TODO: Метод Merge() - соединить c другим деревом 
//TODO: Метод Balance() - сбалансировать дерево 
//TODO: Метод Split() - разделить дерево 
//TODO: Организовать удаление сложных типов T в деструкторе


int main() 
{
    std::cout << "Writing tree..." << std::endl;

    Tree<int> tree; 

    tree.Insert(3);
    tree.Insert(2);
    tree.Insert(543);
    tree.Insert(1);

    tree.PrintInAscendingOrder();

    tree.Clear();

    tree.Insert(-2);
    tree.Insert(-6);
    tree.Insert(-1);

    tree.PrintInAscendingOrder();

    return 0;
}

