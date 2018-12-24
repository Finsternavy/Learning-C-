#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* head;
node* tail;
node* n;

bool isPalindrome(node* head, node*tail);

int main() {

    n = new node;
    n->data = 1;
    n->prev = NULL;
    head = n;
    tail = n;

    n = new node;
    n->data = 2;
    n->prev = tail;
    tail->next = n;
    tail = n;

    n = new node;
    n->data = 3;
    n->prev = tail;
    tail->next = n;
    tail = n;

    n = new node;
    n->data = 2;
    n->prev = tail;
    tail->next = n;
    tail = n;

    n = new node;
    n->data = 1;
    n->prev = tail;
    tail->next = n;
    tail = n;

    if(isPalindrome(head, tail)){
        cout << "This list is a palindrome.";
    }else{
        cout << "This list is not a palindrome";
    }


    return 0;
}


bool isPalindrome(node* head, node* tail){

    while(head < tail)
    {
        if(head->next->data == tail->next->data)
        {
            head = head->next;
            tail = tail->prev;
        }

        else return false;
    }

    return true;
}

