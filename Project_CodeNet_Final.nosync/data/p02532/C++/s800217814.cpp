#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    string s;
    int i;
    stack<char> stk[128];

    int n;
    cin >> n;
    for (cin >> s >> i; s != "quit"; cin >> s >> i){
        if (s == "push"){
            char c;

            cin >> c;
            stk[i].push(c);
        }
        else if (s == "move"){
            int t;

            cin >> t;
            char tmp = stk[i].top();
            stk[i].pop();
            stk[t].push(tmp);
        }
        else {
            cout << stk[i].top() << endl;
            stk[i].pop();
        }
    }

    return 0;
}