//
//  main.cpp
//  ERT35P3
//
//  Created by Elaina Teramoto on 10/26/17.
//  Copyright © 2017 Elaina Teramoto. All rights reserved.
//
/*
 
 if no value is written by the user then the last added value or 0 is added again.
 if there is nothing in the array and remove is called, nothing happens and the user is
 asked to do something else and the program keeps running.

 Design decisions: I chose to design my project by not using the lazy insertion because the heap 
 always needs to be in order. After each addition and removal, I have to print out the heap accoriding
 to the project. Lazy insertion would be good if i knew how many values I would be adding to the array. 

 */


#include "main.h"

//implement a heap data structure with a priority queue

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "Hello" <<endl;
    MinHeap<int> minheap1;
    string decision = "";
    char choice  =' ';
    bool quit = false;
    int addvalue =0;
    cout << "What would you like to do? \n "
        <<"a: add \n r: remove root \n q: quit the program \n";
    getline(cin, decision);
    istringstream is(decision);
    is>> choice >> addvalue;
    while (!quit)
    {
        if (choice == 'a')
        {
            minheap1.add(addvalue);
        }
            
        else if(choice == 'r')
        {
            minheap1.remove(); // removes the root node
        }
        else
        {
           if (choice == 'q')
           {
               //chooses to quit so print out the remaining heap
               quit = true;
               break;
           }
           else {
           }
        }
        cout << "What would you like to do next? \n "
            <<"a:add \n r: remove root \n q: quit the program" << endl;
        getline(cin, decision);
        istringstream is(decision);
        is>> choice >>addvalue;
    }
    
}
