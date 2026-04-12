#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)

struct edge {
    int u, v, cost;
    edge() {}
    edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

/* UnionFindTree Begin
  --------------------------------------------------------------------------
*/
class UnionFind {
private:
    int size_;
    vector<int> par, rank;
public:
    UnionFind() : size_(0), par(vector<int>(0)), rank(vector<int>(0)) {}
    UnionFind(int size_) : size_(size_) {
        par.resize(size_), rank.resize(size_);
        rep(i,size_) par[i] = i, rank[i] = 0;
    }
    // 現在のsize_を返す
    int size() { return size_; }
    // 親を返す
    int root(int x) { return (par[x] == x) ? x : par[x] = root(par[x]); }
    // ２つの頂点を連結する
    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
    // 親が同じかを判定する
    bool same(int x, int y) { return root(x) == root(y); }
};
/* UnionFindTree End
  --------------------------------------------------------------------------
*/

int n, a, b;
vector<pair<int, int> > x, y;
vector<edge> e;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        x.push_back(make_pair(a, i));
        y.push_back(make_pair(b, i));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long ans = 0, cnt = 0, size_ = 0;
    UnionFind uf(n);

    for (int i = 1; i < n; ++i) {
        if (x[i].second != x[i-1].second) {
            e.push_back(edge(x[i-1].second, x[i].second, abs(x[i].first - x[i-1].first)));
            size_++;
        }
        if (y[i].second != y[i-1].second) {
            e.push_back(edge(y[i-1].second, y[i].second, abs(y[i].first - y[i-1].first)));
            size_++;
        }
    }

    edge eg;

    sort(e.begin(), e.end(), comp);

    for (int i = 0; i < size_; ++i) {
        eg = e[i];
        if (!uf.same(eg.u, eg.v)) {
            uf.unite(eg.u, eg.v);
            cnt++;
            ans += eg.cost;
            //cout << eg.cost << " " << eg.u << " " << eg.v << endl;
        }

        if (cnt == n - 1) break;
    }

    printf("%lld\n", ans);

    return 0;
}