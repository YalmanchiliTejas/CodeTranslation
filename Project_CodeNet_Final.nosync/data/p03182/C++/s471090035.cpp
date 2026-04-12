#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#define rep(i, x) for(int i = 0; i < x; i++)
using namespace std;
typedef long long ll;
ll MOD = (ll)1e9 + 7;
const ll N = 2e5+5, inf = 1e18+5;
ll add(ll x, ll y) { x += y; if (x >= MOD) return x - MOD; return x; }
ll sub(ll x, ll y) { x -= y; if (x < 0) return x + MOD; return x; }
ll mult(ll x, ll y) { return (x * y) % MOD; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    ll val, lazy;
    void add(ll x) {
        val += x;
        lazy += x;
    }
};
vector<Node> st(4*N, {0, 0});

void add(int node, int l, int r, int ql, int qr, ll x) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        st[node].add(x);
    } else {
        st[node*2].add(st[node].lazy);
        st[node*2+1].add(st[node].lazy);
        st[node].lazy = 0;

        add(node*2, l, (l+r)/2, ql, qr, x);
        add(node*2+1, (l+r)/2+1, r, ql, qr, x);
        st[node].val = max(st[node*2].val, st[node*2+1].val);
    }
}

ll query(int node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return -inf;
    if (ql <= l && r <= qr) {
        return st[node].val;
    } else {
        st[node*2].add(st[node].lazy);
        st[node*2+1].add(st[node].lazy);
        st[node].lazy = 0;

        ll q1 = query(node*2, l, (l+r)/2, ql, qr);
        ll q2 = query(node*2+1, (l+r)/2+1, r, ql, qr);
        return max(q1, q2);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<ll> l(m), r(m), a(m), dp(n+1, -inf);
    vector<vector<ll>> starting(n+1, vector<ll>()), ending(n+1, vector<ll>());
    rep (i, m) {
        cin >> l[i] >> r[i] >> a[i];
        starting[l[i]].push_back(i);
        ending[r[i]].push_back(i);
    }

    dp[0] = 0;
    /*
    for (int k = 0; k < m; ++k) if (l[k] == 0) dp[0] += a[k];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ll sum = 0;
            for (int k = 0; k < m; ++k)
                if (j < l[k] && l[k] <= i && i <= r[k])
                    sum += a[k];
            dp[i] = max(dp[i], dp[j]+sum);
        }
    }
    */
    for (int i = 1; i <= n; ++i) {
        for (ll x : starting[i]) add(1, 0, n, 0, i-1, a[x]);
        dp[i] = query(1, 0, n, 0, i-1);
        for (ll x : ending[i]) add(1, 0, n, 0, l[x]-1, -a[x]);
        add(1, 0, n, i, i, dp[i]);
    }
    cout << *max_element(begin(dp), end(dp)) << endl;
}