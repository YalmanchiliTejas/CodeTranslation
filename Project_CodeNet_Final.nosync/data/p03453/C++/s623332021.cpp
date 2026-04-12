#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <pair <ll, ll> > > gr;
ll n, m;

void dfs(ll v, ll t, vector <ll> &d, vector <ll> &w) {
    if (w[v] != -1) {
        return;
    }
    if (v == t) {
        w[v] = 1;
        return;
    }
    w[v] = 0;
    for (auto e : gr[v]) {
        ll u = e.first, r = e.second;
        if (d[u] + r == d[v]) {
            dfs(u, t, d, w);
            w[v] = (w[v] + w[u]) % INF;
        }
    }
}

void dijkstra(ll s, vector <ll> &d, vector <ll> &w) {
    d.resize(n, INF * INF);
    w.resize(n, -1);
    d[s] = 0;
    set <pair <ll, ll> > q;
    q.insert({d[s], s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
        for (auto e : gr[v]) {
            ll u = e.first, r = e.second;
            if (d[u] > d[v] + r) {
                q.erase({d[u], u});
                d[u] = d[v] + r;
                q.insert({d[u], u});
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        dfs(i, s, d, w);
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    gr.resize(n);
    for (ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        gr[v].push_back({u, w});
        gr[u].push_back({v, w});
    }
    vector <ll> ds, ws, dt, wt;
    dijkstra(s, ds, ws);
    dijkstra(t, dt, wt);
//    for (int i = 0; i < n; i++) {
//        cout << ws[i] << " ";
//    }
//    cout << "\n";
    ll res = ws[t] * wt[s] % INF;
    ll all = ds[t];
    for (ll i = 0; i < n; i++) {
        if (ds[i] + dt[i] != all) continue;
        if (ds[i] == dt[i]) {
            //cout << ws[i] << " " << wt[i] << "\n";
            res = (res - ws[i] * wt[i] % INF * ws[i] % INF * wt[i] % INF + INF) % INF;
        }
    }
    for (ll v = 0; v < n; v++) {
        for (auto e : gr[v]) {
            ll u = e.first, w = e.second;
            if (ds[v] + dt[u] + w != all) continue;
            if (w > abs(dt[u] - ds[v])) {
                res = (res - ws[v] * wt[u] % INF * ws[v] % INF * wt[u] % INF + INF) % INF;
            }
        }
    }
    cout << res;
}
