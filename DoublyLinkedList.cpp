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