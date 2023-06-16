/*
File: bintree.cpp
   
Summary: BinTree class is declared below, intended to be used as
         a binary tree. BinNode's will be used within and will be
         manipulated by the BinTree class to form a tree data
         structure. Functions defined in bintree.cpp file.
 
Test Cases: N/A
 
Author: Josue 
 
Date: 06/11/2023
  
Summary of modifications: N/A
 
Compiler: Ubuntu (g++)
 

Class implemented: BinTree (see bintree.h for documentation)
INVARIANT for the BinTree ADT:
    1.) The root pointer tht points to the root of the tree is stored
        in the private member variable 'root'

*/
#include "bintree.h"
#include <iostream> 
using std::cout;

BinTree::~BinTree(){
    makeEmpty();
}

bool BinTree::isEmpty(){
    return root == nullptr;
}

void BinTree::makeEmpty(){
    makeEmpty(root);
    return;
}

void BinTree::makeEmpty(BinNode*& subRoot){
    if(subRoot != nullptr){
        makeEmpty(subRoot->left);
        makeEmpty(subRoot->right);
        delete subRoot;
    }
    subRoot = nullptr;

    return;
}

void BinTree::insert(const int& val){
    insert(val, root);
    return;
}

void BinTree::insert(const int& val, BinNode*& subRoot){
    if(subRoot == nullptr)
        subRoot = new BinNode(val, nullptr, nullptr);
    else if(val < subRoot->data)
        insert(val, subRoot->left);
    else if(val > subRoot->data)
        insert(val, subRoot->right);
    return;
}

void BinTree::printTree(){
    if(!isEmpty())
        printTree(root);
    return;
}

void BinTree::printTree(BinNode* subRoot){
    if(subRoot == nullptr)
        return;
    printTree(subRoot->left);
    cout << subRoot->data << " ";
    printTree(subRoot->right);
    return;
}

int BinTree::getProduct(){
    return isEmpty() ? 0 : getProduct(root);
}

int BinTree::getProduct(BinNode* subRoot){
    if(subRoot == nullptr)
        return 1;
    return (subRoot->data * getProduct(subRoot->left) * getProduct(subRoot->right));
}


void BinTree::breakTree(BinTree& first, BinTree& second){
    first.root = root->left;
    second.root = root->right;

    root->left = nullptr;
    root->right = nullptr;
    return;
}

bool BinTree::operator == (BinTree& rhs){
    return identicalTrees(root, rhs.root);
}

bool BinTree::identicalTrees(BinNode* subRootOne, BinNode* subRootTwo){
    if(subRootOne == nullptr && subRootTwo == nullptr)
        return true;

    if(subRootOne != nullptr && subRootTwo != nullptr){
        return (subRootOne->data == subRootTwo->data &&
                identicalTrees(subRootOne->left, subRootTwo->left) &&
                identicalTrees(subRootTwo->right, subRootTwo->right));
    }
    
    return false;
}

void BinTree::remove(const int& val){
    remove(val);
    return;
}

void BinTree::remove(const int& val, BinNode* subRoot){
    if(subRoot == nullptr)
        return;

    if(val < subRoot->data)
        remove(val, subRoot->left);

    else if(val > subRoot->data)
        remove(val, subRoot->right);
    else if(subRoot->left != nullptr && subRoot->right != nullptr){
        subRoot->data = subRoot->right->data;
        remove(subRoot->data, subRoot->right);
    }
    else{
        BinNode* oldNode = subRoot;
        subRoot = (subRoot->left == nullptr) ? subRoot->left : subRoot->right;
        delete oldNode;
    }
    return;
}
