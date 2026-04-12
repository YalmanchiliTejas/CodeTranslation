#include <bits/stdc++.h>
 
#define forn(i, n) for (llong i = 0ll; i < (llong) n; ++i)
#define fornn(i, l, r) for (llong i = (llong) l; i < (llong) r; ++i)
#define size(x) ((int) (x.size()))
 
using namespace std;
 
typedef long long llong;
const llong inf = (llong) 1e+9 + 7ll;
const llong linf = (llong) 1e+18 + 7ll;
const long double eps = (long double) 1e-9;
const long double pi = acosl((long double) -1.0);
const int alph = 26;

mt19937 mrand(random_device{} ()); 

template<typename T, typename U> inline llong umin(const T& a, const U& b) { return a < b ? a : b; }
template<typename T, typename U> inline llong umax(const T& a, const U& b) { return a > b ? a : b; }
 
static char buff[(int) 2e6 + 17]; // reads std::string
const int maxn = (int) 2e5 + 17;

struct pt
{
	int x, y, i;
	pt() { }
	pt(int x, int y, int i) : x(x), y(y), i(i) { }
};

struct edge
{
	int v, u, w;
	edge() { }
	edge(int v, int u, int w) : v(v), u(u), w(w) { }
};

struct dsu
{
	int n;
	vector<int> p, w;

	dsu(int n) : n(n)
	{
		p.resize(n);
		w.resize(n);

		forn (i, n)
			p[i] = i, w[i] = 1;
	}

	int getp(int v) { return p[v] == v ? v : p[v] = getp(p[v]); }

	bool join(int u, int v)
	{
		u = getp(u);
		v = getp(v);
		if (u == v) return false;
		if (w[u] < w[v]) swap(u, v);
		p[v] = u;
		w[u] += w[u] == w[v];
		return true;
	}
};

int n;
pt p[maxn];

bool read()
{
	if (scanf("%d", &n) != 1)
		return false;

	forn (i, n)
		scanf("%d %d", &p[i].x, &p[i].y), p[i].i = i;

	return true;
}

bool cmpx(pt a, pt b) { return a.x < b.x || (a.x == b.x && a.i < b.i); }
bool cmpy(pt a, pt b) { return a.y < b.y || (a.y == b.y && a.i < b.i); }
bool cmpe(edge a, edge b) { return a.w < b.w; }

void solve()
{
	vector<edge> e;
	sort(p, p + n, cmpx);

	forn (i, n - 1)
		e.push_back(edge(p[i].i, p[i + 1].i, p[i + 1].x - p[i].x));

	sort(p, p + n, cmpy);

	forn (i, n - 1)
		e.push_back(edge(p[i].i, p[i + 1].i, p[i + 1].y - p[i].y));

	sort(e.begin(), e.end(), cmpe);
	dsu d(n);
	llong ans = 0;

	forn (i, size(e))
		if (d.join(e[i].v, e[i].u))
			ans += e[i].w;

	printf("%lld\n", ans);
}

int main()
{
#if SEREZHKA
	freopen("file.in", "r", stdin);
#endif

	while (read())
		solve();

	return 0;
}
