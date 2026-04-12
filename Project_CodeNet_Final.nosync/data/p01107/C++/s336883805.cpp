#include <bits/stdc++.h>
using namespace std;

template <typename Edge>
class graph {
    using graph_t = std::vector<std::vector<Edge>>;
public:
    using reference = std::vector<Edge>&;
    using const_reference = std::vector<Edge> const&;
    using iterator = typename graph_t::iterator;
    using const_iterator = typename graph_t::const_iterator;
    using reverse_iterator = typename graph_t::reverse_iterator;

    graph() : g() {}
    graph(int n) : g(n) {}

    reference operator[](int x) { return g[x]; }
    const_reference operator[](int x) const { return g[x]; }

    iterator begin() { return std::begin(g); }
    const_iterator begin() const { return std::begin(g); }
    iterator end() { return std::end(g); }
    const_iterator end() const { return std::end(g); }
    reverse_iterator rbegin() { return std::rbegin(g); }
    reverse_iterator rend() { return std::rend(g); }

    int size() const { return g.size(); }

    void add_node(std::vector<Edge> es) {
        g.push_back(std::move(es));
    }

private:
    std::vector<std::vector<Edge>> g;
};

template <typename Capacity>
struct capacity_edge {
    using capacity_type = Capacity;
    int to, rev;
    capacity_type cap;
    capacity_edge(int t, int r, capacity_type c) : to(t), rev(r), cap(c) {}
};

template <typename Capacity>
using capacity_graph = graph<capacity_edge<Capacity>>;

template <typename Capacity>
void add_edge(capacity_graph<Capacity>& g, int from, int to, Capacity cap) {
    g[from].emplace_back(to, static_cast<int>(g[to].size()), cap);
    g[to].emplace_back(from, static_cast<int>(g[from].size() - 1), Capacity{0});
}

template <typename Edge, typename Capacity = typename Edge::capacity_type>
Capacity augument(graph<Edge>& g, std::vector<bool>& used, int v, int t, Capacity f) {
    if(v == t) return f;
    used[v] = true;
    for(auto& e : g[v]) {
        if(!used[e.to] && e.cap > 0) {
            auto d = augument(g, used, e.to, t, std::min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

template <typename Edge, typename Capacity = typename Edge::capacity_type>
Capacity max_flow(graph<Edge>& g, int s, int t) {
    Capacity flow = 0;
    std::vector<bool> used(g.size(), false);
    while(true) {
        std::fill(std::begin(used), std::end(used), false);
        const auto f = augument(g, used, s, t, std::numeric_limits<Capacity>::max() / 2);
        if(f == 0) return flow;
        flow += f;
    }
}

constexpr int dx[4] = {0, 1, 0, -1};
constexpr int dy[4] = {1, 0, -1, 0};

int main() {
    int n, m;
    while(cin >> n >> m, n) {
        vector<string> s(n);
        for(int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        capacity_graph<int> g1(2 * n * m);
        auto in_range = [&] (int y, int x) {
            return 0 <= y && y < n && 0 <= x && x < m;
        };
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                    add_edge(g1, i * m + j, i * m + j + n * m, 2);
                } else {
                    add_edge(g1, i * m + j, i * m + j + n * m, 1);
                }
                if(s[i][j] == '#') continue;
                for(int k = 0; k < 4; ++k) {
                    const int ny = i + dy[k], nx = j + dx[k];
                    if(!in_range(ny, nx) || s[ny][nx] == '#') continue;
                    add_edge(g1, i * m + j + n * m, ny * m + nx, 1);
                }
            }
        }
        auto g2 = g1;

        if(max_flow(g1, 0, (n - 1) * m + m - 1) == 2 && max_flow(g2, (n - 1) * m, m - 1) == 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
