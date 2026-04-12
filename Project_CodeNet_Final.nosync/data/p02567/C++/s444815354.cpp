#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return -INF;
}

int v;
bool f(int x) {
    return x < v;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    segtree<int, op, e> seg(a);
    int t, x, l, r;
    rep(i, q) {
        cin >> t;
        if (t == 1) {
            cin >> x >> v;
            x--;
            seg.set(x, v);
        } else if (t == 2) {
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << endl;
        } else {
            cin >> x >> v;
            x--;
            cout << seg.max_right<f>(x) + 1 << endl;
        }
    }
    return 0;
}