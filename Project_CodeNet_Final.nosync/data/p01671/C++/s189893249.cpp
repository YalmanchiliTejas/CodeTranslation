#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
	int from, to, id;
	ll cost;
	edge(int f, int t, int i, ll c) : from(f), to(t), id(i), cost(c) {}
	bool operator<(const edge& that) const {
		return cost < that.cost;
	}
};

using edges = vector<edge>;

class union_find {
	vector<int> par;
	int find(int a) {
		return par[a] < 0 ? a : par[a] = find(par[a]);
	}
public:
	union_find(int n) : par(n, -1) {}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (par[a] < par[b]) swap(a, b);
		else if (par[a] == par[b]) par[b]--;
		par[a] = b;
	}
};

class HLD {
	vector<vector<int>> G;
	vector<int> vid, head, heavy, par, dep;
	int dfs(int v, int prev) {
		par[v] = prev;
		int cnt = 1, ma = 0;
		for (int to : G[v]) if (to != prev) {
			dep[to] = dep[v] + 1;
			int c = dfs(to, v);
			cnt += c;
			if (ma < c) {
				ma = c;
				heavy[v] = to;
			}
		}
		return cnt;
	}
public:
	HLD(int n) : G(n), vid(n, -1), head(n), heavy(n, -1), par(n), dep(n) {}
	void add(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void build() {
		dfs(0, -1);
		int k = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int h = q.front(); q.pop();
			for (int i = h; i != -1; i = heavy[i]) {
				vid[i] = k++;
				head[i] = h;
				for (int j : G[i]) if (j != par[i] && j != heavy[i]) q.push(j);
			}
		}
	}
	int operator[](int v) {
		return vid[v];
	}
	void for_each_edge(int u, int v, function<void(int, int)> f) {
		while (true) {
			if (vid[u] > vid[v]) swap(u, v);
			if (head[u] != head[v]) {
				f(vid[head[v]], vid[v]);
				v = par[head[v]];
			}
			else {
				if (u != v) f(vid[u] + 1, vid[v]);
				break;
			}
		}
	}
};

struct ru {
	using type = int;
	static type id() { return INT_MAX; }
	static type up(type m, type u) { return min(m, u); }
};

template <typename M>
class segment_tree {
	using T = typename M::type;
	int size(int x) {
		int res = 1;
		while (res < x) res <<= 1;
		return res;
	}
	const int n;
	vector<T> data;
	void sub(int l, int r, T val, int node, int lb, int ub) {
		if (r <= lb || ub <= l) return;
		if (l <= lb && ub <= r) {
			data[node] = M::up(data[node], val);
			return;
		}
		int m = (lb + ub) >> 1;
		data[node << 1] = M::up(data[node << 1], data[node]);
		data[(node << 1) | 1] = M::up(data[(node << 1) | 1], data[node]);
		sub(l, r, val, node << 1, lb, m);
		sub(l, r, val, (node << 1) | 1, m, ub);
	}
	T get(int p, int node, int lb, int ub) {
		if (ub - lb == 1) return data[node];
		int m = (lb + ub) >> 1;
		if (p < m) {
			data[node << 1] = M::up(data[node << 1], data[node]);
			return get(p, node << 1, lb, m);
		}
		data[(node << 1) | 1] = M::up(data[(node << 1) | 1], data[node]);
		return get(p, (node << 1) | 1, m, ub);
	}
public:
	segment_tree(int n_) : n(size(n_)), data(n * 2, M::id()) {}
	void update(int l, int r, T val) {
		sub(l, r, val, 1, 0, n);
	}
	T find(int p) {
		return get(p, 1, 0, n);
	}
};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	edges es;
	for (int i = 0; i < m; i++) {
		int a, b;
		ll w;
		cin >> a >> b >> w; a--, b--;
		es.emplace_back(a, b, i, w);
	}
	sort(es.begin(), es.end());
	union_find uf(n);
	vector<int> used(m);
	ll sum = 0;
	HLD hl(n);
	for (int i = 0; i < m; i++) {
		int u = es[i].from, v = es[i].to, c = es[i].cost;
		if (!uf.same(u, v)) {
			used[i] = 1;
			uf.unite(u, v);
			sum += c;
			hl.add(u, v);
		}
	}
	if (count(used.begin(), used.end(), 1) != n - 1) {
		for (int i = 0; i < m; i++) {
			puts("-1");
		}
		return 0;
	}
	hl.build();
	segment_tree<ru> st(n + 1);
	for (int i = 0; i < m; i++) {
		if (!used[i]) {
			int u = es[i].from, v = es[i].to, c = es[i].cost;
			hl.for_each_edge(u, v, [&](int l, int r) {
				st.update(l, r + 1, c);
			});
		}
	}
	vector<ll> res(m);
	for (int i = 0; i < m; i++) {
		if (!used[i]) {
			res[es[i].id] = sum;
			continue;
		}
		ll cost = INT_MAX;
		hl.for_each_edge(es[i].from, es[i].to, [&](int l, int r) {
			cost = min(cost, (ll)st.find(l));
		});
		if (cost == INT_MAX) {
			res[es[i].id] = -1;
		}
		else {
			res[es[i].id] = sum + cost - es[i].cost;
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%lld\n", res[i]);
	}
	return 0;
}

