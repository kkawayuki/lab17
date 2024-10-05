#include <iostream>
using namespace std;

/*
Refactor this code. The code currently is not modular at all; important code that could be reused is not contained in functions.

Rewrite the code such that it leverages functions to perform these linked list operations: adding a node to the front; adding a node to the tail; deleting a node; inserting a node; and deleting the entire linked list.

Don't forget that the coding conventions for this course have been updated and now require using function prototypes.
*/

// constant global value
const int SIZE = 7; // corresponds to the desired size

// struct
struct Node
{
    float value;
    Node *next;
};

// function prototypes
void output(Node *);           // print all
void createLinkedList(Node *&); // initialize linked list

void addNodeFront(Node *);
void addNodeTail(Node *);
void deleteNode(Node *, Node *);
void insertNode(Node *, Node *);
void deleteLinkedList(Node *, Node *);

int main()
{
    Node *head = nullptr;
    Node *current = head;
    int count = 0;

    createLinkedList(head);

    cout << "starting list: \n";
    output(head);

    deleteNode(head, current);
    insertNode(head, current);

    deleteLinkedList(head, current);

    return 0;
}

// functions --------------------------

void output(Node *hd)
{
    if (!hd)
    {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current)
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void createLinkedList(Node *&head)
{
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++)
    {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;

        // adds node at head
        if (!head)
        { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else
        { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
} // initialize linked list

void addNodeFront(Node *)
{
}

void addNodeTail(Node *)
{
}

void deleteNode(Node *head, Node *current)
{
    // deleting a node

    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry - 1); i++)
        if (i == 0)
            current = current->next;
        else
        {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current)
    { // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);
}

void insertNode(Node *head, Node *current)
{
    // insert a node
    Node *prev = head;
    int entry, val;
    int count = 1;

    current = head;
    cout << "After which node to insert 10000? " << endl;

    while (current)
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else
        {
            current = current->next;
            prev = prev->next;
        }
    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);
}

void deleteLinkedList(Node *current, Node *head)
{
    // deleting the linked list
    current = head;
    while (current)
    {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}
