#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define forn(i, n) for (ll i = 0; i < (ll) n; ++i)
#define sz(a) static_cast<int>(a.size())

char buff[(int) 2e6+ 17];
const ll inf = (ll) 1e9 + 7ll;

const int maxn = (int) 2e5 + 17;

int n, m, s, t;
vector< pair<int, ll> > g[maxn];
vector<int> g1[maxn];
ll ds[maxn], dt[maxn], dps[maxn], dpt[maxn];
bool used[maxn];

bool read() {
    if (scanf("%d %d %d %d", &n, &m, &s, &t) != 4)
        return false;

    --s, --t;

    forn (i, m) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        g[u - 1].push_back(make_pair(v - 1, x));
        g[v - 1].push_back(make_pair(u - 1, x));
    }

    return true;
}

void dijkstra(int v, ll* d) {
    fill(d, d + n, inf * inf);
    d[v] = 0;
    set< pair<ll, int> > Q;
    Q.insert(make_pair(d[v], v));

    for (; !Q.empty(); ) {
        v = Q.begin()->second;
        Q.erase(Q.begin());

        for (auto to : g[v])
            if (d[v] + to.second < d[to.first]) {
                Q.erase(make_pair(d[to.first], to.first));
                d[to.first] = d[v] + to.second;
                Q.insert(make_pair(d[to.first], to.first));
            }
    }
}

void dfs(int v, int s, ll* dp) {
    used[v] = true;

    if (v == s)
        dp[v] = 1;
    else
        dp[v] = 0;

    for (auto to : g1[v]) {
        if (!used[to])
            dfs(to, s, dp);

        dp[v] += dp[to];
        dp[v] %= inf;
    }
}

void solve() {
    dijkstra(s, ds);
    dijkstra(t, dt);

    for (int i = 0; i < n; ++i)
        for (auto to : g[i])
            if (ds[to.first] == ds[i] + to.second)
                g1[to.first].push_back(i);

    dfs(t, s, dps);

    forn (i, n)
        g1[i].clear();

    for (int i = 0; i < n; ++i)
        for (auto to : g[i])
            if (dt[to.first] == dt[i] + to.second)
                g1[to.first].push_back(i);

    fill(used, used + n, false);
    dfs(s, t, dpt);

    ll ans = dps[t] * dpt[s] % inf;

    for (int v = 0; v < n; ++v)
        for (auto to : g[v]) {
            int u = to.first;
            ll dd = to.second;

            if (ds[u] == ds[v] + dd && dt[v] == dt[u] + dd && ds[u] + dt[u] == ds[t] && dt[v] + ds[v] == ds[t]) {
                ll cnt = (dps[v] * dpt[u] % inf) * (dpt[u] * dps[v] % inf) % inf;

                if (abs(ds[v] - dt[u]) < dd)
                    ans = (inf + ans - cnt) % inf;
            }
        }

    for (int i = 0; i < n; ++i)
        if (ds[i] == dt[i] && ds[i] + dt[i] == ds[t])
            ans = (inf + ans - (dps[i] * dpt[i] % inf) * (dps[i] * dpt[i] % inf) % inf) % inf;

    printf("%lld\n", ans);
}

int main() {
#if SEREZHKA
    freopen("file.in", "r", stdin);
#endif

    while (read())
        solve();

    return 0;
}