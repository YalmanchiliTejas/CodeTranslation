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

using cost_type = ll;
struct edge {
	int to;
	cost_type cost;
	edge() {}
	edge(int to, cost_type cost) : to(to), cost(cost) {}
};

void dijkstra(vector<vector<edge> >& edges, vector<cost_type>& cost_table, int s, vector<int>* _prev = NULL) {
	typedef pair<cost_type, int> P;
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

const int MOD = ten(9) + 7;
void f(vector<vector<edge>>& g, int s, vector<ll>& dp) {
	int n = sz(g);
	dp.resize(n);
	FOR(i, n) dp[i] = 0;
	dp[s] = 1;
	typedef pair<cost_type, int> P;
	priority_queue<P, vector<P>, greater<P> > q;
	vector<ll> cost_table(n, numeric_limits<ll>::max() / 3);
	q.emplace(0, s);
	cost_table[s] = 0;
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int v = p.second;
		if (cost_table[v] < p.first) continue;
		for (const auto& e : g[v]) {
			(dp[e.to] += dp[v]) %= MOD;
			if (cost_table[e.to] > cost_table[v] + e.cost) {
				cost_table[e.to] = cost_table[v] + e.cost;
				q.push(P(cost_table[e.to], e.to));
			}
		}
	}
}

int solve(vector<vector<edge>>& g, int s, int t) {
	const int n = sz(g);
	{
		vector<ll> costs;
		dijkstra(g, costs, s);
		vector<bool> used(n);
		queue<int> q;
		q.emplace(t);
		used[t] = true;
		vector<tuple<int, int, ll>> g2;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto& tc : g[cur]) {
				if (costs[cur] - tc.cost == costs[tc.to]) {
					g2.emplace_back(tc.to, cur, tc.cost);

					if (!used[tc.to]) {
						used[tc.to] = true;
						q.push(tc.to);
					}

				}
			}
		}
		vector<vector<edge>> g3(2 * n);
		FOR(i, n) g3[i].emplace_back(i + n, 0);
		for (auto& abc : g2) {
			int a, b; ll c; tie(a, b, c) = abc;
			g3[a + n].emplace_back(b, c);
		}

		g = g3;
	}

	{
		vector<ll> costs;
		dijkstra(g, costs, s);
		ll md = costs[t] / 2;
		vector<vector<edge>> a1(2 * n), a2(2 * n);
		vector<Pii> middle;
		FOR(i, 2 * n) {
			for (auto tc : g[i]) {
				if (costs[i] == md && costs[tc.to] == md) {
					middle.emplace_back(i, tc.to);
				} else if (costs[i] < md && md < costs[tc.to]) {
					middle.emplace_back(i, tc.to);
				} else {
					if (costs[tc.to] <= md) {
						a1[i].push_back(tc);
					} else {
						a2[tc.to].push_back(edge(i, tc.cost));
					}
				}
			}
		}

		vector<ll> dp1, dp2;
		f(a1, s, dp1);
		f(a2, t + n, dp2);
		vector<ll> pers;
		for (auto ab : middle) {
			ll cur = dp1[ab.first] * dp2[ab.second] % MOD;
			pers.push_back(cur);
		}
		ll sum = accumulate(pers.begin(), pers.end(), 0LL) % MOD;
		ll ans = 0;
		for (auto a : pers) {
			(ans += a * (sum - a)) %= MOD;
		}
		return (ans % MOD + MOD) % MOD;
	}
}

void test() {
	for (int l = 1; l <= 20; l++) {
		vector<vector<edge>> g(1 + l * 3);
		int s = 0, t = sz(g) - 1;
		FOR(i, l) {
			const int base = i * 3;
			g[base].emplace_back(base + 1, 1);
			g[base].emplace_back(base + 2, 1);
			g[base + 1].emplace_back(base, 1);
			g[base + 1].emplace_back(base + 3, 1);
			g[base + 2].emplace_back(base, 1);
			g[base + 2].emplace_back(base + 3, 1);
			g[base + 3].emplace_back(base + 1, 1);
			g[base + 3].emplace_back(base + 2, 1);
		}
		auto ori = g;
		int ans = solve(g, s, t);
		writerLn(ans);
	}
}

int main() {
	// test();

	int n, m; reader(n, m);
	int s, t; reader(s, t);
	s--; t--;
	vector<vector<edge>> g(n);
	FOR(i, m) {
		int a, b; ll c; reader(a, b, c);
		c *= 2;
		a--; b--;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}

	int ans = solve(g, s, t);
	writerLn(ans);

	return 0;
}