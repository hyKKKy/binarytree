#include <iostream>
#include "SinglyList.h"
#include "BinaryTree.h"

int main()
{
    /*SinglyList<int> list;

    list.PushBack(1);
    list.PushBack(4);
    list.PushBack(41);
    list.PushBack(15);
    list.PushBack(134);
    list.PushBack(13);
    
    list.printList();

    list.popBack();
    
    list.printList();*/

    BinaryTree<int> Tree;

    Tree.insert(5);
    Tree.insert(6);
    Tree.insert(1);
    Tree.insert(3);
    Tree.insert(10);
    Tree.inorder();


    //std::cout << "Hello World!\n";
}


