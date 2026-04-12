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

void relax(int &a, int &b, int &c, int val) {
    if (a == 0) a = val;
    if (b == 0) b = val;
    if (c == 0) c = val;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (abs(a[i][j]) + abs(a[j][k]) + abs(a[i][k]) >= 2) continue;
                int val = a[i][j] + a[j][k] + a[i][k];
                string s(n, '0');
                s[i] = s[j] = s[k] = '1';
                if (ask(s) == 0) {
                    relax(a[i][j], a[j][k], a[i][k], -1);
                }
                if ((ask(s) == 1 && val == -1) || (ask(s) == 2 && val == 1)) {
                    string t = s;
                    if (a[i][j]) {
                        t[i] = '0';
                        if (ask(t)) {
                            a[j][k] = 1;
                        } else {
                            a[i][k] = 1;
                        }
                    } else
                    if (a[j][k]) {
                        t[j] = '0';
                        if (ask(t)) {
                            a[i][k] = 1;
                        } else {
                            a[i][j] = 1;
                        }
                    } else
                    if (a[i][k]) {
                        t[k] = '0';
                        if (ask(t)) {
                            a[i][j] = 1;
                        } else {
                            a[j][k] = 1;
                        }
                    }
                    relax(a[i][j], a[j][k], a[i][k], -1);
                }
                if (ask(s) == 1) {
                    if (val == 1) {
                        relax(a[i][j], a[j][k], a[i][k], -1);
                    }
                    if (val == 0) {
                        string t = s;
                        t[i] = '0';
                        if (ask(t)) {
                            a[j][k] = 1;
                        } else {
                            t = s;
                            t[j] = '0';
                            if (ask(t)) {
                                a[i][k] = 1;
                            } else {
                                a[i][j] = 1;
                            }
                        }
                        relax(a[i][j], a[j][k], a[i][k], -1);
                    }
                }
                if (ask(s) == 2) {
                    if (val == -1) {
                        relax(a[i][j], a[j][k], a[i][k], 1);
                    }
                    if (val == 0) {
                        string t = s;
                        t[i] = '0';
                        if (!ask(t)) {
                            a[j][k] = -1;
                        } else {
                            t = s;
                            t[j] = '0';
                            if (!ask(t)) {
                                a[i][k] = -1;
                            } else {
                                a[i][j] = -1;
                            }
                        }
                        relax(a[i][j], a[j][k], a[i][k], 1);
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