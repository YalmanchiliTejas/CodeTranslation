#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
typedef pair <int, int> pi;

const int N = 1e5 + 10;
int n, u, v, v2, u2, ans, l, r, pa[N], sz[N];
vector <int> g[N];
pi p[N]; vector <pi> xx, yy;
struct edge { int u, v, w; };
bool operator < (edge a, edge b) { return a.w < b.w; }
vector <edge> e;

int root(int v) {
    return (pa[v] == v) ? v : pa[v] = root(pa[v]);
}

bool same(int u, int v) {
    return root(u) == root(v);
}

void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    pa[v] = u;
}

void kruskal() {
    for (int i = 0; i < n; ++i)
        pa[i] = i, sz[i] = 1;
    sort(e.begin(), e.end());
    for (auto i: e) {
        if (!same(i.u, i.v)) {
            merge(i.u, i.v);
            ans += i.w;
        }
    }
}

int f(int i, int j) {
    return min(abs(p[i].x - p[j].x), abs(p[i].y - p[j].y));
}

void make_graph() {
    for (int i = 0; i < n; ++i) {
        l = max(i - 3, 0ll), r = min(i + 3, n);
        v = xx[i].y;
        v2 = yy[i].y;
        for (int j = l; j < r; ++j) {
            u = xx[j].y;
            u2 = yy[j].y;
            if (v < u)
                e.push_back({v, u, f(v, u)});
            if (v2 < u2)
                e.push_back({v2, u2, f(v2, u2)});
        }
    }
}

main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        xx.push_back({p[i].x, i});
        yy.push_back({p[i].y, i});
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    make_graph();
    kruskal();
    cout << ans << '\n';
    return 0;
}
