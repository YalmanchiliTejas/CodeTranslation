#include <bits/stdc++.h>

using namespace std;

namespace {
    string s;
    int X;
    void input() {
        cin >> s;
        cin >> X;
    }

    int calc(char op, int a, int b) {
        if (op == '+') return a + b;
        if (op == '*') return a * b;
        assert(0);
    }

    int number(const string& s, int& index) {
        int r = 0;
        while (index < s.size() && isdigit(s[index])) {
            r = r * 10 + (s[index] - '0');
            index++;
        }
        return r;
    }

    int L(const string& s, int& index) {
        int r = number(s, index);
        while (index < s.size()) {
            char op = s[index++];
            int a = number(s, index);
            r = calc(op, r, a);
        }
        return r;
    }

    int term(const string& s, int& index) {
        int r = number(s, index);
        while (index < s.size() && s[index] == '*') {
            index++;
            int a = number(s, index);
            r *= a;
        }
        return r;
    }

    int M(const string& s, int& index) {
        int r = term(s, index);
        while (index < s.size()) {
            assert(s[index] == '+');
            index++;
            int a = term(s, index);
            r += a;
        }
        return r;
    }

    void solve() {
        int index = 0;
        int m = M(s, index);
        index = 0;
        int l = L(s, index);
        if (m == X && l == X) {
            cout << "U" << endl;
        } else if (m != X && l != X) {
            cout << "I" << endl;
        } else if (m == X) {
            cout << "M" << endl;
        } else if (l == X) {
            cout << "L" << endl;
        }
    }
}

int main() {
    input(); solve();
    return 0;
}