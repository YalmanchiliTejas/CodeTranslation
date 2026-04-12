#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
static const int MAXN = 1e5 + 4;
static const int INF = 0x3fffffff;

int n;
int x[MAXN], y[MAXN];
int p[MAXN];

namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline void merge(int u, int v) { u = root(u), v = root(v); p[u] = v; }
}

struct seg {
    int diff, u, v;
    seg() { }
    seg(int diff, int u, int v) : diff(diff), u(u), v(v) { }
    inline bool operator < (const seg &other) const { return diff < other.diff; }
};

std::multiset<seg> sx, sy;

inline bool x_cmp(int a, int b) { return x[a] < x[b]; }
inline bool y_cmp(int a, int b) { return y[a] < y[b]; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);

    for (int i = 0; i < n; ++i) p[i] = i;
    std::sort(p, p + n, x_cmp);
    for (int i = 0; i < n - 1; ++i) sx.insert(seg(x[p[i + 1]] - x[p[i]], p[i + 1], p[i]));
    std::sort(p, p + n, y_cmp);
    for (int i = 0; i < n - 1; ++i) sy.insert(seg(y[p[i + 1]] - y[p[i]], p[i + 1], p[i]));

    long long ans = 0;
    dsu::init(n);
    for (int i = 0; i < n - 1; ++i) {
        seg tx, ty;
        while (!sx.empty()) {
            tx = *sx.begin();
            if (dsu::root(tx.u) == dsu::root(tx.v)) sx.erase(sx.begin());
            else break;
        }
        if (sx.empty()) tx = seg(INF, 0, 0);
        while (!sy.empty()) {
            ty = *sy.begin();
            if (dsu::root(ty.u) == dsu::root(ty.v)) sy.erase(sy.begin());
            else break;
        }
        if (sy.empty()) ty = seg(INF, 0, 0);

        if (tx < ty) {
            dsu::merge(tx.u, tx.v);
            ans += tx.diff;
            sx.erase(sx.begin());
        } else {
            dsu::merge(ty.u, ty.v);
            ans += ty.diff;
            sy.erase(sy.begin());
        }
    }
    printf("%lld\n", ans);

    return 0;
}
