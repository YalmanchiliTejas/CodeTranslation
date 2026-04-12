#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct edge {
    int from;
    int to;
    long long cost;
    edge(int _from, int _to, long long _cost) : from(_from), to(_to), cost(_cost) {}
};

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;
    dsu(int _n)
        : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }
};

vector<int> min_span(vector<edge> edges, int n, long long &ans) {
    vector<int> order(edges.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return edges[a].cost < edges[b].cost;
    });
    vector<int> res;
    ans = 0;
    dsu d(n);
    for (int id : order) {
        edge e = edges[id];
        if (d.get(e.from) != d.get(e.to)) {
            d.unite(e.from, e.to);
            res.emplace_back(id);
            ans += e.cost;
        }
    }
    if ((int)res.size() != n) {
        return vector<int>();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        a[i] = make_pair(x[i], y[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    int s = x.size(), t = y.size();
    dsu uf(s + t);
    for (int i = 0; i < n; i++) {
        int b = lower_bound(x.begin(), x.end(), a[i].first) - x.begin();
        int c = lower_bound(y.begin(), y.end(), a[i].second) - y.begin();
        uf.unite(b, s + c);
    }
    int m = 0;
    map<int, int> mp;
    for (int i = 0; i < s + t; i++) {
        if (uf.get(i) == i) {
            mp[uf.get(i)] = m;
            m++;
        }
    }
    vector<edge> edges;
    for (int i = 1; i < s; i++) {
        int b = mp[uf.get(i - 1)], c = mp[uf.get(i)];
        if (b != c) {
            edges.emplace_back(b, c, x[i] - x[i - 1]);
        }
    }
    for (int i = 1; i < t; i++) {
        int b = mp[uf.get(s + i - 1)], c = mp[uf.get(s + i)];
        if (b != c) {
            edges.emplace_back(b, c, y[i] - y[i - 1]);
        }
    }
    debug(mp);
    debug(m, s, t);
    debug(x, y);
    for (auto e : edges) {
        debug(e.from, e.to, e.cost);
    }
    ll ans;
    min_span(edges, m, ans);
    debug(min_span(edges, m, ans));
    cout << ans << '\n';
    return 0;
}