#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int read() {
    static char s[1 << 16];
    static int i, n;
    int r = 0;
    for (;;) {
        if (i == n) {
            cin.read(s, sizeof(s));
            i = 0;
            n = (int)cin.gcount();
            if (n == 0) break;
        }
        unsigned int c = s[i++] - '0';
        if (c < 10) {
            r *= 10;
            r += c;
        } else {
            break;
        }
    }
    return r;
}

int main() {
    int n = read();

    vector<int> m;
    m.reserve(n);

    for (int i = 0; i < n; i++) {
        int a = read();

        auto it = upper_bound(m.begin(), m.end(), a, greater<>());
        if (it == m.end()) m.push_back(a); else *it = a;
    }

    cout << m.size() << endl;

    return 0;
}