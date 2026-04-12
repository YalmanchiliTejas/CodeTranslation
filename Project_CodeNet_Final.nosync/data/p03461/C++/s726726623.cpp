#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
ll mod_inv(ll a, ll m) { ll x, y; extgcd<ll>(a, m, x, y); return (m + x % m) % m; }

using cost_type = int;

struct edge {
	int to;
	cost_type cost;
	edge() {}
	edge(int to, cost_type cost) : to(to), cost(cost) {}
};
typedef pair<cost_type, int> P;

static void run(vector<vector<edge> >& edges, vector<cost_type>& cost_table, int s, vector<int>* _prev = NULL) {
	//init
	cost_table.resize((int)edges.size());
	fill(cost_table.begin(), cost_table.end(), numeric_limits<cost_type>::max() / 3);
	if (_prev) _prev->resize(edges.size());
	if (_prev) fill(_prev->begin(), _prev->end(), -1);

	priority_queue<P, vector<P>, greater<P> > q;
	q.push(P(0, s));
	cost_table[s] = 0;

	while (!q.empty()) {
		P p = q.top(); q.pop();
		int v = p.second;
		if (cost_table[v] < p.first) continue;
		for (const auto& e : edges[v]) {
			if (cost_table[e.to] > cost_table[v] + e.cost) {
				cost_table[e.to] = cost_table[v] + e.cost;
				if (_prev) (*_prev)[e.to] = v;
				q.push(P(cost_table[e.to], e.to));
			}
		}
	}
}

int d[10][10];
int minx[10][10], miny[10][10];

int solve(int s, int t, vector<vector<edge>>& e) {
	vector<int> costs;
	run(e, costs, s);
	return costs[t];
}

int main() {
	int a, b; reader(a, b);
	FOR(i, a) FOR(j, b) {
		reader(d[i][j]);
	}
	bool ok = true;
	//FOR(i, a - 2) FOR(j, b) {
	//	int df1 = d[i + 1][j] - d[i][j];
	//	int df2 = d[i + 2][j] - d[i + 1][j];
	//	if (df1 > df2) {
	//		ok = false;
	//	}
	//}
	//FOR(i, a) FOR(j, b - 2) {
	//}

	FOR(i, a - 1) FOR(j, b) {
		int df = d[i + 1][j] - d[i][j];
		chmax(minx[i][j], df);
	}
	FOR(i, a) FOR(j, b - 1) {
		int df = d[i][j + 1] - d[i][j];
		chmax(miny[i][j], df);
	}

	vector<int> xv, yv;
	const int Y = 105;
	const int S = Y * 2 - 2, T = Y * 2 - 1;
	xv.push_back(S);
	FOR(i, Y - 1) xv.push_back(i);
	xv.push_back(T);
	yv.push_back(S);
	FOR(i, Y - 1) yv.push_back(i + Y - 1);
	yv.push_back(T);

	const int XW = ten(8), YW = -ten(8);
	vector<tuple<int, int, int>> vp;
	FOR(i, Y) {
		vp.emplace_back(xv[i], xv[i + 1], XW);
		vp.emplace_back(yv[i], yv[i + 1], YW);
	}
	FOR(w, Y) FOR(z, Y) {
		if (w + z >= Y) continue;
		int maxdiff = -10000;
		FOR(i, a) FOR(j, b) {
			int xw = w * (i + 1);
			int yw = z * (j + 1);
			int additional = d[i][j] - xw - yw;
			chmax(maxdiff, additional);
		}
		if (maxdiff >= 0) {
			int from = xv[w], to = yv[Y - z];
			// printf("%dx + %dy + %d\n", w, z, maxdiff);
			vp.emplace_back(from, to, maxdiff);
		}
	}

	if (ok) {
		FOR(i, a) FOR(j, b) {
			vector<vector<edge>> g(T + 1);
			for (auto& abc : vp) {
				int a, b, c; tie(a, b, c) = abc;
				if (c == XW) c = i + 1;
				else if (c == YW) c = j + 1;
				g[a].emplace_back(b, c);
			}
			int cans = solve(S, T, g);
			if (cans != d[i][j]) {
				ok = false;
			}
		}
	}

	if (ok) {
		printf("Possible\n");
		printf("%d %d\n", T + 1, sz(vp));
		for (auto& abc : vp) {
			int a, b, c; tie(a, b, c) = abc;
			if (c == XW) {
				printf("%d %d X\n", a + 1, b + 1);
			} else if (c == YW) {
				printf("%d %d Y\n", a + 1, b + 1);
			} else {
				printf("%d %d %d\n", a + 1, b + 1, c);
			}
		}
		printf("%d %d\n", S + 1, T + 1);
	} else {
		printf("Impossible\n");
	}


	return 0;
}
