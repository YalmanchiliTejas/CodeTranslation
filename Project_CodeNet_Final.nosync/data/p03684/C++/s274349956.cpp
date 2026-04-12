#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<ll, ll>;


ll mabs(ll x) {
    return x > 0 ? x : -x;
}

ll dist(const pii& a, const pii& b) {
    return min(mabs(a.first - b.first), mabs(a.second - b.second));
}

struct Dsu {
    vector<int> p;

    Dsu(int n): p(n) {
        iota(p.begin(), p.end(), 0);
    }

    int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        p[a] = b;
        return a != b;
    }
};

struct Edge {
    ll len;
    int a;
    int b;

    Edge(ll l, int aa, int bb): len(l), a(aa), b(bb) {}

    bool operator<(const Edge& e) const {
        return len < e.len;
    }
};

int main() {
#ifdef LOCAL
    // freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    cin >> n;
    vector<pii> ps(n);
    for (int i = 0; i < n; i++)
        cin >> ps[i].first >> ps[i].second;
    vector<Edge> es;
    vector<pair<pii, int>> xs(n);
    for (int i = 0; i < n; i++)
        xs[i] = {ps[i], i};
    for (int rep = 0; rep < 2; rep++) {
        sort(xs.begin(), xs.end());
        for (int i = 0; i < n - 1; i++)
            es.push_back(Edge(dist(xs[i].first, xs[i + 1].first), xs[i].second, xs[i + 1].second));
        for (int i = 0; i < n; i++)
            swap(xs[i].first.first, xs[i].first.second);
    }
    Dsu d(n);
    ll res = 0;
    sort(es.begin(), es.end());
    for (auto e : es)
        if (d.unite(e.a, e.b))
            res += e.len;
    cout << res << "\n";
}