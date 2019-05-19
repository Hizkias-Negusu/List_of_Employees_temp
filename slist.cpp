#include "slist.h"
//Negusu Hizkias Assignment 2

slist::slist ()         //Default constructor
{
    
    head = NULL;
}

slist::~slist ()
{
    //post-condition:  All nodes in the list are deleted.
    
    node* temp;
    
    while (head != NULL)
    {
        temp = head;
        
        head = head->getNext ();
        
        delete temp;
    }
    
    head = NULL;
    
}




bool slist::empty () const
{
    
    return (head==NULL);
}





int slist::getSize() const
{
    node* temp=head;
    int count=0;
    
    while (temp!=NULL)
    {
        temp=temp->getNext();
        count++;
    }
    return count;
    
    
}


void slist::prepend (const dataType& newItem)
{
    
    node *temp=new node(newItem);
    temp->setNext(head);
    head=temp;
    
}

// Inserts the new item to the front of the list
void slist::append(const dataType& item){
    if (head == NULL)
        prepend(item);
    else{
        node *curr = head;
        node *temp2 = new node(item);
        while( curr->getNext() != NULL){
            curr = curr->getNext();
        }
        curr->setNext(temp2);
        temp2->setNext(NULL);
    }
}

//Orders the list in order of most years and less years
void slist::proOrder(const dataType& item){
    node *curr = head;
    node *temp2 = new node(item);
    
    if (head == NULL)
        prepend(item);
    else if ( curr->getData().years > temp2->getData().years) {
        
        while(curr->getNext() != NULL && temp2->getData().years < curr->getData().years){
            curr = curr->getNext();
        }
        node * temp3 = curr->getNext();
        curr->setNext(temp2);
        temp2->setNext(temp3);
    }
    else
        prepend(item);
    
    
}

//Orders the list in alphabetical orders
void slist::alpOrder(const dataType& item){
    node *curr = head;
    node *temp2 = new node(item);
    
    if (head == NULL)
        prepend(item);
    else if (curr->getData().name < temp2->getData().name){
        while (curr->getNext() != NULL && temp2->getData().name < curr->getData().name){
            curr = curr->getNext();
        }
        node * temp3 = curr->getNext();
        curr->setNext(temp2);
        temp2->setNext(temp3);
    }
    else
        prepend(item);
}





//grabs the first element in the list and returns the data stored in that node
//it returns true or false indicating whether or not the remove was successful.  Thus, if
//the list is empty, it returns false, otherwise it returns true;
bool slist::remove(dataType & returnData)
{
    if (head==NULL)
        return false;
    //else will only do this code if it doesn't return
    returnData=head->getData();
    node *tmp=head;
    head=head->getNext();
    delete tmp;
    return true;
}

void slist::printDEBUG() const
{
    node *temp=head;
    if (temp==NULL)
    {
        cout<<"Empty List"<<endl;
    }
    else
    {
        while (temp!=NULL)
        {
            dataType mydata=temp->getData();
            cout<<mydata.name<<" ";
            cout<<mydata.years;
            cout<< " years of experience.";
            cout<<endl;
            temp=temp->getNext();
        }
        
    }
}
