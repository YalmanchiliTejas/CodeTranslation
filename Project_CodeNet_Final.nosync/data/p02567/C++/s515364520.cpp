#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int v;
int op(int a, int b) {
    return max(a, b);
}
int e() {
    return (int)(-1e9);
}
bool f(int x) {
    return x<v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    segtree<int, op, e> seg(a);
    int t, x;
    rep(i, q) {
        cin >> t >> x >> v;
        if (t==1) seg.set(x-1, v);
        else if(t==2) cout << seg.prod(x-1, v) << endl;
        else cout << seg.max_right<f>(x-1)+1 << endl;
    }
    return 0;
}