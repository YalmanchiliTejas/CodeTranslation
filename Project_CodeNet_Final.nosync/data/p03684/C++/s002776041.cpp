#include<bits/stdc++.h>

#define HEAP priority_queue
#define rep(i, n) for(int i = 0, _end_ = (n); i < _end_; ++i)
#define per(i, n) for(int i = (n) - 1; i >= 0 ; --i)
#define forn(i, l, r) for(int i = (l), _end_ = (r); i <= _end_; ++i)
#define nrof(i, r, l) for(int i = (r), _end_ = (l); i >= _end_; --i)
#define FOR(a, b) for(auto (a): (b))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define X first
#define Y second
#define eps 1e-6
#define pi 3.1415926535897932384626433832795
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define MCPY(a, b) memcpy((a), (b), sizeof((b)))

using namespace std;

typedef long long LL;
typedef double flt;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
typedef vector<pil> vil;
typedef vector<pii> vii;
typedef vector<pli> vli;
typedef vector<pll> vll;

const int iinf = 1e9 + 7;
const int oo = 0x3f3f3f3f;
const LL linf = 1ll << 60;
const flt dinf = 1e60;

template <typename T>
inline void scf(T &x)
{
	bool f = 0; x = 0; char c = getchar();
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') { f = 1; c = getchar(); }
	while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	if(f) x = -x; return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) { scf(x); return scf(y); }
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) { scf(x); scf(y); return scf(z); }
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) { scf(x); scf(y); scf(z); return scf(w); }

inline char mygetchar(){ char c = getchar(); while(c == ' ' || c == '\n') c = getchar(); return c; }

template <typename T> inline bool chkmax(T &x, const T &y){ return y > x ? x = y, 1 : 0; }
template <typename T> inline bool chkmin(T &x, const T &y){ return y < x ? x = y, 1 : 0; }

#ifdef ONLINE_JUDGE
#define debug(...) ;
#else
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define DEBUG
#endif

//---------------------------------------------------------head----------------------------------------------------

const int maxn = 1e6 + 100;

int n, m;

struct point
{
	LL x, y;
	int i;

	point(LL x = 0, LL y = 0, int i = 0): x(x), y(y), i(i){}
}pnt[maxn];

struct edge
{
	LL d;
	int u, v;

	edge(LL d = 0, int u = 0, int v = 0): d(d), u(u), v(v){}
}E[maxn];

int par[maxn];

LL calc(point a, point b)
{
	return min(abs(a.x - b.x), abs(a.y - b.y));
}

int F(int u){ return par[u] == u ? u : par[u] = F(par[u]); }

int main()
{
	scf(n);
	rep(i, n)
	{
		LL x, y;
		scf(x, y);
		pnt[i] = point(x, y, i);
		par[i] = i;
	}
	sort(pnt, pnt + n, [&](point a, point b){ return a.x < b.x; });
	rep(i, n - 1) E[m++] = edge(calc(pnt[i], pnt[i + 1]), pnt[i].i, pnt[i + 1].i);
	sort(pnt, pnt + n, [&](point a, point b){ return a.y < b.y; });
	rep(i, n - 1) E[m++] = edge(calc(pnt[i], pnt[i + 1]), pnt[i].i, pnt[i + 1].i);
	sort(E, E + m, [&](edge a, edge b){ return a.d < b.d; });
	LL ans = 0;
	rep(i, m)
	{
		LL d = E[i].d;
		int u = E[i].u, v = E[i].v;
		if(F(u) == F(v)) continue;
		ans += d;
		par[F(u)] = F(v);
	}
	printf("%lld\n", ans);
	return 0;
}