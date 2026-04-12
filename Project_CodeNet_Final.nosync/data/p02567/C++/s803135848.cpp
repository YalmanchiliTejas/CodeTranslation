#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const int INF = 1001001001;
const ll mod = 998244353;
const ll INFL = 1001001001001001000;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return (int) -1;
}

int v;

bool f(int x) {
    return x < v;
}


int main() {
    int n, q; cin >> n >> q;
    segtree<int, op, e> seg(n+1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        seg.set(i, a);
    }
    rep(qq, q) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v;
            seg.set(x, v);
        } else if (t == 2) {
            int l, r; cin >> l >> r;
            cout << seg.prod(l, r+1) << endl;
        } else {
            int x; cin >> x >> v;
            cout << seg.max_right<f>(x) << endl;
        }
    }
    return 0;
}
