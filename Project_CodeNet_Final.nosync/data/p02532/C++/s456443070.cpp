#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector< stack<char> > v;
    v.resize(n);

    while(true) {
        string str;
        cin >> str;
        if (str == "push") {
            int t;
            char c;
            cin >> t >> c;
            t--;
            v[t].push(c);
        } else if (str == "pop") {
            int t;
            cin >> t;
            t--;
            cout << v[t].top() << endl;
            v[t].pop();
        } else if (str == "move") {
            int a, b;
            cin >> a >> b;
            a--,b--;
            v[b].push(v[a].top());
            v[a].pop();
        } else if (str == "quit") {
            break;
        }
    }

    return 0;
}