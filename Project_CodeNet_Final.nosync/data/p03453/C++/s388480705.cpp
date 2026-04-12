#include <bits/stdc++.h>

using namespace std;

#define MXN 100005
#define x first
#define y second
// #define debug

typedef long long int LLI;
typedef pair<LLI,LLI> PII;

const int mod = 1e9+7;

vector<PII> edges[MXN];
LLI dist[2][MXN], ways[2][MXN];
priority_queue<PII, vector<PII>, greater<PII> > pq;
int u[MXN<<1], v[MXN<<1], d[MXN<<1];
bool meet[MXN];

void djikstra(int w, LLI cur) {
    dist[w][cur] = 0;
    ways[w][cur] = 1;
    pq.push({0LL, cur});
    LLI d;
    while (pq.size()) {
        d = pq.top().x, cur = pq.top().y;
        pq.pop();
        if (d > dist[w][cur]) continue;
        for (PII nxt : edges[cur]) {
            if (dist[w][nxt.x] > dist[w][cur] + nxt.y) {
                dist[w][nxt.x] = dist[w][cur] + nxt.y;
                ways[w][nxt.x] = ways[w][cur];
                pq.push({dist[w][nxt.x], nxt.x});
            } else if (dist[w][nxt.x] == dist[w][cur] + nxt.y) {
                ways[w][nxt.x] += ways[w][cur];
                if (ways[w][nxt.x] >= mod) ways[w][nxt.x] -= mod;
            }
        }
    }
}

inline LLI sqmod(LLI k) {
    return (k*k) % mod;
}

int main() { 
    int n, m, s, t;
    while (cin >> n >> m >> s >> t) {
        for (int i = 0; i < m; ++i) {
            cin >> u[i] >> v[i] >> d[i];
            edges[u[i]].emplace_back(v[i], d[i]);
            edges[v[i]].emplace_back(u[i], d[i]);
        }
        memset(dist, 0x3f, sizeof(dist));
        memset(ways, 0, sizeof(ways));
        djikstra(0, s);
        djikstra(1, t);
#ifdef debug
        cout << dist[0][t] << " " << ways[0][t] << "\n";
        cout << dist[1][s] << " " << ways[1][s] << "\n";
#endif
        assert(dist[0][t] == dist[1][s]);
        assert(ways[0][t] == ways[1][s]);
        LLI tmp, total = sqmod(ways[0][t]);
        memset(meet, 0, sizeof(meet));
        for (int i = 1; i <= n; ++i) { // check vertices
            if (dist[0][i] == dist[1][i] && dist[0][i] + dist[1][i] == dist[0][t]) {
                tmp = (sqmod(ways[0][i]) * sqmod(ways[1][i])) % mod;
                meet[i] = 1;
#ifdef debug
                cout << "meet at " << i << " and subtract " << tmp << "\n";
#endif
                total -= tmp;
                if (total < 0) total += mod;
            }
        }
        for (int i = 0; i < m; ++i) { // check edges
            if (meet[u[i]] || meet[v[i]]) continue;
            if (dist[0][u[i]] + d[i] + dist[1][v[i]] == dist[0][t]) { // from u to v
                if ((dist[0][u[i]]<<1) < dist[0][t] && ((dist[0][u[i]] + d[i])<<1) > dist[0][t] &&
                        (dist[1][v[i]]<<1) < dist[0][t] && ((dist[1][v[i]] + d[i])<<1) > dist[0][t]) {
                    tmp = (sqmod(ways[0][u[i]]) * sqmod(ways[1][v[i]])) % mod;
#ifdef debug
                    cout << "meet between " << u[i] << " and " << v[i] << " and subtract " << tmp << "\n";
#endif
                    total -= tmp;
                    if (total < 0) total += mod;
                }
            }
            if (dist[1][u[i]] + d[i] + dist[0][v[i]] == dist[0][t]) {
                if ((dist[1][u[i]]<<1) < dist[0][t] && ((dist[1][u[i]] + d[i])<<1) > dist[0][t] &&
                        (dist[0][v[i]]<<1) < dist[0][t] && ((dist[0][v[i]] + d[i])<<1) > dist[0][t]) {
                    tmp = (sqmod(ways[1][u[i]]) * sqmod(ways[0][v[i]])) % mod;
#ifdef debug
                    cout << "meet between " << v[i] << " and " << u[i] << " and subtract " << tmp << "\n";
#endif
                    total -= tmp;
                    if (total < 0) total += mod;
                }
            }
        }
        total = (total + mod) % mod;
        cout << total << "\n";
        for (int i = 1; i <= n; ++i) edges[i].clear();
    }

    return 0;
}
