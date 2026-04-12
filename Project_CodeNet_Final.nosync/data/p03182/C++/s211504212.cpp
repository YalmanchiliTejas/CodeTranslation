#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

class LazySegTree {
public:
    int n = 1;
    VLL data, lazy;

    LazySegTree(int N) {
        while (n < N) n *= 2;
        data.resize(2 * n);
        lazy.resize(2 * n);
    }

    void push(int k, int l, int r) {
        data[k] += lazy[k];
        if (r - l > 1) {
            lazy[k * 2] += lazy[k];
            lazy[k * 2 + 1] += lazy[k];
        }
        lazy[k] = 0;
    }

    void incr(int a, int b, LL val) {
        incr1(a, b, val, 1, 0, n);
    }
    void incr1(int a, int b, LL val, int k, int l, int r) {
        push(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = val;
            push(k, l, r);
        }
        else {
            int m = (l + r) >> 1;
            incr1(a, b, val, 2 * k, l, m);
            incr1(a, b, val, 2 * k + 1, m, r);
            data[k] = max(data[2 * k], data[2 * k + 1]);
        }
    }

    LL query(int a, int b) {
        return query1(a, b, 1, 0, n);
    }
    LL query1(int a, int b, int k, int l, int r) {
        push(k, l, r);

        if (b <= l || r <= a) return LONG_MIN;
        if (a <= l && r <= b) return data[k];

        int m = (l + r) >> 1;
        LL vl = query1(a, b, 2 * k, l, m);
        LL vr = query1(a, b, 2 * k + 1, m, r);
        return max(vl, vr);
    }
};

int main() {
    IOS;

    int N, M;
    cin >> N >> M;
    unordered_map<int, VI> add;
    unordered_map<int, vector<pair<int, int>>> del;
    int l, r, a;
    forn(i, 0, M) {
        cin >> l >> r >> a;
        add[l].push_back(a);
        del[r].push_back(make_pair(l, a));
    }

    LazySegTree seg(N);
    LL res = 0;
    for (int k = 1; k <= N; k++) {
        for (auto a: add[k])
            seg.incr(0, k, a);

        LL mx = seg.query(0, k);
        res = max(res, mx);
        seg.incr(k, k + 1, mx);

        for (auto d: del[k])
            seg.incr(0, d.first, -d.second);
    }

    cout << res << endl;

    return 0;
}
