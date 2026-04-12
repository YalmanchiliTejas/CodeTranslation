#ifndef CLASS_MODINT
#define CLASS_MODINT

#include <cstdint>

template <std::uint32_t mod>
class modint {
private:
	std::uint32_t n;
public:
	modint() : n(0) {};
	modint(std::int64_t n_) : n((n_ >= 0 ? n_ : mod - (-n_) % mod) % mod) {};
	static constexpr std::uint32_t get_mod() { return mod; }
	std::uint32_t get() const { return n; }
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint inv() const { return (*this).pow(mod - 2); }
	modint pow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
};

#endif // CLASS_MODINT

#include <queue>
#include <vector>
#include <iostream>
using namespace std;
using mint = modint<1000000007>;
class edge {
public:
	int to; long long cost;
	edge() : to(-1), cost(0) {};
	edge(int to_, long long cost_) : to(to_), cost(cost_) {};
};
class state {
public:
	int pos; long long cost;
	state() : pos(-1), cost(0) {};
	state(int pos_, long long cost_) : pos(pos_), cost(cost_) {};
	bool operator<(const state& s) const {
		return cost > s.cost;
	}
};
vector<pair<long long, mint> > calc(int src, vector<vector<edge> > G) {
	int N = G.size();
	vector<pair<long long, mint> > ans(N, make_pair(1LL << 62, mint(0)));
	priority_queue<state> que;
	ans[src] = make_pair(0, mint(1));
	que.push(state(src, 0));
	vector<bool> vis(N, false);
	while (!que.empty()) {
		int u = que.top().pos; que.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (edge e : G[u]) {
			if (ans[e.to].first > ans[u].first + e.cost) {
				ans[e.to] = make_pair(ans[u].first + e.cost, ans[u].second);
				que.push(state(e.to, ans[e.to].first));
			}
			else if (ans[e.to].first == ans[u].first + e.cost) {
				ans[e.to].second += ans[u].second;
			}
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, S, T;
	cin >> N >> M >> S >> T; --S, --T;
	vector<vector<edge> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c; --a, --b;
		G[a].push_back(edge(b, c));
		G[b].push_back(edge(a, c));
	}
	vector<pair<long long, mint> > resa = calc(S, G);
	vector<pair<long long, mint> > resb = calc(T, G);
	long long dist = resa[T].first;
	mint comb = resa[T].second;
	mint ans = comb * comb;
	for (int i = 0; i < N; ++i) {
		if (resa[i].first * 2 == dist && resb[i].first * 2 == dist) {
			ans -= resa[i].second * resa[i].second * resb[i].second * resb[i].second;
		}
		for (edge e : G[i]) {
			if (resa[i].first * 2 < dist && resb[e.to].first * 2 < dist && resa[i].first + resb[e.to].first + e.cost == dist) {
				ans -= resa[i].second * resa[i].second * resb[e.to].second * resb[e.to].second;
			}
		}
	}
	cout << ans.get() << endl;
	return 0;
}