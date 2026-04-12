#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

class UnionFind {
    int cnt;
    vector<int> par, rank, size;
public:
    UnionFind() {}
    UnionFind(int _n) :cnt(_n), par(_n), rank(_n), size(_n, 1) {
        for (int i = 0; i<_n; ++i) par[i] = i;
    }
    int find(int k) {
        return (k == par[k]) ? k : (par[k] = find(par[k]));
    }
    int operator[](int k) {
        return find(k);
    }
    int getSize(int k) {
        return size[find(k)];
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        --cnt;
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[y] == rank[x]) ++rank[x];
        }
    }
    int count() {
        return cnt;
    }
};

template<class Weight>
struct KruskalMST {
    using Edges = vector<tuple<Weight, int, int>>;
    Weight sum;
    Edges mst;
    KruskalMST(int V, Edges edges) :sum(0) {
        sort(edges.begin(), edges.end());
        UnionFind uf(V);
        each(e, edges) {
            Weight w;
            int u, v;
            tie(w, u, v) = e;
            if (uf[u] != uf[v]) {
                mst.emplace_back(e);
                uf.unite(u, v);
                sum += w;
            }
        }
    }
};

int N, M, ma[4001][4001];
vector<pii> G[4001];

void dfs(int u, int s, int p=-1, int x=0) {
    ma[s][u] = x;
    each(e, G[u]) {
        if (e.first != p) {
            dfs(e.first, s, u, max(x, e.second));
        }
    }
}

void solve() {
    cin >> N >> M;

    vector<tuple<ll, int, int>> E(M);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        E[i] = tie(c, a, b);
    }

    auto mst = KruskalMST<ll>(N, E);
    each(e, mst.mst) {
        ll ww;
        int w, u, v;
        tie(ww, u, v) = e;
        w = (int)ww;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    rep(i, N)dfs(i, i);

    int Q;
    cin >> Q;
    rep(i, Q) {
        int s, t;
        cin >> s >> t;
        --s; --t;
        ll ans = mst.sum - ma[s][t];
        cout << ans << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}