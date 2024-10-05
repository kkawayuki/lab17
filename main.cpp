// COMSC-210 | lab 17 | Kent Kawashima
#include <iostream>
using namespace std;

// constant global value
const int SIZE = 7; // corresponds to the desired size

// struct
struct Node
{
    float value;
    Node *next;
};

// function prototypes
void output(Node *);            // print all
void createLinkedList(Node *&); // initialize linked list
void addNodeFront(Node *&);
void addNodeTail(Node *, Node *);
void deleteNode(Node *, Node *);
void insertNode(Node *, Node *);
void deleteLinkedList(Node *, Node *);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    Node *head = nullptr;
    Node *current = head;

    createLinkedList(head); //create intial linked list

    cout << "starting list: \n";
    output(head); //output linked list

    addNodeFront(head);
    addNodeTail(head,current);
    deleteNode(head, current); //delete node of user specificaiton 
    insertNode(head, current);
    deleteLinkedList(head, current); //delete linked list to avoid memory leak

    return 0;
}


/************************************************
 * Function: Takes in the pointer to the head of 
 * the array and iterates through it, printing 
 * the float value at each node, formatted. 
 *
 * Parameters: *hd, the pointer to the head of the
 * linked list, (starting point of iteration)
 * Return: NONE
 ************************************************/
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

/************************************************
 * Function: Takes in the pointer to the head of 
 * the array by reference, so it's alterable
 * (alternatively could have returntype be node)
 * then intializes each Node of the linked list. 
 *
 * Parameters: *&head, the pointer to the head of the
 * linked list, (starting point of Node creation)
 * Return: NONE
 ************************************************/
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
} 

/************************************************
 * Function: Adds a node to the forefront of the
 * linked list, value specified by user input.
 *
 * Parameters: *&head, the pointer to the head of the
 * linked list, (starting point of Node creation)
 * Return: NONE
 ************************************************/
void addNodeFront(Node *&head)
{
    Node *prev = head;
    int val;

    cout << "value to add to front: ";
    cin >> val;

    Node *newnode = new Node;
    newnode->value = val; // assigns user-inputted value

    newnode->next = head; 
    head = newnode;

    output(head); // show changes
}

/************************************************
 * Function: Iterates to the end of the linked
 * list, then adds a value specified by user input
 *
 * Parameters: 
 * *head, the pointer to the head of the
 * linked list, (starting point of Node creation)
 * *current, a secondary pointer used to iterate
 * through the linked list to the end (where the
 * user-inputted value is to be saved.)
 * Return: NONE
 ************************************************/
void addNodeTail(Node *head, Node *current)
{
    int val;
    int count = 1;

    current = head;

    cout << "value to add to back: ";
    cin >> val;

    while(current->next != nullptr)
    {
        current = current->next;
    }
    // insert a node between prev and current after iterated to last node (tail)
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = nullptr;

    current->next = newnode;

    output(head); // output changes
}

/************************************************
 * Function: Iterates a specified member of the 
 * linked list, removes it, and 
 *
 * Parameters: 
 * *head, the pointer to the head of the
 * linked list, (starting point of Node creation)
 * *current, a secondary pointer used to iterate
 * through the linked list to the end (where the
 * user-inputted value is to be saved.)
 * Return: NONE
 ************************************************/
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

    // has built-in print
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
    output(head); //validate list deletion
}
