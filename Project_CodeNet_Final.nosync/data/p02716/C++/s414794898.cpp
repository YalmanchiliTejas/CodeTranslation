#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int read() {
    static char s[1 << 18];
    static int i, j;
    int r = 0, t = 1, b = 0;
    while (1) {
        if (i == j) {
            cin.read(s, sizeof(s));
            i = 0;
            j = cin.gcount();
            if (j == 0) break;
        }
        int c = s[i++];
        if ('0' <= c && c <= '9') {
            r = r * 10 + (c - '0');
            b = 1;
        } else if (c == '-') {
            t = -1;
        } else if (b) {
            break;
        }
    }
    return r * t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = read();

    int a0 = read(), a1 = read();

    ll r0 = 0, r1 = max(a0, a1), r2;
    ll s = a0;

    for (int i = 2; i < n; i++) {
        int a = read();

        if (i & 1) {
            r2 = max(r0 + a, s);
        } else {
            r2 = max(r0 + a, r1);
            s += a;
        }
        r0 = r1;
        r1 = r2;
    }

    cout << r1 << endl;

    return 0;
}