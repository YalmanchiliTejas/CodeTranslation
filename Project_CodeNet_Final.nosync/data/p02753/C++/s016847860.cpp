#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int ctoi(char c) {
    int n = c - '0';
    return n;
}

int pow_int(int x, int n) {
    if (n == 0) {
        return 1;
    }else {
        int y = x;
        for (int i = 0; i < n-1; i++) {
            x *= y;
        }
        return x;
    }
}

int main() {
    string s;
    cin >> s;
    if (s == "AAA" || s == "BBB") {
        cout << "No";
    }else {
        cout << "Yes";
    }
}