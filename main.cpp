#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include "Node.h"
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int a,b,c,d;
    string w;
    string command = "";
    cout << "Enter the amount of numbers in the node:\n";
    int n;
    cin >> n;
    cout << "Enter the numbers:\n";
    Node node(n);
    int current;
    if(n)
    {
        current = 0;
    }
    else
    {
        current = -1;
    }
    //cout << node;
    system("clear");
    while (command != "STOP")
    {
        cout << node << endl;
        cout << "Current elem is: "<<current<< endl << endl;
        cout << "1.Push_front\n2.Push_back\n3.Pop_front\n4.Pop_back\n5.Insert num\n6.Delete num\n7.Is_empty?\n8.Move current forward\n9.Move current backward\n10.STOP\n\n Choose the command:\n";
        cin >> w;
        if(int(w[0]) - 48 == 1 && w.size() == 1)
        {
            cout << "Enter the number which you want to insert:\n";
            int elem;
            cin >> elem;
            node.Push_front(elem);
            current++;

        }


        else if(int(w[0]) - 48 == 2 && w.size() == 1)
        {
            cout << "Enter the number which you want to insert:\n";
            int elem;
            cin >> elem;
            node.Push_back(elem);
            if(current == -1)current++;
        }


        else if (int(w[0]) - 48 == 3 && w.size() == 1)
        {
            node.Pop_front();
            if (current > 0)
            {
                current--;
            }
            else if (current == 0 && node.Pnode == nullptr)
            {
                current--;
            }
        }


        else if (int(w[0]) - 48 == 4 && w.size() == 1)
        {
            node.Pop_back();
            if (current == n-1 || (current == 0 && node.Pnode == nullptr))
            {
                current--;
            }
        }

        else if (int(w[0]) - 48 == 5 && w.size() == 1)
        {
            cout << "Enter the number which you want to insert:\n";
            int x;
            cin >> x;
            node.Insert_current(x,current);
        }

        else if (int(w[0]) - 48 == 6 && w.size() == 1)
        {
            node.Delete_current();
            if(current != 0 || node.Pnode == nullptr)
            {
            current--;
            }
            cout << node << endl;
            cout << "Current elem is: "<<current<< endl << endl;
            int sd;
            cin>>sd;
        }

        else if (int(w[0]) - 48 == 7 && w.size() == 1)
        {
            if (node.Is_Empty())
            {
             cout << "True\n";
            }
            else
            {
                cout << "False\n";
            }
            sleep(2);
        }

        else if (int(w[0]) - 48 == 8 && w.size() == 1)
        {
            node.Move_current_forward(current);
            current++;
        }

        else if (int(w[0]) - 48 == 9 && w.size() == 1)
        {
            node.Move_current_backward(current);
            current--;
        }

        else if (int(w[0]) - 48 == 1 && int(w[1]) - 48 == 0 && w.size() == 2)
        {
            command = "STOP";
            return 0;
        }


        else
        {
            cout << "strange command :/\n\n";
        }

        system("clear");
    }
    return 0;
}
