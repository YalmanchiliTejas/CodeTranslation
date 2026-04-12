#include <bits/stdc++.h>

#define X first
#define Y second
#define pb push_back

using namespace std;


const int maxn = 2e5;
vector < pair <int, int> > g[maxn];

const long long INF = 1e18;
const long long mod = 1e9 + 7;

void djkstra(int s, vector <long long> &d, vector <long long> &c)
{
    d[s] = 0;
    c[s] = 1;
    int n = d.size();
    set < pair <long long, int> > Q;
    for (int i = 0; i < n; i++)
        Q.insert({d[i], i});

    while (!Q.empty())
    {
        pair <long long, int> t = *Q.begin();
        Q.erase(Q.begin());
        int v = t.Y;
        for (auto e : g[v])
        {
            if (d[e.X] < d[v] + e.Y) continue;
            if (d[e.X] == d[v] + e.Y) {c[e.X] += c[v]; c[e.X] %= mod; continue;}
            Q.erase({d[e.X], e.X});
            d[e.X] = d[v] + e.Y;
            c[e.X] = c[v];
            Q.insert({d[e.X], e.X});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;
        g[u].pb({v, cost});
        g[v].pb({u, cost});
    }

    s--, t--;

    vector <long long> d1(n, INF), d2(n, INF), c1(n, 0), c2(n, 0);
    djkstra(s, d1, c1);
    djkstra(t, d2, c2);

    long long all = (c1[t] * c1[t]) % mod;
    for (int i = 0; i < n; i++)
    {
        if (d1[i] == d2[i] && d1[i] == d1[t] / 2)
        {
            all -= (((c1[i]*c2[i])%mod)*((c1[i]*c2[i]) % mod))%mod;
            all += mod;
            all %= mod;
        }
        for (auto e : g[i])
        {
                if (d1[i] < d1[t] / 2 && d2[e.X] < d1[t] / 2 && d1[i] + e.Y + d2[e.X] == d1[t])
                {
                    all -= (((c1[i]*c2[e.X])%mod)*(c1[i]*c2[e.X]%mod)) % mod;
                    all += mod;
                    all %= mod;
                }
        }
    }
    cout  << all << '\n';
    return 0;
}
