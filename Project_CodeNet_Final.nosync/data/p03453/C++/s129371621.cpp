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
    void addEdge(const int from, const int to, const T cost)
    {
        edge[from].push_back(Edge{from, to, cost});
        rev_edge[to].push_back(Edge(to, from, cost));
    }
    vector<vector<Edge>> edge;
    vector<vector<Edge>> rev_edge;
    const int V;
};

void Dijkstra(const CostGraph& g, const int s, vector<pair<CostGraph::T, ll>>& d)
{
    using P = pair<CostGraph::T, ll>;
    auto add = [](const P& a, const P& b) {
        return (a.first < b.first) ? a : (a.first > b.first) ? b : P{a.first, (a.second + b.second) % MOD};
    };
    auto mul = [](const P& a, const P& b) {
        return P{a.first + b.first, a.second * b.second % MOD};
    };
    constexpr P ZERO = {INF<CostGraph::T>, 0};
    constexpr P ONE = {0, 1};

    using PP = pair<P, int>;
    assert(s < g.V);
    assert(d.size() == g.V);
    vector<bool> used(g.V, false);
    priority_queue<PP, vector<PP>, greater<PP>> q;
    for (int i = 0; i < g.V; i++) {
        d[i] = ZERO;
    }
    d[s] = ONE;
    q.push({ONE, s});
    while (not q.empty()) {
        const PP& p = q.top();
        const int v = p.second;
        q.pop();
        if (used[v]) {
            continue;
        }
        used[v] = true;
        for (const auto& e : g.edge[v]) {
            const int to = e.to;
            const ll cost = e.cost;
            d[to] = add(d[to], mul(d[v], {cost, 1}));
            q.push({d[e.to], e.to});
        }
    }
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
    vector<CostGraph::Edge> edge;
    for (int i = 0; i < M; i++) {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        u--, v--;
        edge.push_back(CostGraph::Edge{u, v, 2 * d});
        g.addEdge(u, v, 2 * d);
        g.addEdge(v, u, 2 * d);
    }
    using P = pair<ll, ll>;
    vector<P> d(N);
    vector<P> revd(N);
    Dijkstra(g, S, d);
    Dijkstra(g, T, revd);
    const ll L = d[T].first;
    const ll Half = L / 2;
    const ll Total = d[T].second * d[T].second % MOD;
    ll minus = 0;
    for (int i = 0; i < N; i++) {
        if (d[i].first == Half and revd[i].first == Half) {
            const ll p = d[i].second * revd[i].second % MOD;
            minus += (p * p % MOD);
            minus %= MOD;
        }
    }
    for (int i = 0; i < M; i++) {
        const int u = edge[i].from;
        const int v = edge[i].to;
        const ll cost = edge[i].cost;
        if (d[u].first + revd[v].first + cost == L) {
            if (d[u].first < Half and d[v].first > Half) {
                const ll p = d[u].second * revd[v].second % MOD;
                minus += (p * p % MOD);
                minus %= MOD;
            }
        } else if (revd[u].first + d[v].first + cost == L) {
            if (d[u].first > Half and d[v].first < Half) {
                const ll p = revd[u].second * d[v].second % MOD;
                minus += (p * p % MOD);
                minus %= MOD;
            }
        }
    }
    cout << (Total + MOD - minus) % MOD << endl;

    return 0;
}
