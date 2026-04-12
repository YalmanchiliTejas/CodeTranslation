#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 出会う位置はTとSのちょうど中間点.
// 任意の最短経路に対してこの中間点を求めればよい.
// ここで, 各頂点に対してSからの最短距離とTからの最短距離を求めておく.
// この和がST間の最短距離ならばこの時に限りその頂点を通る最短経路が存在する.
// これを用いて最短経路のみを持つ有向グラフを作ることができる.
// この有向グラフはDAGなのでDPで経路数を求めることができ, 全経路の組から中間点を共有するものを引けばよい.
// これは双方向からDAG経路数を求めて全ての辺と頂点を全探索すれば求められる.

#define mod 1000000007
struct edge{int to; int cost;};
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<edge>>;

// 辺の向きを反転
Graph reverse(Graph &g) {
    Graph res(g.size());
    for (int i = 0; i < g.size(); ++i) {
        for (int x: g[i]) {
            res[x].push_back(i);
        }
    }
    return res;
}

#define INF 1e18
// 重みが非負の時に頂点sから任意の点への最短距離を返す, O(E log V)
vector<ll> dijkstra(int s, WeightedGraph &g) {
    using P = pair<ll, int>; // (最短距離, 頂点)
    vector<ll>res(g.size(), INF);
    res[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (! que.empty()) {
        P t = que.top(); que.pop();
        int v = t.second;
        if (res[v] < t.first) continue;
        for (auto x: g[v]) {
            if (res[x.to] > res[v] + x.cost) {
                res[x.to] = res[v] + x.cost;
                que.push(P(res[x.to], x.to));
            }
        }
    }
    return res;
}

// トポロジカルソート
vector<int> DAG_sort(Graph &g) {
    vector<int>res;
    vector<int>in(g.size(), 0);
    for (int i = 0; i < g.size(); ++i) {
        for (int x: g[i]) in[x]++;
    }
    stack<int>st;
    for (int i = 0; i < g.size(); ++i) {
        if (in[i] == 0) st.push(i);
    }
    while (! st.empty()) {
        int t = st.top(); st.pop();
        res.push_back(t);
        for (int x: g[t]) {
            in[x]--;
            if (in[x] == 0) st.push(x);
        }
    }
    return res;
}

ll sub(ll x, ll y) {
    x -= y;
    if (x < 0) return x + mod;
    return x;
}


int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    WeightedGraph graph(N+1);
    for (int i = 0; i < M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    auto sd = dijkstra(S, graph);
    auto td = dijkstra(T, graph);
    vector<int>flag(N+1, 0);
    for (int i = 1; i <= N; ++i) {
        if (sd[i] + td[i] == sd[T]) flag[i] = 1;
    }

    // 最短経路DAGを求める
    Graph dag(N+1);
    for (int i = 1; i <= N; ++i) {
        if (flag[i] == 0) continue;
        for (auto x: graph[i]) {
            if (flag[x.to] == 0) continue;
            if (sd[x.to] - sd[i] == x.cost) dag[i].push_back(x.to);
        }
    }
    auto dag_rev = reverse(dag);

    // DAGの経路数を求める
    vector<ll>dp(N+1, 0);
    dp[S] = 1;
    for (int x: DAG_sort(dag)) {
        for (int y: dag[x]) {
            (dp[y] += dp[x]) %= mod;
        }
    }
    vector<ll>dp_rev(N+1, 0);
    dp_rev[T] = 1;
    for (int x: DAG_sort(dag_rev)) {
        for (int y: dag_rev[x]) {
            (dp_rev[y] += dp_rev[x]) %= mod;
        }
    }

    ll ans = 0;
    // 頂点を全探索
    for (int i = 1; i <= N; ++i) {
        if (flag[i] == 0 || sd[i] != td[i]) continue;
        ll temp = dp[i] * dp_rev[i] % mod;
        (ans += temp * temp) %= mod;
    }

    // 辺を全探索
    for (int i = 1; i <= N; ++i) {
        for (int x: dag[i]) {
            if (sd[i] * 2 < sd[T] && td[x] * 2 < sd[T]) {
                ll temp = dp[i] * dp_rev[x] % mod;
                (ans += temp * temp) %= mod;
            }
        }
    }

    ans = sub(dp[T] * dp_rev[S] % mod, ans);
    cout << ans << "\n";
    return 0;
}