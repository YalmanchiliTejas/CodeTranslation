#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll,int>;

const ll MOD = 1000000007;
const ll INF = 1ll<<60;
ll mod(ll a, ll m) { return (a % m + m) % m; }

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;

    vector<vector<P>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v; ll d;
        cin >> u >> v >> d;
        u--; v--;
        G[u].push_back(P(d, v));
        G[v].push_back(P(d, u));
    }

    vector<ll> ds(n,INF), dt(n,INF), ns(n,0), nt(n,0);

    ds[s] = 0; ns[s] = 1;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0ll, s));
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        ll d = p.first;
        int v = p.second;
        if (ds[v] < d) continue;
        for (auto nv : G[v]) {
            if (ds[nv.second] > ds[v] + nv.first) {
                ds[nv.second] = ds[v] + nv.first;
                ns[nv.second] = ns[v];
                que.push(P(ds[nv.second], nv.second));
            }
            else if (ds[nv.second] == ds[v] + nv.first) {
                ns[nv.second] += ns[v];
                ns[nv.second] %= MOD;
            }
        }
    }

    dt[t] = 0; nt[t] = 1;
    que.push(P(0ll, t));
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        ll d = p.first;
        int v = p.second;
        if (dt[v] < d) continue;
        for (auto nv : G[v]) {
            if (dt[nv.second] > dt[v] + nv.first) {
                dt[nv.second] = dt[v] + nv.first;
                nt[nv.second] = nt[v];
                que.push(P(dt[nv.second], nv.second));
            }
            else if (dt[nv.second] == dt[v] + nv.first) {
                nt[nv.second] += nt[v];
                nt[nv.second] %= MOD;
            }
        }
    }

    ll dist = ds[t];
    ll ans = (ns[t] * nt[s]) % MOD;
    for (int v = 0; v < n; v++) {
        if (ds[v] == dt[v] && ds[v] + dt[v] == dist) {
            ll sub = (ns[v] * nt[v]) % MOD;
            ans = mod(ans - sub * sub % MOD, MOD);
        }
        for (auto nv : G[v]) {
            int from = v, to = nv.second;
            ll d = nv.first;
            if (ds[from] + d + dt[to] != dist) continue;
            if (ds[from] + d != ds[to] || dt[to] + d != dt[from]) continue;
            if (ds[from] < dt[from] && ds[to] > dt[to]) {
                ll sub = (ns[from] * nt[to]) % MOD;
                ans = mod(ans - sub * sub % MOD, MOD);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}