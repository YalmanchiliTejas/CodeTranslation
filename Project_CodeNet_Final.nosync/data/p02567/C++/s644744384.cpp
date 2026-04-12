#include <bits/stdc++.h>

#include <atcoder/all>
typedef long long lint;
using namespace std;
using namespace atcoder;

int n, q;

int op(int x, int y) {
    return max(x, y);
}
int id() {
    return INT_MIN;
}
int target;
bool f(int x) {
    return x < target;
}

int main() {
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segtree<int, op, id> seg(a);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            x--;
            seg.set(x, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << endl;
        } else {
            int x, v;
            cin >> x >> v;
            target = v;
            x--;
            auto ans = seg.max_right<f>(x) + 1;
            cout << ans << endl;
        }
    }
}