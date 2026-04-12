#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> mn[101];
    int n, to, from;
    char ch;
    string str;

    cin >> n;
    while (cin >> str) {
        if (str == "push") {
            cin >> to >> ch;
            mn[to].push(ch);
        }
        else if (str == "pop") {
            cin >> from;
            cout << mn[from].top() << endl;
            mn[from].pop();
        }
        else if (str == "move") {
            cin >> from >> to;
            mn[to].push(mn[from].top());
            mn[from].pop();
        }
        else if (str == "quit")
            break;
    }
    

    return 0;
}