
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using u32 = uint32_t;
using vi = vector<int>;    using vvi = vector<vi>;
using vb = vector<bool>;   using vvb = vector<vb>;
using vl = vector<ll>;     using vvl = vector<vl>;
using vd = vector<double>; using vvd = vector<vd>;

#define MAXC(c, x) (c = max(c, x))
#define MINC(c, x) (c = min(c, x))

#define REP(i,n) for(auto i = 0 * (n), i##_len = (n); i < i##_len; ++i)
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,s,n) for(ll i=s, i##_len=(ll)(n); i<i##_len; ++i)
#define TEN(x) ((ll)1e##x)
const ll mod = TEN(9) + 7;

const ll INF = 1e9;
template<int64_t mod> struct GF {
	typedef int64_t T;
	T v;
	GF() = default;
	GF(T v) : v((v % mod + mod) % mod) {}
	GF & operator+=(GF x) { v = (v + x.v) % mod; return *this; }
	GF & operator*=(GF x) { v = (v * x.v) % mod; return *this; }
	GF & operator-=(GF x) { v = (v - x.v + mod) % mod; return *this; }
	GF & operator/=(GF x) { return (*this) *= x.inverse(); }
	GF operator+(GF rhs) const { GF lhs = *this; return lhs += rhs; }
	GF operator*(GF rhs) const { GF lhs = *this; return lhs *= rhs; }
	GF operator-(GF rhs) const { GF lhs = *this; return lhs -= rhs; }
	GF operator/(GF rhs) const { GF lhs = *this; return lhs /= rhs; }
	GF inverse() const { // http://topcoder.g.hatena.ne.jp/iwiwi/20130105/1357363348
		T a = v, b = mod, x = 1, y = 0;
		while (b) {
			T t = a / b;
			swap(a -= t * b, b);
			swap(x -= t * y, y);
		}
		return x;
	}
	GF pow(T n) const {
		GF r; r.v = 1;
		for (T x = v; n > 0; n >>= 1) {
			if (n & 1) (r.v *= x) %= mod;
			(x *= x) %= mod;
		}
		return r;
	}
	typedef size_t U;
	static GF fact(U n) {
		static vector<GF> data;
		U m = data.size();
		if (m <= n) {
			data.resize(n + 1);
			if (m == 0) { data[0].v = 1; m++; }
			for (U i = m; i < n + 1; ++i) data[i] = data[i - 1] * i;
		}
		return data[n];
	}
	static GF nCr(U n, U r) { return fact(n) / fact(r) / fact(n - r); }
	static GF nPr(U n, U r) { return fact(n) / fact(r); }
};
int main() {
	#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
	#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(50);

	ll n, m; cin >> n >> m;
	ll s, t; cin >> s >> t;
	s--, t--;

	using P = pair<ll, ll>;
	vector<vector<P>> g(n);
	REP(i, m) {
		ll u, v, d; cin >> u >> v >> d;
		u--, v--;
		g[u].push_back(P{ v, d });
		g[v].push_back(P{ u, d });
	}

	vl dist(n, TEN(16));
	{
		priority_queue<P, vector<P>, greater<P>> q;
		q.push(P(0, s));
		while (!q.empty()) {
			ll d, v;
			tie(d, v) = q.top(); q.pop();
			if (dist[v] < d) continue;
			dist[v] = d;
			for (auto&& next : g[v]) {
				if (dist[next.first] <= dist[v] + next.second) continue;
				dist[next.first] = dist[v] + next.second;
				q.push(P(dist[v] + next.second, next.first));
			}
		}
	}
	
	vl hit1;
	vector<P> hit2;
	vl ord;
	{
		vb used(n, false);
		using T = tuple<ll, ll, ll>;
		priority_queue<T> q;
		q.push(T(dist[t], t, -1));
		while(!q.empty()) {
			ll d, cur, prev;
			tie(d, cur, prev) = q.top(); q.pop();
			if (used[cur]) continue;
			used[cur] = true;
			ord.push_back(cur);
			if (dist[cur] * 2 == dist[t]) {
				hit1.push_back(cur);
			}
			for (auto&& next : g[cur]) {
				if (dist[next.first] + next.second != dist[cur]) continue;
				q.push(T{ dist[cur] - next.second, next.first, cur});
				if (dist[next.first] * 2 < dist[t] && dist[t] < dist[cur] * 2) {
					hit2.push_back(P{ next.first, cur });
				}
			}
		}
	}
	using G = GF<mod>;

	vector<G> dp_t(n, 0);
	dp_t[t] = 1;
	for (ll cur : ord) {
		for (auto&& next : g[cur]) {
			if (dist[next.first] + next.second != dist[cur]) continue;
			dp_t[next.first] += dp_t[cur];
		}
	}

	reverse(ALL(ord));
	vector<G> dp_s(n, 0);
	dp_s[s] = 1;
	for (ll cur : ord) {
		for (auto&& next : g[cur]) {
			if (dist[next.first] != dist[cur] + next.second) continue;
			dp_s[next.first] += dp_s[cur];
		}
	}
	auto ans = dp_s[t] * dp_t[s];
	for (auto h : hit1) {
		ans -= dp_s[h] * dp_t[h] * dp_s[h] * dp_t[h];
	}
	for (auto h : hit2) {
		ans -= dp_s[h.first] * dp_t[h.second] * dp_s[h.first] * dp_t[h.second];
	}
	cout << ans.v << endl;
	

	return 0;
}
