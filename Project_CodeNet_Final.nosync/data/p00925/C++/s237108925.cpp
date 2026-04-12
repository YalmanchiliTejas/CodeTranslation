#include <iostream>
#include <sstream>
using namespace std;

char result[8] = "IMLU";

int main() {
    string expr;
    int ans, a, b, c, res1, res2;
    char op;
    stringstream ss, tt;
    cin >> expr >> ans;
// left-to-right
    ss << expr;
    ss >> a;
    while (!ss.eof()) {
        ss >> op;
        ss >> b;
        if (op == '+') {
            a += b;
        } else if (op == '*') {
            a *= b;
        }
    }
    res1 = a;

    ss.clear();
    // multiplication-first
    ss << expr;
    ss >> a;
    while (!ss.eof()) {
        ss >> op;
        ss >> b;

        if(op == '+') {
            tt << a;
            tt << '+';
            a = b;
        } else if (op == '*') {
            a *= b;
        }
    }
    tt << a;

    ss.clear();
    ss << tt.str();
    ss >> a;
    while (!ss.eof()) {
        ss >> op;
        ss >> b;
        if (op == '+') {
            a += b;
        } else if (op == '*') {
            a *= b;
        }
    }
    res2 = a;

    int status = 0;
    if (res1 == ans) {
        status += 2;
    }
    if (res2 == ans) {
        status += 1;
    }

    cout << result[status] << endl;

    return 0;
}