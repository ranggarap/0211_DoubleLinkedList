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
// kondisi jika semua kondisi if tidak terpenuhi 
else
{
    // insert the new node in the middle or at the end 
    // set nilai current = start dan nilai previous =null
    Node *current = START; // step 1.a start from the first node
    Node *previous = NULL; // step 1.b : previous node is null initialitty
    
    // lopping selama current != null dan noMhs dari current lebih kecil dari
    while (current != NULL && current -> noMhs < newNode ->noMhs) 
    {                               // step 1.c traverse the list to find the 
        previous = current;         // step 1.d move the previous to the current
        current = current ->next;   // step 1.e move the current to the next 

        // set nilai next node baru = current dan prev node baru == previous 
        newNode -> next = current  ; //step 4 : make the next field of the new code
        newNode -> prev = previous ; //step 5 : make the previous field of the new nodes  

        // kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current -> prev = newNode; // step 6: make the previous field of the 
        }
        // kondisi jika previous tidak sama dengan null
        if (previous != NULL)
        {
            previous -> next = newNode; //step 7 make the next field of the previous 
        }
        
        // kondisi jika if previous sama dengan null 
        else
        {
            // if previous is null , means newnode is now the frist node
            START = newNode;
        }
    }
}
}
// pembuatan function search untuk mencari data
bool search (int rollNo, Node **previous ,Node ** current)
{
    *previous =NULL;
    *current  = START;
    while  (*current !=NULL && (*current) -> noMhs !=rollNo)
    {
        *previous = *current ;
        *current = (*current)-> next;
    }
    return (*current !=NULL);

} 
// pembuatan prosedur delete untuk menghapus data
void deleteNode()
{
    Node *previous , *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be delete: ";
    cin >> rollNo; // step 3: get roll number number to be delete

    if (START == NULL)
    {
        cout << "list is empty" << endl;
        return ;
    }

    current = START; // step 1 : start from the frist node
    previous = NULL;
//locate the node to be delete 
while (current !=NULL && current -> noMhs !=  rollNo)
{
    previous =current ;
    current = current ->next;
}
if (current == NULL)
{
    cout << "\033 [31mthe record with roll number " << rollNo << " not found\033[0m"<< endl;
    return;
}
// node to be deleted in the first node
if (current = START)
{
    START = START ->next;// step 2:update the START pointer
    if (START !=NULL)
    {
        START -> prev =NULL;
    }
}
else 
{
    // node to be delected is not the frist node 
    previous ->next =current ->next;
    if (current-> next != NULL)
    {// if there a successor ,update its prev pointer
            current -> next -> prev =previous ;
        }
    }
    //release the memory of the node marked as current 
    delete current ;
    cout <<"\x1b[32mRecord wiyh roll number" << rollNo << "delete\x1b[0m" << endl;
}

// method untuk mengecek apakah list kosong
bool listempty()
{
    return (START == NULL );
}

void traverse()
{
    
        if(listempty())
        {
            cout << "\nlist kosong\n";
        }
        else
        {
            cout << "\nData di dalam list adalah;\n";
            Node *currentNode =START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                Node*currentNode =START;
                while (currentNode !=NULL)
                {
                    cout << currentNode->noMhs << endl;
                    currentNode = currentNode->next;
                }
                
            }
            cout <<endl;
        }
}

//prosedur traverse retraverse 
void retraverse()
    {
        if(listempty())
        {
            cout << "\nlist empty\n";
        }
        else
        {
            cout << "\nRecord in descending order of roll number are:" <<endl;
            Node *currentNode =START;
            while (currentNode != NULL)
            currentNode = currentNode->next;
             while (currentNode !=NULL)
            {
                cout << currentNode ->noMhs << " " << currentNode-> name << endl;
                currentNode = currentNode->prev;
                
            }
           
        } 
    }
//prosedur untuk mencar data dan menampilkan  dan menampilkan data yg akan di cari
void searchData()
{
    if (listempty()== true )
    {
        cout << "\nList is empty"  <<endl;
    }
Node *prev, *curr;
prev = curr = NULL;
cout << "\nEnter the roll nember of the student whose record yo want to search :";
int num ;
cin >> num ;
if (search (num, & prev, & curr) ==false )
    cout <<"\nRecord the not found " << endl;
    else 
    {
        cout << "\nRecord found "<< endl;
        cout << "\nRoll number :" << curr ->noMhs << endl;
        cout <<"\nName:" << curr -> name << endl;
    }
}
int main()
{   

    while (true)
    {
         try
        { 
        cout << endl
            <<"Menu";
        cout << endl
            <<"1. menambahkan data ke dalam list"<< endl;
        cout << "2.menghapus data dari dalam list" << endl;
        cout << "3. menampilkan semua data dari list "<<endl;
        cout << "4.mencari data dalam list "<< endl;
        cout << "5. keluar"<< endl;
        cout << endl
            << "masukan Pilihan (1-5):";
            char ch;
            cin >> ch;
                
                        switch (ch)
                        {
                            case '1':
                            addNode ();
                            break;
                            case '2':
                            deleteNode ();
                            break;
                            case '3':
                            traverse();
                            break;
                            case '4':
                            retraverse();
                            break;
                            case '5':
                            searchData();
                            break;
                            case '6':
                            return 0;
                            default :
                            cout << "\nInvalid option" << endl;
                            break;

                        }
                        