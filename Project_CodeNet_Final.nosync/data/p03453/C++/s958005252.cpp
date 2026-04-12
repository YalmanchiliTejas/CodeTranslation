#include <bits/stdc++.h>
using namespace std;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<int(1e9)+7>;

using ll = long long;

pair<vector<ll>, vector<num>> gen_dist(const vector<vector<pair<int, int>>>& edges, int s) {
	int n = int(edges.size());
	vector<ll> dist(n, -1);
	vector<num> ways(n, 0);
	dist[s] = 0;
	ways[s] = 1;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int v = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if (d != dist[v]) continue;
		for (auto z : edges[v]) {
			int w = z.first;
			ll newd = z.second + d;
			if (dist[w] == -1 || newd < dist[w]) {
				dist[w] = newd;
				ways[w] = 0;
				pq.push(make_pair(newd, w));
			}
			if (newd == dist[w]) {
				ways[w] += ways[v];
			}
		}
	}
	return {dist, ways};
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	s--; t--;
	vector<vector<pair<int, int>>> edges(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges[a].emplace_back(b, c);
		edges[b].emplace_back(a, c);
	}
	auto res0 = gen_dist(edges, s);
	auto res1 = gen_dist(edges, t);
	ll best = res0.first[t];
	assert(best == res1.first[s]);

	num total = res0.second[t] * res0.second[t];
	// 点
	for(int v = 0; v < n; v++){
		if (res0.first[v] + res1.first[v] == best && res0.first[v] == res1.first[v]) {
			total -= res0.second[v] * res0.second[v] * res1.second[v] * res1.second[v];
		}
	}
	// 边
	for (int v = 0; v < n; v++) {
		if (2 * res0.first[v] >= best) continue;
		for (auto z : edges[v]) {
			int w = z.first;
			int c = z.second;
			if (2 * res1.first[w] >= best) continue;
			if (res0.first[v] + res1.first[w] + c == best) {
				total -= res0.second[v] * res0.second[v] * res1.second[w] * res1.second[w];
			}
		}
	}
	cout << total << '\n';
}
