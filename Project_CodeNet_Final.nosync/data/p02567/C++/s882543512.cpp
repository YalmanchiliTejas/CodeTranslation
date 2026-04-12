#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return -1;
}

int target;

bool f(int x) {
    return x < target;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segtree<int, op, e> seg(a);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            seg.set(x - 1, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l - 1, r) << endl;
        } else {
            int x, v;
            cin >> x >> v;
            target = v;
            cout << seg.max_right<f>(x - 1) + 1 << endl;
        }
    }
}
