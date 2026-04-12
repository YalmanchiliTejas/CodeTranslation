#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define RFOR(i, a, b) for (ll i = (b)-1; i >= (a); i--)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep1(i, n) for (ll i = 1; i <= (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define pii pair<int, int>

namespace is_stl_container_impl
{
template <typename T>
struct is_stl_container : false_type {
};
template <typename T, size_t N>
struct is_stl_container<array<T, N>> : true_type {
};
template <typename... Args>
struct is_stl_container<vector<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<deque<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<list<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<forward_list<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<set<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<multiset<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<map<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<multimap<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<unordered_set<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<unordered_multiset<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<unordered_map<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<unordered_multimap<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<stack<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<queue<Args...>> : true_type {
};
template <typename... Args>
struct is_stl_container<priority_queue<Args...>> : true_type {
};
}  // namespace is_stl_container_impl

//type trait to utilize the implementation type traits as well as decay the type
template <typename T>
struct is_stl_container {
    static constexpr bool const value = is_stl_container_impl::is_stl_container<decay_t<T>>::value;
};

template <typename T>
typename enable_if<is_stl_container<T>::value, ostream&>::type operator<<(ostream& os, const T& container)
{
    os << "[";
    for (const auto& p : container) {
        os << p << ",";
    }
    os << "]";
    return os;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


using ll = long long;
constexpr ll MOD = 1000000007;

template <typename T>
constexpr T INF = numeric_limits<T>::inf() / 100;

struct UDGraph {
    using T = ll;
    UDGraph(const int v) : V(v)
    {
        edge.resize(v);
    }
    void addEdge(const int from, const int to, const T cost)
    {
        edge[from].pb(Edge{from, to, cost});
        edge[to].pb(Edge{to, from, cost});
    }

    struct Edge {
        Edge(const int from, const int to, const T cost) : from(from), to(to), cost(cost) {}
        int from;
        int to;
        T cost;
        bool operator<(const Edge& e) const
        {
            return cost != e.cost ? cost < e.cost : to < e.to;
        }
    };

    const int V;
    vector<vector<Edge>> edge;
};

class DisjointSets
{
public:
    DisjointSets(const int v)
    {
        m_parent.resize(v);
        m_rank.resize(v);
        m_size.resize(v);
        for (int i = 0; i < v; i++) {
            m_parent[i] = i;
            m_rank[i] = 0;
            m_size[i] = 1;
        }
    }

    bool same(const int a, const int b)
    {
        return find(a) == find(b);
    }


    int find(const int a)
    {
        if (m_parent[a] == a) {
            return a;
        } else {
            return m_parent[a] = find(m_parent[a]);
        }
    }

    void unite(const int a_, const int b_)
    {
        const int a = find(a_);
        const int b = find(b_);
        if (a == b) {
            return;
        }
        if (m_rank[a] > m_rank[b]) {
            m_parent[b] = a;
            m_size[a] += m_size[b];
        } else {
            m_parent[a] = b;
            m_size[b] += m_size[a];
        }
        if (m_rank[a] == m_rank[b]) {
            m_rank[b]++;
        }
    }

    int getSize(const int a)
    {
        return m_size[a];
    }

private:
    vector<int> m_parent;
    vector<int> m_rank;
    vector<int> m_size;
};

void Kruskal(const UDGraph& g, vector<UDGraph::Edge>& edge_set)
{
    edge_set.clear();

    DisjointSets tree{g.V};

    vector<UDGraph::Edge> edges;
    for (int i = 0; i < g.V; i++) {
        for (const auto& e : g.edge[i]) {
            edges.pb(e);
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSets uf(g.V);
    int min_cost = 0;

    rep(ei, edges.size())
    {
        UDGraph::Edge& e = edges[ei];
        if (not uf.same(e.from, e.to)) {
            edge_set.pb(e);
            uf.unite(e.from, e.to);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> pos(n);
    set<pair<ll, int>> xs;
    set<pair<ll, int>> ys;
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        pos[i].first = x;
        pos[i].second = y;
        xs.insert(mp(x, i));
        ys.insert(mp(y, i));
    }

    UDGraph g{n};

    bool first = true;
    pair<ll, int> prev;
    for (auto p : xs) {
        if (first) {
            first = false;
            prev = p;
            continue;
        }
        const int po = p.second;
        const ll x = p.first;
        g.addEdge(prev.second, po, abs(x - prev.first));
        prev = p;
    }

    first = true;
    for (auto p : ys) {
        if (first) {
            first = false;
            prev = p;
            continue;
        }
        const int po = p.second;
        const ll y = p.first;
        g.addEdge(prev.second, po, abs(y - prev.first));
        prev = p;
    }

    vector<UDGraph::Edge> edge;
    Kruskal(g, edge);
    ll sum = 0;
    for (const auto e : edge) {
        sum += e.cost;
    }
    cout << sum << endl;

    return 0;
}
