
#include<bits/stdc++.h>
using namespace std;
class node  //nij teke akta structure banannor  junno ei class ta use kore ci
{
public:
    int data;
    node*nxt;


};
class LinkedList
{
    public:
    node*head;//uporer class use korbo tai pointer use korci;
    //head=NULL;
    int sz;
    LinkedList()   //Eta akta constructor .Iniatally head ke 0 kore rakbo
    {
        head=NULL;
        sz=0;
    }
    //Creates a new node with data = value and  nxt =NULL
    node* CreateNewNode(int value)//pointer use kore amra notun node create korte pari
    {
         node *newnode = new node;  //Ekane node a je memmory dorkar seta computer tar heap teke dea;
         newnode->data = value;  // kono kice pointer type er structure hole -> ei type er(->) sign use korbo
         newnode->nxt = NULL;
         return newnode;
    }
    //Insert new value at Head
    void InsertAtHead(int value)
    {

        sz++;
        node*a = CreateNewNode(value);
    if(head == NULL)
    {
      head = a;
     return ;
    }
    //If head is not NULL
    a->nxt = head;
    head = a;
    }


    //prints the Linked list
    void Traverse()
    {
     node*a =head;
     while(a!= NULL)
     {
         cout<<a->data<<" ";
         a= a->nxt;
     }
     cout<<"\n";
    }
    //Search for a single value

    int  SearchDistinctValue(int value)
    {
     node* a = head;
     int index =0 ;
     while(a!= NULL)
     {
         if(a->data ==value)
         {
             return index;
         }
         a = a->nxt;
         index++;
     }
     return -1;
    }

    //Search all possible occurrence
    void SearchAlValue(int value)
    {
      node* a = head;
     int index =0 ;
     while(a!= NULL)
     {
         if(a->data ==value)
         {
             //return index;
             cout<<value<<"is found at index " <<index<<"\n";
         }
         a = a->nxt;
         index++;
     }

    }
 int getSize()
 {
    //O(1)
    return sz;

     // O(n) order of  size of link list;
    // int sz=0;

     //node*a=head;
    //while(a!=NULL)   //Ekane jotugolu function ace shobgolu te amra jacci,So Eta O(n) a kaj kore;;   kinto amra chai O(1) a Implement korte;
     //{
        // sz++;
        // a=a->nxt;
     //}
     //return sz;

 }
 void InsertAtAnyIndex(int index,int value)
 {
     if(index<0 || index >sz)
      {
          return;
      }

        if(index==0)
     {
         InsertAtHead(value);
         return;
     }
     sz++;
     node*a =head;
     int cur_index=0;
     while(cur_index!=index-1)
     {
         a=a->nxt;
         cur_index++;
     }
     node*newnode =CreateNewNode(value);
     newnode->nxt=a->nxt;
     a->nxt=newnode;
 }
 void DeleteAtHead()
 {
     if(head ==NULL)
     {
         return;
     }
     sz--;
     node*a=head;
     head= a->nxt;
     delete a;  //Eta na likle o hoto .kinto memmory ta pore takto .As a Result Memmory waste hoto.............
 }
 void DeleteAnyIndex(int index)
 {
     if(index<0 || index>sz-1)
     {
         return;
     }
     if(index==0)
     {
         DeleteAtHead();
         return;
     }
     sz--;
     node*a =head;
     int cur_index =0;
     while(cur_index!=index-1)
     {
         a=a->nxt;
         cur_index++;
     }
     node*b=a->nxt;
     a->nxt=b->nxt;
     delete b;
 }
 void InsertAfterValue(int value,int data)
 {
     node *a =head;
     while(a!=NULL)
     {
         if(a->data==value)
         {
             break;
         }
         a=a->nxt;
     }
     if(a==NULL)
     {
         cout<<value<<" doesn't exit in linked -list.\n ";
         return ;
     }
     sz++;
     node * newnode =CreateNewNode(data);
     newnode->nxt= a->nxt;
     a->nxt = newnode;
 }

};
int main()
{
    LinkedList l;  //l dara linklist er akta object create korlam

    l.InsertAtHead(30);
     l.InsertAtHead(10);
      l.InsertAtHead(5);
      l.Traverse();

      l.InsertAfterValue(10,100);

      l.Traverse();
     cout<<l.getSize()<<" \n";
    return 0;
}

