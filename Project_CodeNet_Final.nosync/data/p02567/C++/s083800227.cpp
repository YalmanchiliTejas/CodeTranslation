#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int n, q, t, x ,y;

int op (int a, int b) { return max(a, b); }
int e () { return (int)-1e9; }
bool f (int a) { return a < y; }

int main(){
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    segtree<int, op, e> data(a);
    while (q--) {
        cin >> t >> x >> y;
        if (t == 1) data.set(x - 1, y);
        else if (t == 2) cout << data.prod(x - 1, y) << "\n";
        else cout << data.max_right<f>(x - 1) + 1 << "\n";
    }
    return 0;
}