#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

//#####################
//Dijkstra
//#####################
struct edge
{
    ll to, cost;
};

int n;
vector<edge> g[112345];
ll sdis[112345], tdis[112345];
ll sc[112345];
ll tc[112345];

void dijkstra(int s, ll dis[], ll c[])
{
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dis, dis + n + 1, INF);
    dis[s] = 0;
    que.push(P(0, s));

    c[s] = 1;

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int n_ = p.second;
        if (dis[n_] < p.first)
            continue;
        for (int i = 0; i < g[n_].size(); i++)
        {
            edge e = g[n_][i];
            if (dis[e.to] == dis[n_] + e.cost)
            {
                c[e.to] += c[n_];
                c[e.to] %= MOD;
            }

            if (dis[e.to] > dis[n_] + e.cost)
            {
                c[e.to] = c[n_];
                c[e.to] %= MOD;
                dis[e.to] = dis[n_] + e.cost;
                que.push(P(dis[e.to], e.to));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, s, t;

    cin >> n >> m >> s >> t;

    vector<pair<int, int>> e;

    map<pair<int, int>, ll> mp;

    REP(i, m)
    {
        int u, v, d;
        cin >> u >> v >> d;

        g[u].push_back({v, d});
        g[v].push_back({u, d});

        e.push_back({u, v});
        mp[{u, v}] = d;
    }

    dijkstra(t, tdis, tc);
    dijkstra(s, sdis, sc);

    ll res = sc[t] * sc[t] % MOD;

    ll allDis = sdis[t];

    for (int i = 0; i < e.size(); i++)
    {
        pair<int, int> p = e[i];

        if (sdis[p.first] + tdis[p.second] + mp[p] == allDis && max(sdis[p.first], tdis[p.second]) * 2 < allDis)
        {
            ll tmp = sc[p.first] * tc[p.second] % MOD * sc[p.first] % MOD * tc[p.second] % MOD;
            res -= tmp;
            res = (res + MOD) % MOD;
        }

        if (tdis[p.first] + sdis[p.second] + mp[p] == allDis && max(sdis[p.second], tdis[p.first]) * 2 < allDis)
        {
            ll tmp = sc[p.second] * tc[p.first] % MOD * sc[p.second] % MOD * tc[p.first] % MOD;
            res -= tmp;
            res = (res + MOD) % MOD;
        }
    }

    if (allDis % 2 == 0)
        for (int i = 1; i <= n; i++)
        {
            if (sdis[i] == allDis / 2 && tdis[i] == allDis / 2)
            {
                ll tmp = sc[i] * tc[i] % MOD * sc[i] % MOD * tc[i] % MOD;
                res -= tmp;
                res = (res + MOD) % MOD;
            }
        }

    cout << res << endl;

    return 0;
}