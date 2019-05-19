#include "node.h"
#include <iostream>

//slist class value semantics:  copy constructor and
//  = work.

//slist class invariant:  The class represents a slist
//  list, which is a chain of nodes.  Each node holds
//  data, and each node except the last points to the next
//  node.  The last node points to NULL.

class slist
{
public:
    slist ();
    ~slist ();
    bool empty () const;
    int getSize() const;
    void prepend (const dataType& newItem);
    void append (const dataType& item);
    void proOrder(const dataType& item);
    void alpOrder(const dataType& item);
    bool remove(dataType & returnData);
    void printDEBUG() const;
    void printAux(node* curr) const;
    
private:
    //head is the address of the first node in the list
    node* head;
    
    
    
    
    
};


