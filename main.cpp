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
    //cout << node;
    system("clear");
    while (command != "STOP")
    {
        cout << node << endl;
        cout << "1.Push_front\n2.Push_back\n3.Pop_front\n4.Pop_back\n5.Insert num\n6.Delete num\n7.Search number\n8.Delete num by value\n9.Concatenation\n10.Is_empty?\n11.STOP\n\n Choose the command:\n";
        cin >> w;
        if(int(w[0]) - 48 == 1 && w.size() == 1)
        {
            cout << "Enter the number which you want to insert:\n";
            int elem;
            cin >> elem;
            node.Push_front(elem);
        }


        else if(int(w[0]) - 48 == 2 && w.size() == 1)
        {
            cout << "Enter the number which you want to insert:\n";
            int elem;
            cin >> elem;
            node.Push_back(elem);
        }


        else if (int(w[0]) - 48 == 3 && w.size() == 1)
        {
            node.Pop_front();
        }


        else if (int(w[0]) - 48 == 4 && w.size() == 1)
        {
            node.Pop_back();
        }

        else if (int(w[0]) - 48 == 5 && w.size() == 1)
        {
            cout << "Enter the number which you want to insert:\n";
            int x;
            cin >> x;
            cout << "Enter the index where you want it to put:\n";
            int j;
            cin >> j;
            node.Insert(x,j);
        }

        else if (int(w[0]) - 48 == 6 && w.size() == 1)
        {
            cout << "Enter the index of the number which you want to delete:\n";
            int j;
            cin >> j;
            node.Delete(j);
        }

        else if (int(w[0]) - 48 == 7 && w.size() == 1)
        {
           cout << "Enter the number which you want to find:\n";
            int x;
            cin >> x;
            int index = node.Search(x);
            if(index >= 0)
            {
                cout << "Index of the first match:\n" << index;
            }
            else
            {
                cout << "No matches\n;";
            }
            sleep(5);
        }

        else if (int(w[0]) - 48 == 8 && w.size() == 1)
        {
            cout << "Enter the number which you want to find and delete:\n";
            int x;
            cin >> x;
            node.Delete_value(x);
        }

        else if (int(w[0]) - 48 == 9 && w.size() == 1)
        {
            cout << "Enter the amount of numbers in the second node:\n";
            int m;
            cin >> m;
            cout << "Enter the numbers of the second node:\n";
            Node node2(m);
            Node sum = (node + node2);
            cout << "Result:\n";
            cout << sum;
            sleep(5);
        }

        else if (int(w[0]) - 48 == 1 && int(w[1]) - 48 == 0 && w.size() == 2)
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

        else if (int(w[0]) - 48 == 1 && int(w[1]) - 48 == 1 && w.size() == 2)
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
