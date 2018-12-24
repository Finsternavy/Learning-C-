#include <iostream>
#include <vector>
using namespace std;

// Node struct
struct Node {
    int data;
    Node* next;
};

// Print linked list
void printList(Node* head)
{
    Node* ptr = head;
    while (ptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "null\n";
}

// Insert node at beginning of list
void push(Node* &head, int data)
{
    Node* node = new Node();
    node->data = data;
    node->next = head;

    head = node;
}

// Reverse list
void reverse(Node* &head)
{
    Node* result = nullptr;
    Node* current = head;

    //iterate while not at the end of the list
    while (current != nullptr)
    {
        //move the next pointer
        Node* next = current->next;

        // move the current to result
        current->next = result;
        result = current;

        // process next node
        current = next;
    }

    // fix head pointer
    head = result;
}

// Recursive function to check if two linked lists are equal or not
bool compare(Node* a, Node* b)
{
    // see if both lists are empty
    if (a == nullptr && b == nullptr)
        return true;

    return a && b && (a->data == b->data) && compare(a->next, b->next);
}

// splits the list in the middle
Node* findMiddle(Node* head, bool &odd)
{
    Node* prev = nullptr;
    Node *slow = head, *fast = head;

    //move through the list until the end of list
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // fast still points to last node
    if (fast)
        odd = true;

    // make next of prev node null
    prev->next = nullptr;

    // return mid node
    return slow;
}

// check if linked list is palindrome or not
bool checkPalindromeSingle(Node* head)
{
    // base case
    if (head == nullptr)
        return true;

    bool odd = false;

    // find second half of linked list
    Node* mid = findMiddle(head, odd);

    // if number of nodes is odd, advance mid
    if (odd)
        mid = mid->next;

    // reverse the second half
    reverse(mid);

    // compare first and second half
    return compare(head, mid);
}

int main()
{

    vector<int> keys = { 1, 2, 3, 2, 1, 5};

    Node* head = nullptr;
    for (int i = keys.size() - 1; i >= 0; i--)
        push(head, keys[i]);

    if (checkPalindromeSingle(head))
        cout << "Linked list is Palindrome";
    else
        cout << "Linked list is not Palindrome";

    return 0;
}