#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define fr(i,j,k) for(int i=j;i<k;i++)
//#define f(n) fr(i,0,n)
//#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const ll mod = 1e9 + 7;
const int maxn = 2e5+5;
#include<atcoder/all>
using namespace atcoder;
int pull(int a,int b) {
    return max(a, b);
}
int e() {
    return -1;
}
int tar;
bool f(int x) {
    return x < tar;
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int>v(n);
    for (auto &i : v) {
        cin >> i;
    }
    segtree<int,pull,e>seg(v);
    for (int i = 0 ; i < q ; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, v;
            cin >> x >> v;
            seg.set(x-1,v);
        }
        else if (op == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l-1, r) << '\n';
        }
        else {
            int x, v;
            cin >> x >> v;
            tar = v;
            cout << seg.max_right<f>(x-1) + 1 << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        solve();
    }
    
}
