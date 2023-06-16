/*
File: driver.cpp
   
Summary: Driver file to test BinTree class using binNode's, both of which
         are declared in bintree.h

Test Cases: used valgrind to check for memory leaks, output:

            HEAP SUMMARY:
                in use at exit: 0 bytes in 0 blocks
                total heap usage: 9 allocs, 9 frees, 73,869 bytes allocated

            All heap blocks were freed -- no leaks are possible

            For lists of detected and suppressed errors, rerun with: -s
            ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Author: Josue 
  
Date: 06/11/2023
 
Summary of modifications: N/A
 
Compiler: Ubuntu (g++)

*/

#include <iostream>
#include "bintree.h"

using std::cout;
using std::endl;

int main(){

    BinTree b1;
    BinTree b2;
    BinTree b3;

    b1.insert(15);
    b1.insert(25);
    b1.insert(5);
    b1.insert(20);
    b1.insert(10);
    b1.insert(30);
    b1.insert(3);

    cout << "Original tree: ";
    b1.printTree();    

    b1.breakTree(b2, b3);

    cout << "\nLeft sub tree: ";
    b2.printTree();

    cout << "\nRight sub tree: ";
    b3.printTree();
    cout << endl;

    cout << "left and right trees are ";
    b2 == b3 ? cout << "identical" : cout << "NOT identical";
    cout << endl;

    cout << "is b2 equal to b2? ";
    b2 == b2 ? cout << "yes" : cout << "no";
    cout << endl;
    
    return 0;
}
