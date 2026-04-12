#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int (i)=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()

using P = pair<int, int>;

struct UnionFind {
    vector<int> p;
    UnionFind(int n) : p(n, -1) {};
    bool unite(int u, int v) {
        if ((u = root(u)) == (v = root(v))) return false;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v]; p[v] = u;
        return true;
    }
    bool find(int u, int v) { return root(u) == root(v); }
    int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }
    int size(int u) { return -p[root(u)]; }
};

struct edge {
    int from, to, cost;
    edge() {};
    edge(int _from, int _to, int _cost) {
        from = _from; to = _to; cost = _cost;
    };
    bool operator<(const edge& e) {
        if (cost != e.cost) return cost < e.cost;
        if (from != e.from) return from < e.from;
        if (to != e.to) return to < e.to;
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    vector<P> px(n), py(n);
    rep(i, n) {
        int x, y; scanf("%d%d", &x, &y);
        x--; y--;
        px[i] = P(x, i);
        py[i] = P(y, i);
    }
    sort(ALL(px));
    sort(ALL(py));

    vector<edge> es;
    rep(i, n - 1) {
        int dx = abs(px[i + 1].first - px[i].first);
        int dy = abs(py[i + 1].first - py[i].first);
        es.push_back(edge(px[i].second, px[i + 1].second, dx));
        es.push_back(edge(py[i].second, py[i + 1].second, dy));
    }
    sort(ALL(es));

    ll ans = 0;
    UnionFind uf(n);
    for (edge& e : es) {
        int u = e.from, v = e.to;
        if (uf.unite(u, v)) {
            ans += e.cost;
        }
    }

    cout << ans << endl;
    return 0;
}