#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;

constexpr int N = 200009;
int n, m; 
ll x[N], dp[N], s[N << 2], lazy[N << 2];
vector<int> ending[N];
vector<pair<pair<int, int>, int>> seg;

inline int L(int v) {return v << 1;}
inline int R(int v) {return L(v) + 1;}

void build(int v, int l, int r) {
    if(l == r) {
        s[v] = x[l];
    } else {
        int m = l + r >> 1;
        build(L(v), l, m);
        build(R(v), m + 1, r);
        s[v] = max(s[L(v)], s[R(v)]);
    }
}
void push(int v) {
    if(!lazy[v]) return;
    lazy[L(v)] += lazy[v];
    s[L(v)] += lazy[v];
    lazy[R(v)] += lazy[v];
    s[R(v)] += lazy[v];
    lazy[v] = 0;
}
ll mx(int v, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return 0;
    if(ql <= l && r <= qr) return s[v];
    push(v);
    int m = l + r >> 1;
    return max(mx(L(v), l, m, ql, qr), mx(R(v), m + 1, r, ql, qr));
}
void add(int v, int l, int r, int ql, int qr, ll value) {
    if(l > qr || r < ql) return;
    if(ql <= l && r <= qr) {
        lazy[v] += value;
        s[v] += value;
    } else {
        push(v);
        int m = l + r >> 1;
        add(L(v), l, m, ql, qr, value);
        add(R(v), m + 1, r, ql, qr, value);
        s[v] = max(s[L(v)], s[R(v)]);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int l, r, a;
        cin >> l >> r >> a;
        x[l] += a;
        x[r + 1] -= a;
        seg.push_back({{l, r}, a});
        ending[r].push_back(i);
    }

    for(int i = 1; i < N; ++i) {
        x[i] += x[i - 1];
    }
    for(int i = 1; i < N; ++i) {
        x[i] = -x[i];
    }
    build(1, 1, n);
    for(int i = 1; i <= n; ++i) {
        dp[i] = -x[i];
        for(int j : ending[i - 1]) {
            add(1, 1, n, seg[j].fi.fi, seg[j].fi.se, seg[j].se);
        }
        dp[i] += mx(1, 1, n, 1, i - 1);
        add(1, 1, n, i, i, dp[i]);
    }
    cout << max(0LL, *max_element(dp + 1, dp + n + 1)) << '\n';   
}
