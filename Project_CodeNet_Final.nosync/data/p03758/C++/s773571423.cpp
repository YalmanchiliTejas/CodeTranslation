//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double old;

const int N = 200;

int a[N][N];
map<string, int> mem;

int ask(string &s) {
    if (mem.count(s)) {
        return mem[s];
    }
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return mem[s] = x;
}

int n;

int get_vertex() {
    return rand() % n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (a[i][j] || a[j][k] || a[i][k]) {
                    continue;
                }
                string s(n, '0');
                s[i] = s[j] = s[k] = '1';
                int x = ask(s);
                if (x == 0) {
                    a[i][j] = a[j][k] = a[i][k] = -1;
                }
                if (x == 1) {
                    s[k] = '0';
                    int y = ask(s);
                    s[k] = '1';
                    if (y) {
                        a[i][j] = 1;
                        a[j][k] = a[i][k] = -1;
                    } else {
                        s[j] = '0';
                        y = ask(s);
                        if (y) {
                            a[i][k] = 1;
                            a[i][j] = a[j][k] = -1;
                        } else {
                            a[j][k] = 1;
                            a[i][k] = a[i][j] = -1;
                        }
                    }
                }
                if (x == 2) {
                    s[k] = '0';
                    int y = ask(s);
                    s[k] = '1';
                    if (!y) {
                        a[i][j] = -1;
                        a[i][k] = a[j][k] = 1;
                    } else {
                        s[j] = '0';
                        y = ask(s);
                        if (!y) {
                            a[i][k] = -1;
                            a[i][j] = a[j][k] = 1;
                        } else {
                            a[j][k] = -1;
                            a[i][j] = a[i][k] = 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] == 0) {
                string s(n, '0');
                s[i] = s[j] = '1';
                if (ask(s)) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = -1;
                }
            }
        }
    }
    cout << '!';
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] == 1) {
                cout << " (" << i << ',' << j << ')';
            }
        }
    }
    cout << endl;
    return 0;
}