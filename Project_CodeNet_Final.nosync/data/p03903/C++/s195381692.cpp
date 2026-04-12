#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};


int N, M;
struct Edge {
    int x, y;
    int c;
    
    bool operator<(const Edge &e) const {
	return c < e.c;
    }
} E[400011];
vector<pair<int, int> > G[4011];
int par[15][4011];
int cst[15][4011];
int depth[4011];

int get_max(int x, int y) {
    int ret = 0;
    if (depth[x] > depth[y]) swap(x, y);
    for (int t=15; t--;) {
	if ((depth[y]-depth[x])>>t&1) {
	    amax(ret, cst[t][y]);
	    y = par[t][y];
	}
    }
    if (x == y) return ret;
    for (int t=15; t--;) {
	if (par[t][x] != par[t][y]) {
	    amax(ret, cst[t][x]);
	    amax(ret, cst[t][y]);
	    x = par[t][x];
	    y = par[t][y];
	}
    }
    amax(ret, cst[0][x]);
    amax(ret, cst[0][y]);
    return ret;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	a--; b--;
	E[i].x = a;
	E[i].y = b;
	E[i].c = c;
    }

    LL sum = 0;
    sort(E, E+M);
    UnionFind U(N);
    REP (i, M) {
	int x = E[i].x;
	int y = E[i].y;
	int c = E[i].c;
	if (!U.same(x, y)) {
	    G[x].emplace_back(y, c);
	    G[y].emplace_back(x, c);
	    U.link(x, y);
	    sum += c;
	}
    }
    VI ord;
    ord.push_back(0);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (e->first != par[0][v]) {
	    par[0][e->first] = v;
	    cst[0][e->first] = e->second;
	    depth[e->first] = depth[v] + 1;
	    ord.push_back(e->first);
	}
    }

    REP (t, 14) REP (i, N) {
	int p = par[t][i];
	par[t+1][i] = par[t][p];
	cst[t+1][i] = max(cst[t][i], cst[t][p]);
    }

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int s, t;
	scanf("%d%d", &s, &t);
	s--; t--;
	LL ans = sum - get_max(s, t);
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

