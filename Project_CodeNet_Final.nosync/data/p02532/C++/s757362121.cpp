#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int n;
    string s;
    stack<char> st[128];

    cin >> n;
    cin >> s;
    while (s != "quit"){
        if (s == "push"){
            int p;
            char c;

            cin >> p >> c;
            st[p].push(c);
        }
        else if (s == "pop"){
            int p;

            cin >> p;
            cout << st[p].top() << endl;
            st[p].pop();
        }
        else if (s == "move"){
            int p1, p2;

            cin >> p1 >> p2;
            st[p2].push(st[p1].top());
            st[p1].pop();
        }
        cin >> s;
    }

    return (0);
}