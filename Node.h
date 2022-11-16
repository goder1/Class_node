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
};

class Node
{
    Node_elem* Pnode;

public:

    Node()
    {
        Pnode = nullptr;
    }

    Node(int n)
    {
        if (n == 0)
        {
            Pnode = nullptr;
        }
        else
        {
            Pnode = new Node_elem;
            Node_elem* ptr = Pnode;
            for (int i = 0; i < n; i++)
            {
                cin >> ptr->a;
                if(i + 1 < n)
                {
                    ptr->next = new Node_elem;
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

    void Push_front(int elem)
    {
        Node_elem* ptr = new Node_elem;
        ptr->a = elem;
        ptr->next = Pnode;
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
        ptr = ptr->next;
        ptr->a = elem;
        ptr->next = nullptr;
    }

    void Pop_front()
    {
        if (Pnode->next != nullptr)
        {
        Node_elem* ptr = Pnode->next;
        delete Pnode;
        Pnode = ptr;
        }
        else
        {
            delete Pnode;
            Pnode = nullptr;
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
        }
    }

    void Insert(int x, int j)
    {
        Node_elem* ptr = Pnode;
        int counter = 0;
        if (j == 0)
        {
            Node_elem* ptr_2 = new Node_elem;
            ptr_2->a = x;
            ptr_2->next = Pnode;
            Pnode = ptr_2;
        }
        else
        {
            while (ptr->next != nullptr)
            {
                if (counter != j - 1)
                {
                    ptr = ptr->next;
                    counter++;
                }
                else
                {
                    break;
                }
            }
            Node_elem* ptr_2 = new Node_elem;
            ptr_2->a = x;
            ptr_2->next = ptr->next;
            ptr->next = ptr_2;
        }
    }

    void Delete(int j)
    {
        if (j == 0)
        {
            if (Pnode->next != nullptr)
            {
                Node_elem* ptr = Pnode->next;
                delete Pnode;
                Pnode = ptr;
            }
            else
            {
                delete Pnode;
                Pnode = nullptr;
            }
        }
        else
        {
            Node_elem* ptr = Pnode;
            int counter = 0;
            while (ptr->next != nullptr)
            {
                if (counter != j - 1)
                {
                    ptr = ptr->next;
                    counter++;
                }
                else
                {
                    break;
                }
            }
            if (ptr->next->next != nullptr)
            {
                Node_elem* ptr_2 = new Node_elem;
                ptr_2->a = ptr->next->next->a;
                ptr_2->next = ptr->next->next->next;
                delete ptr->next;
                ptr->next = ptr_2;
            }
            else
            {
                delete ptr->next;
                ptr->next = nullptr;
            }
        }
    }

    int Search(int x)
    {
        Node_elem* ptr = Pnode;
        if (ptr->next == nullptr)
        {
            if (x == ptr->a)
            {
                return 0;
            }
            return -1;
        }
        int index = -1;
        while (ptr->next != nullptr)
        {
            index++;
            if (ptr->a == x)
            {
                return index;
            }
            ptr = ptr->next;
        }
        return index;
    }


    void Delete_value(int x)
    {
        Node_elem* ptr = Pnode;

        if (ptr->next == nullptr && x == ptr->a)
        {
            delete Pnode;
            Pnode = nullptr;
        }
        else if (ptr->a == x)
        {
            ptr = Pnode->next;
            delete Pnode;
            Pnode = ptr;
        }
        else
        {
            int del = 0;
            while (ptr->next->next != nullptr)
            {
                if (ptr->next->a == x)
                {
                    Node_elem* ptr_2 = new Node_elem;
                    ptr_2->a = ptr->next->next->a;
                    ptr_2->next = ptr->next->next->next;
                    delete ptr->next;
                    ptr->next = ptr_2;
                    del = 1;
                    break;
                }
                ptr = ptr->next;
            }
            if (del == 0 && ptr->next->a == x)
            {
                delete ptr->next;
                ptr->next = nullptr;
            }
        }
    }

    Node operator=(Node node)
    {
        Node A;
        A.Pnode = node.Pnode;
        return A;
    }

    Node operator+(Node node)
    {
        Node A;
        A.Pnode = new Node_elem;
        Node_elem* ptrA = A.Pnode;
        Node_elem* ptr = Pnode;
        while (ptr->next != nullptr)
        {
            ptrA->a = ptr->a;
            ptr = ptr->next;
            ptrA->next = new Node_elem;
            ptrA = ptrA->next;
        }
        ptrA->a = ptr->a;
        ptrA->next = new Node_elem;
        ptrA = ptrA->next;
        ptr = node.Pnode;
        while (ptr->next != nullptr)
        {
            ptrA->a = ptr->a;
            ptr = ptr->next;
            ptrA->next = new Node_elem;
            ptrA = ptrA->next;
        }
        ptrA->a = ptr->a;
        ptrA->next = nullptr;

        return A;
    }



    /*void print(ostream &out)
    {
        for (Node_elem* i = A.Pnode; i != nullptr; i = i.next)
        {
            out << i.a << " ";
        }
    }*/


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

    //friend istream& operator>>(istream&, Matrix<Type>&);
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

/*template<typename T>
istream& operator>>(istream& in, Node& A) {
    A.input(in);
    for (int i = 0; i < A.a ; i++)
    {
        A.matrix[i] = new T [A.b];
    }
    for (int i = 0; i < A.a; i++)
    {
        for (int j = 0; j < A.b; j++)
        {
        in >> A.matrix[i][j];
        }
    }
    return in;
}*/

#endif
