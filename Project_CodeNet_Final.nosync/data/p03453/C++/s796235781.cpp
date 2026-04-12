#include <bits/stdc++.h>

#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
vector<T> Vec(int n, T v)
{
    return vector<T>(n, v);
}
template <class... Args>
auto Vec(int n, Args... args)
{
    auto val = Vec(args...);
    return vector<decltype(val)>(n, move(val));
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = (ll)1e9 + 7LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 100;

struct CostGraph {
    using T = ll;
    CostGraph(const int v) : V{v}
    {
        edge.resize(v);
        rev_edge.resize(v);
    }
    struct Edge {
        Edge(const int from, const int to, const T cost) : from{from}, to{to}, cost{cost} {}
        const int from;
        const int to;
        const T cost;
        bool operator<(const Edge& e) const
        {
            return cost != e.cost ? cost < e.cost : to < e.to;
        }
    };
    void addEdge(const int from, const int to, const T cost = 1)
    {
        edge[from].push_back(Edge{from, to, cost});
        rev_edge[to].push_back(Edge(to, from, cost));
    }
    vector<vector<Edge>> edge;
    vector<vector<Edge>> rev_edge;
    const int V;
};

void Dijkstra(const CostGraph& g, const int s, vector<CostGraph::T>& d)
{
    using T = CostGraph::T;
    assert(s < g.V);
    assert(d.size() == g.V);
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    for (int i = 0; i < g.V; i++) {
        d[i] = INF<T>;
    }
    d[s] = 0;
    q.push(make_pair(0, s));
    while (not q.empty()) {
        const P& p = q.top();
        const T cost = p.first;
        const int v = p.second;
        q.pop();
        if (d[v] < cost) {
            continue;
        }
        for (const auto& e : g.edge[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.push(make_pair(d[e.to], e.to));
            }
        }
    }
}

struct Graph {
    Graph(const int v) : V{v}
    {
        edge.resize(v);
        rev_edge.resize(v);
    }
    void addEdge(const int from, const int to)
    {
        edge[from].push_back(to);
        rev_edge[to].push_back(from);
    }
    vector<vector<int>> edge;
    vector<vector<int>> rev_edge;
    const int V;
};

bool dfs_topo(const Graph& g, const int s, vector<int>& used, vector<int>& srt)
{
    assert(s < g.V);
    assert(used.size() == g.V);
    if (used[s] == 1) {
        return false;
    } else if (used[s] == 0) {
        used[s] = 1;
        for (const int to : g.edge[s]) {
            if (not dfs_topo(g, to, used, srt)) {
                return false;
            }
        }
        used[s] = 2;
        srt.push_back(s);
    }
    return true;
}

bool TopologocalSort(const Graph& g, vector<int>& srt)  // 有向グラフ
{
    srt.clear();
    vector<int> used(g.V, 0);
    for (int i = 0; i < g.V; i++) {
        if (not dfs_topo(g, i, used, srt)) {
            return false;
        }
    }
    reverse(srt.begin(), srt.end());
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int S, T;
    cin >> S >> T;
    S--, T--;
    CostGraph g(N);
    using E = pair<pair<int, int>, ll>;
    vector<E> edge(M);
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        edge[i] = {{u, v}, 2 * d};
        g.addEdge(u, v, 2 * d);
        g.addEdge(v, u, 2 * d);
    }
    vector<ll> d(N, INF<ll>);
    vector<ll> revd(N, INF<ll>);
    Dijkstra(g, S, d);
    Dijkstra(g, T, revd);
    const ll tim = d[T];
    const ll half = d[T] / 2;
    Graph dag(N);
    using P = pair<int, int>;
    vector<P> used;
    for (int i = 0; i < M; i++) {
        const int u = edge[i].first.first;
        const int v = edge[i].first.second;
        const ll c = edge[i].second;
        if (d[u] + revd[v] + c == tim) {
            dag.addEdge(u, v);
            used.push_back({u, v});
        } else if (revd[u] + d[v] + c == tim) {
            dag.addEdge(v, u);
            used.push_back({v, u});
        }
    }
    vector<int> srt(N);
    TopologocalSort(dag, srt);
    vector<ll> dp1(N, 0);
    dp1[S] = 1;
    for (int i = 0; i < N; i++) {
        const int s = srt[i];
        for (const int to : dag.edge[s]) {
            dp1[to] += dp1[s];
            dp1[to] %= MOD;
        }
    }
    vector<ll> dp2(N, 0);
    dp2[T] = 1;
    for (int i = N - 1; i >= 0; i--) {
        const int s = srt[i];
        for (const int to : dag.rev_edge[s]) {
            dp2[to] += dp2[s];
            dp2[to] %= MOD;
        }
    }
    ll sum = (dp1[T] * dp1[T]) % MOD;
    ll minus = 0;
    for (const auto& e : used) {
        const int u = e.first;
        const int v = e.second;
        if (d[u] < half and d[v] > half) {
            minus += (((dp1[u] * dp2[v]) % MOD) * ((dp1[u] * dp2[v]) % MOD)) % MOD;
            minus %= MOD;
        }
    }
    for (int i = 0; i < N; i++) {
        if (d[i] == half) {
            minus += (((dp1[i] * dp2[i]) % MOD) * (((dp1[i] * dp2[i]) % MOD))) % MOD;
            minus %= MOD;
        }
    }
    cout << (sum - minus + MOD) % MOD << endl;

    return 0;
}
