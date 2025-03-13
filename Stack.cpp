#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data{val}, next{nullptr}
    {
    }
};

class Stack
{
private:
    Node *head;   // Points to top element of stack.
    int num;      // Number of elements (index-style tracking).
    int capacity; // Fixed size limit (resized when full).

public:
    Stack(int initialCapacity) : head{nullptr}
    { // You can set any initial size.
        num = 0;
        capacity = initialCapacity;
    }

    ~Stack()
    {
        delete head;
    }
    void push(int x)
    {
        if (head == nullptr)
        {
            head = new Node(x);
            num++;
            return;
        }
        if (num = capacity)
        {
            increaseCapacity();
        }
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        num++;
        return;
    }

    int pop()
    {
        if (head == nullptr)
            return -1;

        Node *tmp = head;

        int data = head->data;
        head = head->next;
        delete tmp;
        return data;
    }
    void print()
    {
        if (head == nullptr)
        {
            return;
        }
        auto temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data;
            temp = temp->next;
        }
        return;
    }
    int peek()
    {
        if (head == nullptr)
        {
            return -1;
        }
        return head->data;
    }

    bool isEmpty()
    {
        return num < 0;
    }

    void increaseCapacity()
    {
        capacity = capacity * 2;
    }

    bool deleteElement(int val)
    {
        if (head == nullptr)
    {
        return false;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {

            if (temp == head) // if the value is at head
            {

                if (head->next != nullptr)
                {
                    Node *temp2 = head;
                    head = head->next;
                    delete temp2;
                    return true;
                }
                else
                {   
                    delete head;
                    head = nullptr;
                    
                    return true;
                }
            }
           else
            {
                Node *beforelast = head;
                while (beforelast->next->next != nullptr)
                {
                    beforelast = beforelast->next;
                }
                delete beforelast->next;
                beforelast->next =nullptr;
                return true;
            }
            Node *temp4 = temp;
            temp = temp->next;
            delete(temp4);
        }
        temp = temp->next; // if not val move forward
    }
    return false;
    }
};

int main()
{
    Stack *st = new Stack(10);
    st->push(5);
    st->push(6);

    st->deleteElement(5);
    st->print();

    return 0;
}
