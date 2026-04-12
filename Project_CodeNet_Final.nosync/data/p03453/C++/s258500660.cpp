#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
constexpr lint MOD = 1000000007;

struct UndirectedGraph
{
    using Pint = pair<int, int>;
    using Plint = pair<lint, int>;
    int V;
    int E;
    vector<lint> weights;
    vector<vector<Pint>> to;
    vector<Pint> edges;

    UndirectedGraph(int V) : V(V), E(0),
                             to(vector<vector<Pint>>(V)) {}

    void add_edge(int v1, int v2, lint w)
    {
        to[v1].push_back(Pint(v2, E));
        to[v2].push_back(Pint(v1, E));
        edges.push_back(Pint(v1, v2));
        weights.push_back(w);
        E++;
    }

    vector<lint> dist;
    void dijkstra(int start)
    {
        dist = vector<lint>(V, -1);
        priority_queue<Plint, vector<Plint>, greater<Plint>> pq;
        pq.push(Plint(0, start));

        while (!pq.empty()) {
            Plint p = pq.top(); pq.pop();
            int v = p.second;
            if (dist[v] >= 0 && dist[v] <= p.first) continue;
            dist[v] = p.first;
            // cout << "dist[" << v << "] = " << p.first << endl;
            for (auto vnxt : to[v]) {
                lint dnxt = dist[v] + weights[vnxt.second];
                if (dnxt < dist[vnxt.first] || dist[vnxt.first] < 0) {
                    pq.push(Plint(dnxt, vnxt.first));
                }
            }
        }
    }

    vector<lint> patterns(int s, vector<lint> &d)
    {
        vector<lint> ans(V); ans[s] = 1;
        priority_queue<Plint, vector<Plint>, greater<Plint>> pq;
        for (int i = 0; i < V; i++) pq.push(Plint(d[i], i));
        while (!pq.empty())
        {
            Plint p = pq.top(); pq.pop();
            for (auto v : to[p.second]) if (d[v.first] + weights[v.second] == p.first) (ans[p.second] += ans[v.first]) %= MOD;
        }
        return ans;
    }
};

int N, M, S, T;

int main()
{
    cin >> N >> M >> S >> T;
    S--; T--;

    UndirectedGraph graph(N);
    for (int i = 0; i < M; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        graph.add_edge(u, v, d);
    }


    graph.dijkstra(S);
    vector<lint> dist_f = graph.dist;
    vector<lint> dp1 = graph.patterns(S, dist_f);

    graph.dijkstra(T);
    vector<lint> dist_b = graph.dist;
    vector<lint> dp2 = graph.patterns(T, dist_b);

    lint ans = 0;

    lint D = dist_f[T];
    for (int i = 0; i < N; i++) if (dist_f[i] * 2 == D) (ans += (dp1[i] * dp2[i] % MOD) * (dp1[i] * dp2[i] % MOD)) %= MOD;
    for (int i = 0; i < M; i++)
    {
        int v1 = graph.edges[i].first;
        int v2 = graph.edges[i].second;
        if (dist_f[v1] > dist_f[v2]) swap(v1, v2);
        if (dist_f[v1] * 2 < D && dist_b[v2] * 2 < D && dist_f[v1] + dist_b[v2] + graph.weights[i] == D)
        {
            (ans += (dp1[v1] * dp2[v2] % MOD) * (dp1[v1] * dp2[v2] % MOD)) %= MOD;
        }
    }
    cout << (dp1[T] * dp1[T] - ans + MOD) % MOD << endl;
}
