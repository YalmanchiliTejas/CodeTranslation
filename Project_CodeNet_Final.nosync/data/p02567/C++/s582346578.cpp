#include <atcoder/segtree>
#include <iostream>
#include <vector>

using namespace std;
using namespace atcoder;

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int target;

bool f(int v) { return v < target; }

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
            x--;
            seg.set(x, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << endl;
        } else if (t == 3) {
            int p;
            cin >> p >> target;
            p--;
            cout << seg.max_right<f>(p) + 1 << endl;
        }
    }
}
