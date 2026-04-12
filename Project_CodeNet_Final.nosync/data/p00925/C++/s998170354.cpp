#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int number(string &s, int &i) {
    return s[i++] - '0';
}

int term(string &s, int &i) {
    int res = number(s, i);
    while (true) {
        if (s[i] == '*') {
            i++;
            res *= number(s, i);
        } else {
            break;
        }
    }
    return res;
}

int expr(string &s, int &i) {
    int res = term(s, i);
    while (true) {
        if (s[i] == '+') {
            i++;
            res += term(s, i);
        } else {
            break;
        }
    }
    return res;
}

int main() {
    string s; cin >> s;
    int n = s.length();
    int ans; cin >> ans;
    int ans_LtoR = s[0] - '0';
    for (int i = 1; i < n; i += 2) {
        if (s[i] == '+') ans_LtoR += s[i + 1] - '0';
        if (s[i] == '*') ans_LtoR *= s[i + 1] - '0';
    }
    int i = 0;
    int ans_Mult = expr(s, i);
    bool is_LtoR = ans == ans_LtoR;
    bool is_Mult = ans == ans_Mult;
    if (is_LtoR && is_Mult) {
        cout << "U" << endl;
    } else if (is_LtoR) {
        cout << "L" << endl;
    } else if (is_Mult) {
        cout << "M" << endl;
    } else {
        cout << "I" << endl;
    }
    return 0;
}
