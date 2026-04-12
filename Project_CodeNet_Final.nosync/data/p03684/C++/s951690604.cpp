#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define int long long
struct UnionFind {
    int size_;
    vector<int> par;
    vector<int> rank;
    vector<int> sz;

    UnionFind(int size_) : size_(size_) {
        par.resize(size_);
        rank.resize(size_);
        sz.resize(size_);

        for (int i = 0; i < size_; i++) {
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }

    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[y] < rank[x]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;

        par[x] = y;
        sz[y] += sz[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return sz[find(x)]; }
};
int N;
using P = pair<int, int>;
vector<P> pos;
struct Edge {
    int from, to, cost;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    bool operator<(const Edge &rhs) const { return cost < rhs.cost; }
};
vector<Edge> es;
map<P, int> ids;
int cost(P p1, P p2) {
    return min(abs(p1.first - p2.first), abs(p1.second - p2.second));
}
void add_edge(P p1, P p2) {
    int a = ids[p1];
    int b = ids[p2];
    int c = cost(p1, p2);
    es.push_back(Edge(a, b, c));
    es.push_back(Edge(b, a, c));
}
void add() {
    sort(all(pos));
    rep(i, N) if (i) {
        add_edge(pos[i - 1], pos[i]);
        if (i + 1 < N) add_edge(pos[i], pos[i + 1]);
    }
    sort(all(pos), [](const P &p1, const P &p2) {
        return P(p1.second, p1.first) < P(p2.second, p2.first);
    });
    rep(i, N) if (i) {
        // cout << pos[i].first << ", " << pos[i].second << endl;
        add_edge(pos[i - 1], pos[i]);
        if (i + 1 < N) add_edge(pos[i], pos[i + 1]);
    }
}
signed main() {
    cin >> N;
    es.reserve(2 * N);
    rep(i, N) {
        P p;
        cin >> p.first >> p.second;
        if (ids.count(p)) continue;
        int n = ids.size();
        ids[p] = n;
        pos.push_back(p);
    }
    N = pos.size();
    add();
    // cout << es.size() << endl;
    sort(all(es));
    UnionFind uf(N);
    long long ans = 0;
    for (auto e : es) {
        if (!uf.same(e.from, e.to)) {
            ans += e.cost;
            uf.unite(e.from, e.to);
        }
    }
    cout << ans << endl;

    return 0;
}
