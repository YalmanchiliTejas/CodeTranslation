#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int n, m;
int s, t;
long long dist[2][500000];
long long ways[2][500000];
vector<pair<int, int> > graph[500000];
long long ans = 0;

void djkstra(int v, int slot)
{
    set<pair<long long, int> > s;
    s.insert({0, v});
    for (int i = 1; i <= n; i++) dist[slot][i] = 1e18;
    dist[slot][v] = 0;
    ways[slot][v] = 1;
    while (s.size())
    {
        auto it = s.begin();
        s.erase(s.begin());
        int u = (*it).second;
        for (auto e : graph[u])
        {
            int weight = e.second;
            int ver = e.first;
            if (dist[slot][ver] < dist[slot][u] + weight) continue;
            if (dist[slot][ver] > dist[slot][u] + weight)
            {
                s.erase({dist[slot][ver], ver});
                dist[slot][ver] = dist[slot][u] + weight;
                ways[slot][ver] = 0;
                s.insert({dist[slot][ver], ver});
            }
            if (dist[slot][ver] == dist[slot][u] + weight) ways[slot][ver] = (ways[slot][ver] + ways[slot][u]) % MOD;
        }
    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        graph[v].push_back({u, w});
        graph[u].push_back({v, w});
    }
    djkstra(s, 0);
    djkstra(t, 1);
    ans = ways[0][t] * ways[0][t] % MOD;
    long long len = dist[0][t];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int v = graph[i][j].first;
            if (dist[0][i] + dist[1][v] + graph[i][j].second == len && dist[0][i] * 2 < len && dist[0][v] * 2 > len && dist[1][v] * 2 < len && dist[1][i] * 2 > len)
            {
                ans = (ans + MOD - ways[0][i] * ways[0][i] % MOD * ways[1][v] % MOD * ways[1][v] % MOD) % MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[0][i] * 2 == len && dist[1][i] * 2 == len)
        {
            long long up = 0;
            long long down = 0;
            for (int j = 0; j < graph[i].size(); j++)
            {
                int v = graph[i][j].first;
                if ((dist[1][v] + graph[i][j].second) * 2 == len) up = (up + ways[1][v]) % MOD;
                if ((dist[0][v] + graph[i][j].second) * 2 == len) down = (down + ways[0][v]) % MOD;
            }
            ans = (ans + MOD - up * up % MOD * down % MOD * down % MOD) % MOD;
        }
    }
    cout << ans;
}
