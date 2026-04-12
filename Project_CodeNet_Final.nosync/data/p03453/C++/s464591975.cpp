#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll INF = 1e16;
ll MOD = 1e9 + 7;
void add(ll &a, ll b)
{
    a = (a+b+MOD)%MOD;
}
int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<P>> e(n+1);
    for(int i = 0; i < m; i++)
    {
        ll u, v, d;
        cin >> u >> v >> d;
        e[u].push_back(P(v, d));
        e[v].push_back(P(u, d));
    }

    vector<ll> ds(n+1);
    vector<ll> dt(n+1);
    vector<ll> paths(n+1);
    vector<ll> patht(n+1);
    for(int i = 1; i <= n; i++)
    {
        ds[i] = INF;
        dt[i] = INF;
    }
    ds[s] = 0;
    dt[t] = 0;
    paths[s] = 1;
    patht[t] = 1;

    function<void(ll, vector<ll> &, vector<ll> &)> dijkstra = [&](ll s, vector<ll> &d, vector<ll> &path)
    {
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(P(0, s));
        while(!que.empty())
        {
            P p = que.top();
            ll now = p.second;
            que.pop();
            if(d[now] < p.first) continue;
            for(auto nx : e[now])
            {
                ll nv = nx.first;
                ll cost = nx.second;
                if(d[nv] > d[now] + cost)
                {
                    d[nv] = d[now] + cost;
                    que.push(P(d[nv], nv));
                    path[nv] = path[now];
                }
                else if(d[nv] == d[now] + cost)
                {
                    add(path[nv], path[now]);
                }
            }
        }
    };
    dijkstra(s, ds, paths);
    dijkstra(t, dt, patht);

    ll len = ds[t];
    ll ans = paths[t] * paths[t] % MOD;
    for(int i = 1; i <= n; i++)
    {
        if(ds[i] + dt[i] == len && ds[i] * 2 == len)
        {
            ll tmp = (paths[i] * paths[i] % MOD) * (patht[i] * patht[i] % MOD) % MOD;
            add(ans, -tmp);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < e[i].size(); j++)
        {
            P p = e[i][j];
            ll now = p.first;
            ll cost = p.second;
            if(ds[i] + dt[now] + cost == len && ds[i] * 2 < len && dt[now] * 2 < len)
            {
                ll tmp = (paths[i] * paths[i] % MOD) * (patht[now] * patht[now] % MOD) % MOD;
                add(ans, -tmp);
            }
        }
    }
    cout << ans << endl;
}
