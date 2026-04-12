#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

struct unionFind {
    int elements = 0;
    vector<int> Par, Rank_p;
    unionFind(int n) : Par(n), Rank_p(n) {
        for (int id = 0; id < n; id++) {
            elements   = n;
            Par[id]    = id;
            Rank_p[id] = 0;
        }
    }
    int find(int x) {
        if (Par[x] == x)
            return x;
        else
            return Par[x] = find(Par[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Rank_p[x] < Rank_p[y])
            Par[x] = y;
        else {
            Par[y] = x;
            if (Rank_p[x] == Rank_p[y]) Rank_p[x]++;
        }
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int groups() {
        set<int> se;
        for (auto x : Par) {
            se.insert(x);
        }
        return se.size();
    }
};

int main() {
    lint n, k;
    cin >> n >> k;

    lint ans = 0;
    for (lint b = k + 1; b <= n; b++) {
        lint p = n / b;
        lint r = n % b;
        ans += p * max(0ll, b - k) + max(0ll, r - k + 1);
        dd(p, r);
        dd(b, ans);
        if (k == 0) { ans--; }
    }

    cout << ans << endl;
    return 0;
}