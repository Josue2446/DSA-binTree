/*
File: bintree.h

Summary: BinTree class is declared below, intended to be used as
         a binary tree. BinNode's will be used within and will be
         manipulated by the BinTree class to form a tree data
         structure. Functions defined in bintree.cpp file.

Test Cases: N/A

Author: Josue 

Date: 06/11/2023

Summary of modifications: N/A

Compiler: Ubuntu (g++)

Constructor:
    Bintree():
        postcondition: sets root to nullptr

Destructor:
    ~BinTree():
        postcondition: calls makeEmpty() function which clears all
                       the nodes and frees up taken memory

FUNCTIONS:
    void makeEmpty():
        postcondition: gets rid of all the binNodes.

    bool isEmpty():
        postcondition: returns boolean value depending if there are any
                       binNode's in the tree.

    void insert(const int& val):
        postcondition: new binNode is inserted into the tree.

    void printTree():
        postcondition: contents of the tree are displayed.

    int getProduct():
        postcondition: returns product of all binNode values.

    void remove(const int& val):
        postcondition: if a node with the value is found, it will be removed
                       from the BinTree object

    void remove(const int& val, BinNode* subRoot):
        postcondition: if a node with the value is found, it will be removed
                       from the BinTree object

ADDITIONAL NOTES:
    1.) Each each of the above functions has a private member function that
        is exactly the same, just with a parameter. The user can call
        the public ones, the private ones are called within the public ones
        since the user won't have access to certain aspects of the class.


*/

#ifndef BINTREE_H
#define BINTREE_H

#include <cstdlib>
#include <iostream>

class BinTree {
    public:
        BinTree() : root{nullptr}{}
        ~BinTree();

        void makeEmpty();
        bool isEmpty();
        void insert(const int& val);
        void printTree();
        void remove(const int& val);

        // additional functions
        int getProduct();
        //BinTree reversedTree()i;
        void breakTree(BinTree& first, BinTree& second);
        bool operator == (BinTree& rhs);
    private:
        struct BinNode{
            int data;
            BinNode* left;
            BinNode* right;

            BinNode(const int& data_ = int(), BinNode* left_ = nullptr,
                    BinNode* right_ = nullptr) 
                    : data{data_}, left{left_}, right{right_}{}
        };

        BinNode* root;
        
        void remove(const int& val, BinNode* subRoot);
        void makeEmpty(BinNode*& subRoot);
        void insert(const int& val, BinNode*& subRoot);
        void printTree(BinNode* subRoot);
        int getProduct(BinNode* subRoot);
        bool identicalTrees(BinNode* subRootOne, BinNode* subRootTwo);
        
};

#endif // BINTREE_H

