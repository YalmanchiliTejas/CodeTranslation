#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pii pair<int, int>
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
using namespace std;

#define pli pair<ll, int>

vector<pii> g[100005];
ll d[100005], e[100005], x[100005], y[100005];
bool b[100005], c[100005];
priority_queue<pli, vector<pli>, greater<pli>> q;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    int u, v, w, s, t;
    cin >> n >> m >> s >> t;
    fr(m) cin >> u >> v >> w, g[u].push_back({v, w}), g[v].push_back({u, w});
    fill(d, d + n + 1, (ll)mod * mod);
    fill(e, e + n + 1, (ll)mod * mod);
    d[s] = 0;
    x[s] = 1;
    q.push({0, s});
    while (!q.empty()) {
        int p = q.top().second;
        q.pop();
        if (b[p]) continue;
        b[p] = 1;
        for (pli i : g[p]) {
            if (d[i.first] > d[p] + i.second) {
                d[i.first] = d[p] + i.second;
                q.push({d[i.first], i.first});
            }
        }
        for (pii i : g[p]) if (d[i.first] + i.second == d[p]) x[p] = (x[p] + x[i.first]) % mod;
    }
    e[t] = 0;
    y[t] = 1;
    q.push({0, t});
    while (!q.empty()) {
        int p = q.top().second;
        q.pop();
        if (c[p]) continue;
        c[p] = 1;
        for (pli i : g[p]) {
            if (e[i.first] > e[p] + i.second) {
                e[i.first] = e[p] + i.second;
                q.push({e[i.first], i.first});
            }
        }
        for (pii i : g[p]) if (e[i.first] + i.second == e[p]) y[p] = (y[p] + y[i.first]) % mod;
    }
    ll z = 0;
    fr1(n) if (d[i] == e[i] && d[i] + d[i] == d[t]) z = (z + x[i] * y[i] % mod * x[i] % mod * y[i]) % mod;//, cout << i << '\n';
    fr1(n) for (pii j : g[i]) {
        if (d[i] + d[i] < d[t] && d[j.first] + d[j.first] > d[t] && e[i] + e[i] > e[s] && e[j.first] + e[j.first] < e[s] && d[i] + e[i] == d[t] && d[i] + e[j.first] + j.second == d[t]) z = (z + x[i] * y[j.first] % mod * x[i] % mod * y[j.first]) % mod;//, cout << i << ' ' << j.first << '\n';
    }
    /*
    fr1(n) cout << d[i] << ' '; cout << '\n';
    fr1(n) cout << x[i] << ' '; cout << '\n';
    fr1(n) cout << e[i] << ' '; cout << '\n';
    fr1(n) cout << y[i] << ' '; cout << '\n';
    */
    ll z0 = x[t] * x[t] % mod;
    z0 -= z;
    if (z0 < 0) z0 += mod;
    cout << z0;
}
