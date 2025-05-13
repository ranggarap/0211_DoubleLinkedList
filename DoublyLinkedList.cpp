#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedlist
struct Node
{
    //dekralasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    // deklarasi pointer next dan pref untuk penunjukan data sebelum dan sesudah
    Node *next;
    Node *prev;
};

// deklarasi pointer Start dan pemberian nilai
Node *START =NULL;

// deklarasi prosedu addnote
void addnote()
{
    // pembuatan node dan pemberian value untuk data noMhs dan name
    Node *newNode = new Node(); // step 1 buat node baru
    cout << "\nEnter the roll number of the student:";
    cin >> newNode ->noMhs ;// assign value to the data field of the new node
    cout << "\nEnter the name of the student:";
    cin >> newNode -> name;//assign value to the data field of th
    
    //insert the new node in the list
    // kondisi jika star = null atau noMhs node baru <= noMhs start
    if (START == NULL || newNode -> noMhs <= START -> noMhs )
    {
        //STEP 2 :insert the new node at the beggining 
        // kondisi jika start tidak kosong dan noMhs node baru sama dengan noMhs
        if (START !=NULL && newNode  -> noMhs==START -> noMhs)
        {
            cout << "\033 [31mDuplicate roll number not allowed \033[0m" <<endl;
            return;
        }
        // if the list is empty ,make the new node the start
        newNode-> next = START; // step3 : make the new point to the first node
        // kondisi jika start tidak memiliki nilai atau tidak kosong 
        if (START != NULL)
        {
            START -> prev =newNode;// step 4 make the first node to the node
        }
        // memberi nilai prev = null dan start = node baru
        
        newNode -> prev = NULL ; //step 5 make the new node point to NUll
        START = newNode; // step 6 make the new node the frist node 
    }


} 