#include <bits/stdc++.h>
using namespace std;
using Int = long long;
constexpr Int MOD = 1e9+7;
int N, M;
vector<vector<tuple<Int, int, int>>> graph;
void dijkstra(int start, vector<Int>& dist)
{
    using P = pair<Int, int>;
    priority_queue<P, vector<P>, greater<P>> Q;
    vector<bool> visited(N);
    Q.emplace(0, start);
    while (!Q.empty()) {
        Int d, n; tie(d, n) = Q.top();
        Q.pop();
        if (visited[n]) continue;
        visited[n] = true;
        dist[n] = d;
        for (auto& tup : graph[n]) {
            int dd, nn, edge; tie(dd, nn, edge) = tup;
            Q.emplace(d + dd, nn);
        }
    }
}
void counting(int start, vector<Int>& distOpp, vector<Int>& countV, vector<Int>& countE)
{
    using P = pair<Int, int>;
    priority_queue<P, vector<P>, greater<P>> Q;
    vector<bool> visited(N);
    Q.emplace(0, start);
    countV[start] = 1;
    while (!Q.empty()) {
        Int d, n; tie(d, n) = Q.top();
        Q.pop();
        if (visited[n]) continue;
        visited[n] = true;
        for (auto& tup : graph[n]) {
            int dd, nn, id; tie(dd, nn, id) = tup;
            if (distOpp[n] - distOpp[nn] == dd) {
                (countV[nn] += countV[n]) %= MOD;
                (countE[id] += countV[n]) %= MOD;
                Q.emplace(d + dd, nn);
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    int S, T; cin >> S >> T; S--, T--;
    graph.resize(N);
    vector<Int> distS(N), distT(N), countVS(N), countES(M), countVT(N), countET(M);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--, v--;
        edges.emplace_back(u, v, d);
        graph[u].emplace_back(d, v, i);
        graph[v].emplace_back(d, u, i);
    }
    dijkstra(S, distS);
    dijkstra(T, distT);
    counting(S, distT, countVS, countES);
    counting(T, distS, countVT, countET);
    Int all = 0, collision = 0;
    for (int i = 0; i < N; i++) {
        if (distS[i] * 2 == distS[T]) {
            Int pat = countVS[i] * countVT[i] % MOD;
            (all += pat) %= MOD;
            (collision += pat * pat) %= MOD;
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v, d; tie(u, v, d) = edges[i];
        if ( (distS[u] * 2 < distS[T] && distT[v] * 2 < distS[T])
          || (distS[v] * 2 < distS[T] && distT[u] * 2 < distS[T]) ) {
            Int pat = countES[i] * countET[i] % MOD;
            (all += pat) %= MOD;
            (collision += pat * pat) %= MOD;   
        }
    }
    cout << (all * all % MOD - collision + MOD) % MOD << endl;
    return 0;
}
