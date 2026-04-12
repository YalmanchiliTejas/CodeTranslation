#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

using namespace std;

#define int long long
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vpii vector<pii>
#define vb vector<bool>
#define vbb vector<vb>
#define vs vector<string>
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define in(a, x) for (int i = x; i < (a).size(); ++i) cin >> (a)[i]
#define out(a) for (auto qwe : a) cout << qwe << " "

const int INF = 1e9;
const int INF64 = 1e16; // todo 16 -> 18
const int MOD = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int MOD3 = 998244353;
const int P = 37;

const int mxn = 200000;

struct SegTree {
    vi t;
    vi d;
    int m = 1;

    SegTree(int n) {
        while (m < n) m <<= 1;
        t.assign(2 * m, 0);
        d.assign(2 * m, 0);
    }

    void push(int v) {
        t[v] += d[v];

        if (v < m) {
            d[v << 1] += d[v];
            d[(v << 1) + 1] += d[v];
        }

        d[v] = 0;
    }

    int getmax(int v, int tl, int tr, int l, int r) {
        push(v);

        if (tl > r || tr < l) return -INF64;

        if (tl >= l && tr <= r) {
            return t[v];
        }

        int mid = (tl + tr) >> 1;

        return max(getmax(v << 1, tl, mid, l, r),
                    getmax((v << 1) + 1, mid + 1, tr, l, r));
    }

    int getmax(int l, int r) {
        return getmax(1, 1, m, l, r);
    }

    void add(int v, int tl, int tr, int l, int r, int x) {
        push(v);

        if (tl > r || tr < l) return;

        if (tl >= l && tr <= r) {
            d[v] += x;
            push(v);
            return;
        }

        int mid = (tl + tr) >> 1;

        add(v << 1, tl, mid, l, r, x);
        add((v << 1) + 1, mid + 1, tr, l, r, x);

        if (v < m)
            t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }

    void add(int l, int r, int x) {
        add(1, 1, m, l, r, x);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<pii, int>> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].ff.ss >> q[i].ff.ff >> q[i].ss;
    }

    sort(all(q));

    int ind = 0;

    SegTree t(n + 1);

    for (int i = 1; i <= n; ++i) {
        int mx = t.getmax(1, i);
        t.add(i, i, mx);

        while (ind < m && q[ind].ff.ff == i) {
            t.add(q[ind].ff.ss, q[ind].ff.ff, q[ind].ss);
            ++ind;
        }
    }

    cout << max(t.getmax(1, n), 0ll);
}