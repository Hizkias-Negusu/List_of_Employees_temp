//
//  main.cpp
//  AssignmentTwo
//
//  Created by Negusu Hizkias on 2/5/17.
//  Copyright © 2017 Negusu Hizkias. All rights reserved.
//
//This Program is template that can be used to create a roster for any list of employees
//and order the employees by either Alphabetical order, Years of experience order, or by
//order entered

#include "slist.h"
#include <iostream>
using namespace std;

const string SENTINEL = "X";

////
/// main program
//
int main (void)
{
    // create three lists
    slist list0, list1, list2;
    dataType fac ;
    
    
    //Cin first prof name and years of service
    cout << "Type a name [" << SENTINEL << " to quit]: ";
    cin >> fac.name ;
    
    cout << "Enter years of service:";
    while(!(cin >> fac.years)){
        cout << "Error. You did not enter a number!";
        cin.clear(); // erase failure state
        cin.ignore(100, '\n'); //discard malignant data
    }
    
    //adds the value of the first prof into each list and loops the question until the user enters X
    while (fac.name != SENTINEL) {
        list0.append(fac);      ///list0 using dot operator to append '(fac)'
        list1.proOrder(fac);    ///list1 using dot operator to order fac by greatest years served
        list2.alpOrder(fac);    ///list2 using dot operator to order fac in alphabetical order
        
        cout << "Type another name [" << SENTINEL << " to quit]: ";
        
        cin >> fac.name;
        if (fac.name == "x" || fac.name == "X")
            break;
        
        cout << "Enter years of service:";
        while(!(cin >> fac.years)){
            cout << "Error. Must enter a number!" << endl;
            cin.clear(); //erase bad data
            cin.ignore(100,'\n'); //ignore bad data
        }
        
    }
    
    // prints each lists
    cout << endl << "Organized list: "; //Lists by order that data was entered
    list0.printDEBUG ();
    
    cout << endl << "Procession list: ";
    list1.printDEBUG ();
    
    cout << endl << "Alphabetical list: "; // Alpha order assumes that all names are capitalized
    list2.printDEBUG();
    
    
}










