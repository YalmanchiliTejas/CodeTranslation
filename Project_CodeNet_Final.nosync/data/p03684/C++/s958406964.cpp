#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long lint;

struct UnionFind {
    vector<int> par;
    int n, cnt;
    UnionFind(const int& x = 0) {init(x);}
    void init(const int& x) {par.assign(cnt=n=x, -1);}
    inline int find(const int& x) {return par[x] < 0 ? x : par[x] = find(par[x]);}
    inline bool same(const int& x, const int& y) {return find(x) == find(y);}
    inline bool unite(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return false;
        --cnt;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    inline int count() const {return cnt;}
    inline int count(int x) {return -par[find(x)];}
};

struct Edge {
    lint cost;
    int u;
    int v;
    Edge() {}
    Edge(lint cost, int u, int v) : cost(cost), u(u), v(v) {}
};

const int MAXN = 111111;
int X[MAXN], Y[MAXN];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    vector<pair<int, int> > xs(N), ys(N);
    for (int i = 0; i < N; i++) {
        xs[i] = make_pair(X[i], i);
        ys[i] = make_pair(Y[i], i);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    vector<Edge> es;
    for (int i = 0; i < N-1; i++) {
        // X
        int u = xs[i].second, v = xs[i+1].second;
        lint cost = min(abs(X[u] - X[v]), abs(Y[u] - Y[v]));
        es.emplace_back(cost, u, v);
        // Y
        u = ys[i].second, v = ys[i+1].second;
        cost = min(abs(X[u] - X[v]), abs(Y[u] - Y[v]));
        es.emplace_back(cost, u, v);
    }
    // minimum-cost-tree
    sort(es.begin(), es.end(), [](const Edge& lhs, const Edge& rhs) {return lhs.cost < rhs.cost;});
    UnionFind uf(N);
    lint ans = 0;
    for (const Edge& e : es) {
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            ans += e.cost;
        }
    }
    cout << ans << endl;
    return 0;
}