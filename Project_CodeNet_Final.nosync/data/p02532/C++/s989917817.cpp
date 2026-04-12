#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<stack<string> > st(n);
    string s, c;
    int p, p1, p2;
    while (cin >> s, s != "quit") {
        if (s == "push") {
            cin >> p >> c;
            st[p-1].push(c);
        } else if (s == "pop") {
            cin >> p;
            cout << st[p-1].top() << endl;
            st[p-1].pop();
        } else if (s == "move") {
            cin >> p1 >> p2;
            st[p2-1].push(st[p1-1].top());
            st[p1-1].pop();
        }
    }
    return 0;
}