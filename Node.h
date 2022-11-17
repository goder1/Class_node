#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>
using namespace std;


struct Node_elem
{
    int a;
    Node_elem* next;
    Node_elem* prev;
};

class Node
{
    Node_elem* Pnode;
    Node_elem* current;
public:

    Node()
    {
        Pnode = nullptr;
        current = nullptr;
    }

    Node(int n)
    {
        if (n == 0)
        {
            Pnode = nullptr;
            current = nullptr;
        }
        else
        {
            Pnode = new Node_elem;
            current = Pnode;
            Node_elem* ptr = Pnode;
            ptr->prev = nullptr;
            for (int i = 0; i < n; i++)
            {
                cin >> ptr->a;
                if(i + 1 < n)
                {
                    ptr->next = new Node_elem;
                    ptr->next->prev = ptr;
                    ptr = ptr->next;
                }
            }
            ptr->next = nullptr;
        }
    }

    bool Is_Empty()
    {
        if (Pnode == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Move_current_forward()
    {
        current = current->next;
    }

    void Move_current_backward()
    {
        current = current->prev;
    }

    void Push_front(int elem)
    {
        Node_elem* ptr = new Node_elem;
        ptr->a = elem;
        ptr->next = Pnode;
        ptr->prev = nullptr;
        Pnode->prev = ptr;
        Pnode = ptr;
    }

    void Push_back(int elem)
    {
        Node_elem* ptr = Pnode;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = new Node_elem;
        ptr->next->prev = ptr;
        ptr = ptr->next;
        ptr->a = elem;
        ptr->next = nullptr;
    }

    void Pop_front()
    {
        if (Pnode->next != nullptr)
        {
        Node_elem* ptr = Pnode->next;
        ptr->prev = nullptr;
        delete Pnode;
        Pnode = ptr;
        }
        else
        {
            delete Pnode;
            Pnode = nullptr;
            current = nullptr;
        }
    }

    void Pop_back()
    {
        if (Pnode->next != nullptr)
        {
            Node_elem* ptr = Pnode;
            while (ptr->next->next != nullptr)
            {
                ptr = ptr->next;
            }
            delete ptr->next;
            ptr->next = nullptr;
        }
        else
        {
            delete Pnode;
            Pnode = nullptr;
            current = nullptr;
        }
    }

    void Insert_current(int x)
    {
        if(current->prev != nullptr)
        {
            current->prev->next = new Node_elem;
            current->prev->next->a = x;
            current->prev->next->next = current;
            current->prev = current->prev->next;
        }
        else
        {
            Node_elem* ptr = new Node_elem;
            ptr->a = x;
            ptr->next = Pnode;
            ptr->prev = nullptr;
            Pnode->prev = ptr;
            Pnode = ptr;
        }
    }

    void Delete_current()
    {
        Node_elem* ptr1 = current->prev;
        Node_elem* ptr2 = current->next;
        delete current;
        ptr1->next = ptr2;
        ptr2->prev = ptr1;
        current = ptr1;
    }


    Node operator=(Node node)
    {
        Node A;
        A.Pnode = node.Pnode;
        return A;
    }

    ~Node()
    {
        Node_elem* ptr = Pnode;
        while (ptr != nullptr)
        {
            ptr = ptr->next;
            delete Pnode;
            Pnode = ptr;
        }
    }

    friend ostream& operator<<(ostream&, const Node&);
};


ostream& operator<<(ostream& out, const Node& A)
{
    for (Node_elem* i = A.Pnode; i != nullptr; i = i->next)
    {
        out << i->a << " ";
    }
    out << endl;
    return out;
}


#endif
