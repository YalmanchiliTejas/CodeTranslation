#include <bits/stdc++.h>
using namespace std;

using lint = long long;
using pint = pair<lint, lint>;
#define x first
#define y second

const int maxn = 100004, maxm = 200004, mod = 1000000007;
int n, m, s, t;
lint d1[maxn], d2[maxn];
int c1[maxn], c2[maxn], a[2*maxm], b[2*maxm], d[2*maxm];
vector<pint> g[maxn];

int sum(int x, int y) { return (x+y) % mod; }
int mul(int x, int y) { return (x*(lint)y) % mod; }
int sq(int x) { return mul(x, x); }

void dijkstra(int st, lint *d, int *c) {
    for (int i=1; i<=n; i++) d[i] = 1e17;
    c[st] = 1; d[st] = 0;

    priority_queue<pint, vector<pint>, greater<pint> > q;
    q.emplace(0ll, st);

    while (not q.empty()) {
        int k; lint di; tie(di, k) = q.top(); q.pop();
        if (di > d[k]) continue;
        d[k] = di;
        for (pint i : g[k]) {
            int nk = i.x; lint nd = di + i.y;
            if (nd < d[nk]) d[nk] = nd, c[nk] = 0, q.emplace(nd, nk);
            if (nd == d[nk]) c[nk] = sum(c[nk], c[k]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s >> t;

    for (int i=0; i<m; i++) {
        int x, y; lint k;
        cin >> x >> y >> k;
        a[i] = y; b[i] = x; d[i] = k;
        a[i+m] = x; b[i+m] = y; d[i+m] = k;
        g[x].emplace_back(y, k);
        g[y].emplace_back(x, k);
    }

    dijkstra(s, d1, c1);
    dijkstra(t, d2, c2);

    lint ans = 0;
    for (int i=1; i<=n; i++) if (d1[i] + d2[i] == d1[t] and d1[i] == d2[i]) ans = sum(ans, sq(mul(c1[i], c2[i])));
    for (int i=0; i<2*m; i++) if (d1[a[i]] + d[i] + d2[b[i]] == d1[t] and d1[a[i]] + d[i] > d2[b[i]] and d1[a[i]] < d[i] + d2[b[i]]) ans = sum(ans, sq(mul(c1[a[i]], c2[b[i]])));

    cout << sum(mul(c1[t], c2[s]), mod - ans) << '\n';
}