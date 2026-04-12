#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

struct edge {
    int to; long long dist;
    edge(int t, long long d) : to(t), dist(d) {}
};

vector<edge> e[100010]; 


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v; long long d; cin >> u >> v >> d;
        e[u].emplace_back(v, d);
        e[v].emplace_back(u, d);
    }
    vector<long long> v(n+1, 1e16); v[s] = 0;
    set<pair<long long, int>> sp; sp.emplace(v[s], s);
    while (!sp.empty()) {
        auto it = *sp.begin();
        sp.erase(sp.begin());
        if (v[it.second] < it.first) continue;
        auto curr = it.second;
        for (auto &edge: e[curr]) {
            if (v[edge.to] > v[curr] + edge.dist) {
                v[edge.to] = v[curr] + edge.dist;
                sp.emplace(v[edge.to], edge.to);
            }
        }
    }
    vector<long long> dpt(n+1, 0); dpt[t] = 1;
    vector<long long> dps(n+1, 0); dps[s] = 1;
    vector<pair<int, edge>> vi;
    vector<int> c;
    sp.emplace(v[t], t);
    while (!sp.empty()) {
        auto it = *sp.rbegin(); sp.erase(it);
        auto curr = it.second;
        c.emplace_back(curr);
        for (auto &edge: e[curr]) {
            if (v[edge.to] == v[curr] - edge.dist) {
                dpt[edge.to] = (dpt[edge.to] + dpt[curr]) % mod;
                sp.emplace(v[edge.to], edge.to);
            }
        }
    }
    sp.emplace(v[s], s);
    while (!sp.empty()) {
        auto it = *sp.begin(); sp.erase(it);
        auto curr = it.second;
        for (auto &edge: e[curr]) {
            if (v[edge.to] == v[curr] + edge.dist) {
                dps[edge.to] = (dps[edge.to] + dps[curr]) % mod;
                sp.emplace(v[edge.to], edge.to);
                vi.emplace_back(curr, edge);
            }
        }
    }
    long long D = v[t];
    long long ans = dps[t] * dpt[s] % mod;
    for (auto &x: c) {
        long long sub = dps[x] * dpt[x] % mod;
        sub = sub * sub % mod;
        if (v[x] * 2 == D) ans = (ans + mod - sub) % mod;
    }
    for (auto &iter: vi) {
        int ui = iter.first;
        int vi = iter.second.to;
        long long d = iter.second.dist;
        if (v[ui] >= D - v[vi] + d) continue;
        if (D - v[vi] >= v[ui] + d) continue;
        long long sub = dps[ui] * dpt[vi] % mod;
        sub = sub * sub % mod;
        ans = (ans + mod - sub) % mod;
    }
    cout << ans << endl;
    return 0;
}