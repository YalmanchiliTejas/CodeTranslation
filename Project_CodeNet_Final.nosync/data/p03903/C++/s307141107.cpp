#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
typedef long long ll;
using namespace std;
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

struct disjoint_sets {
    vector<int> xs;
    disjoint_sets() = default;
    explicit disjoint_sets(size_t n) : xs(n, -1) {}
    bool is_root(int i) { return xs[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (xs[i] = find_root(xs[i])); }
    int set_size(int i) { return - xs[find_root(i)]; }
    int union_sets(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (set_size(i) < set_size(j)) swap(i,j);
            xs[i] += xs[j];
            xs[j] = i;
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
};
template <typename T> struct weighted_edge_t { int u, v; T w; };
template <typename T> bool operator < (weighted_edge_t<T> const & a, weighted_edge_t<T> const & b) { return make_tuple(a.w, a.u, a.v) < make_tuple(b.w, b.u, b.v); }
template <typename T>
vector<vector<weighted_edge_t<T> > > minimum_spanning_tree(int n, vector<weighted_edge_t<T> > edges) { // Kruskal's method, O(E \log E)
    vector<vector<weighted_edge_t<T> > > tree(n);
    disjoint_sets sets(n);
    whole(sort, edges);
    for (auto e : edges) {
        if (not sets.is_same(e.u, e.v)) {
            sets.union_sets(e.u, e.v);
            tree[e.u].push_back( (weighted_edge_t<T>) { e.u, e.v, e.w } );
            tree[e.v].push_back( (weighted_edge_t<T>) { e.v, e.u, e.w } );
        }
    }
    return tree;
}

int main() {
    int n, m; cin >> n >> m;
    vector<weighted_edge_t<int> > es(m);
    repeat (i,m) {
        int a, b, c; cin >> a >> b >> c; -- a; -- b;
        es[i] = { a, b, c };
    }
    auto mst = minimum_spanning_tree(n, es);
    ll total = 0;
    repeat (i,n) for (auto e : mst[i]) {
        if (e.u < e.v) total += e.w;
    }
    vector<vector<int> > drop = vectors(n, n, int()); {
        repeat (i,n) {
            function<void (int, int)> dfs = [&](int j, int parent) {
                for (auto e : mst[j]) if (e.v != parent) {
                    drop[i][e.v] = max(drop[i][j], e.w);
                    dfs(e.v, j);
                }
            };
            drop[i][i] = 0;
            dfs(i, i);
        }
    }
    int q; cin >> q;
    while (q --) {
        int s, t; cin >> s >> t; -- s; -- t;
        cout << total - drop[s][t] << endl;
    }
    return 0;
}
