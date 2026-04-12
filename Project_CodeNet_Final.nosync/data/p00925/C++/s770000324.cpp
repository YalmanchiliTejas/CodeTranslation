#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int char_to_int(char c) {
    return static_cast<int>(c -'0');
}

int m_rule(string expr) {
    stack<int> s;
    for(int i=0; i<expr.size(); ++i) {
        if(expr[i] == '*') {
            int l = s.top();
            s.pop();
            s.push(l * char_to_int(expr[i+1]));
            i++;
        } else if('0' <= expr[i] && expr[i] <= '9') {
            s.push(char_to_int(expr[i]));
        }
    }
    int ret = 0;
    while(!s.empty()) {
        ret += s.top();
        s.pop();
    }
    return ret;
}

int l_rule(string expr) {
    int ret = 0;
    for(int i=0; i<expr.size(); ++i) {
        if(expr[i] == '*') {
            ret *= char_to_int(expr[i+1]);
            i++;
        } else if(expr[i] == '+') {
            ret += char_to_int(expr[i+1]);
            i++;
        } else {
            ret = char_to_int(expr[i]);
        }
    }
    return ret;
}

int main() {
    string expr;
    int ans;
    cin >> expr >> ans;

    int m = m_rule(expr);
    int l = l_rule(expr);
    if(m == ans && l == ans) {
        cout << "U" << endl;
    } else if(m == ans) {
        cout << "M" << endl;
    } else if(l == ans) {
        cout << "L" << endl;
    } else {
        cout << "I" << endl;
    }
}
