#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, k, n) for (int i = k; i < n; ++i)
#define fore(i,a) for (auto &i : a)
#define repr(i, n) for (int i = n; i >= 0; --i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int mod = 1000000000 + 7;
const static int inf = INT_MAX / 2;
const static llong INF = LLONG_MAX / 2;
const static double eps = 1e-10;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

struct edge {
    int u, v;
    llong cost;
};

bool comp(const edge &e1, edge &e2) {
    return e1.cost < e2.cost;
}

const static int MAX_N = 200001;

int par[MAX_N + 1], rank_t[MAX_N + 1];

void init_union_find(int n) {
    for (int i = 0; i <= n; ++i) {
        par[i] = i;
        rank_t[i] = 0;
    }
}

int find_root(int x) {
    return par[x] == x ? x : par[x] = find_root(par[x]);
}

bool same(int x, int y) {
    return find_root(x) == find_root(y);
}

void unite(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x == y) return;

    if (rank_t[x] < rank_t[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank_t[x] == rank_t[y]) rank_t[x]++;
    }
}

vector<edge> es;

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<tuple<int, int, int> > XY(n), YX(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        XY[i] = make_tuple(x, y, i);
        YX[i] = make_tuple(y, x, i);
    }

    sort(all(XY));
    sort(all(YX));

    rep(i, n - 1) {
        edge ex, ey;
        ex.u = get<2>(XY[i]);
        ex.v = get<2>(XY[i + 1]);
        ex.cost = get<0>(XY[i + 1]) - get<0>(XY[i]);
        es.push_back(ex);

        ey.u = get<2>(YX[i]);
        ey.v = get<2>(YX[i + 1]);
        ey.cost = get<0>(YX[i + 1]) - get<0>(YX[i]);
        es.push_back(ey);
    }

    sort(all(es), comp);

    init_union_find(n);

    llong res = 0;
    rep(i, es.size()) {
        edge e = es[i];
        if (! same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }

    cout << res << endl;
    
    return 0;
}