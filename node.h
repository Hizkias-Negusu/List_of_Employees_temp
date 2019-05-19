
#include <string>

using namespace std;


#ifndef NODE_H
#define NODE_H


struct facType {
    std::string name;
    int years;
};


typedef facType dataType;


//Node class value semantics:  No copy constructor,
//  system provided = functionality.

//Node class invariant:  A node holds a datum and a pointer
//  to another node.  The intent is to use the node as the
//  basic building block for a linked list:  a chain of
//  nodes.



class node
{
public:
    node (dataType);
    
    void setData (dataType);
    void setNext (node*);
    
    dataType getData () const;
    node* getNext () const;
    
private:
    node* next;
    dataType data;
};

#endif
