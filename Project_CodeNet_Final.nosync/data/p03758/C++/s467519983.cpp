//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double old;

const int N = 200;

int a[N][N], used[N][N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int edges = 0;
    mt19937 rnd(228);
    uniform_int_distribution<> get(0, n - 1);
    while (edges < n - 1) {
        int v = get(rnd);
        int u = get(rnd);
        while (v == u || used[v][u]) {
            v = get(rnd);
            u = get(rnd);
        }
        used[v][u] = used[u][v] = 1;
        string s(n, '0');
        s[v] = s[u] = '1';
        cout << "? " << s << endl;
        int x;
        cin >> x;
        if (x) {
            a[v][u] = a[u][v] = 1;
            ++edges;
        }
    }
    cout << '!';
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j]) {
                cout << " (" << i << ',' << j << ')';
            }
        }
    }
    cout << endl;
    return 0;
}