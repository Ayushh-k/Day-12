#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete next;
            next = nullptr;
        }
        cout << "Delete node is: " << value << endl;
    }
};

void insertAtHead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }

    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void print(node *&head, node *&tail)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *first = new node(5);
    node *head = first;
    node *tail = first;
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 7);

    print(head, tail);
    return 0;
}