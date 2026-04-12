#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct edge { int dst, cost; };
vector<vector<edge> > adj;
const int M = 1000000007;

void sssp(int start, vector<long long> &dist, vector<long long> &cnt) {
    dist[start] = 0;
    cnt[start] = 1;
    priority_queue<pair<long long, int> > pq;
    pq.push({0, start});
    while (!pq.empty()) {
        long long d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d < dist[u]) continue;
        for (edge e : adj[u]) {
            if (dist[e.dst] > e.cost + d) {
                dist[e.dst] = e.cost + d;
                cnt[e.dst] = cnt[u];
                pq.push({-dist[e.dst], e.dst});
            } else if (dist[e.dst] == e.cost + d) {
                (cnt[e.dst] += cnt[u]) %= M;
            }
        }
    }
}

int main() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    s--; t--;
    adj.resize(n);
    while (m--) {
        int u, v, d; cin >> u >> v >> d;
        u--; v--;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    const long long INF = 1LL<<60;
    vector<long long> dist_s(n, INF), dist_t(n, INF), cnt_s(n, 0), cnt_t(n, 0);
    sssp(s, dist_s, cnt_s);
    sssp(t, dist_t, cnt_t);

    long long ans = cnt_s[t] * cnt_t[s];
    
    for (int i = 0; i < n; i++) {
        if (dist_s[i] + dist_t[i] == dist_s[t] && 
            dist_s[i] == dist_t[i]) {
            long long p = cnt_s[i] * cnt_t[i] % M;
            ans -= p * p % M;
        }
        for (edge e : adj[i]) {
            int j = e.dst;
            if (dist_s[i] + dist_t[j] + e.cost == dist_s[t] && 
                dist_t[j] < dist_s[i] + e.cost &&
                dist_s[i] < dist_t[j] + e.cost) {
                long long p = cnt_s[i] * cnt_t[j] % M;
                ans -= p * p % M;
            }
        }
    }
    cout << (ans % M + M) % M << endl;
}
