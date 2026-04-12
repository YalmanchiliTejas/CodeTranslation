#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct RMQ {
	using type = ll;
	static type id() { return (ll)1e18; }
	static type op(const type& l, const type & r) { return min(l, r); }
};

template <typename M>
class starry_sky_tree {
	using T = typename M::type;
	const int n;
	vector<T> data, lazy;
	int size(int x) {
		int res = 1;
		while (res < x) res <<= 1;
		return res;
	}
	T sub(int l, int r, int node, int lb, int ub) {
		if (r <= lb || ub <= l) return M::id();
		if (l <= lb && ub <= r) return data[node];
		return M::op(sub(l, r, node << 1, lb, (lb + ub) >> 1)
			, sub(l, r, (node << 1) | 1, (lb + ub) >> 1, ub)) + lazy[node];
	}
	void suc(int l, int r, int node, int lb, int ub, T val) {
		if (ub <= l || r <= lb) return;
		if (l <= lb && ub <= r) {
			data[node] += val;
			lazy[node] += val;
			return;
		}
		suc(l, r, node << 1, lb, (lb + ub) >> 1, val);
		suc(l, r, (node << 1) | 1, (lb + ub) >> 1, ub, val);
		data[node] = M::op(data[node << 1], data[(node << 1) | 1]) + lazy[node];
	}
public:
	starry_sky_tree(int n_) : n(size(n_)), data(n << 1), lazy(n << 1) {}
	void add(int l, int r, T val) {
		suc(l, r, 1, 0, n, val);
	}
	T find(int l, int r) {
		return sub(l, r, 1, 0, n);
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	assert(1 <= N && N <= 2e5);
	assert(1 <= M && M <= 2e5);
	vector<vector<pair<int, ll>>> es(N + 1);
	ll sum = 0;
	for (int i = 0; i < M; i++) {
		int l, r;
		ll a;
		cin >> l >> r >> a; --l;
		assert(-1e9 <= a && a <= 1e9);
		assert(0 <= l && l < r && r <= N);
		es[r].emplace_back(l, a);
		sum += a;
	}
	starry_sky_tree<RMQ> dp(N + 2);
	ll res = 0LL;
	for (int i = 1; i <= N; i++) {
		for (auto p : es[i]) {
			dp.add(0, p.first + 1, p.second);
		}
		dp.add(i + 1, i + 2, dp.find(0, i + 1));
		res = min(res, dp.find(0, i + 2));
	}
	cout << sum - res << endl;
	return 0;
}
