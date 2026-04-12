#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<char> h[n+1];
    string op;

    while(cin >> op && op != "quit") {
        if (op == "push") {
            int a; char b;
            cin >> a >> b;
            h[a].push(b);
        } else if (op == "pop") {
            int a;
            cin >> a;
            cout << h[a].top() << endl;
            h[a].pop();
        } else if (op == "move") {
            int a; int b;
            cin >> a >> b;
            h[b].push(h[a].top());
            h[a].pop();
        }
    }

    return 0;
}