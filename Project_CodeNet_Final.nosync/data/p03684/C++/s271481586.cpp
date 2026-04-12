#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;

#define int long long

#define rep(i, n) for (signed i = 0; i < signed(n); i++)
#define REP(i, s, n) for (signed i = signed(s); i < signed(n); i++)
#define rrep(i, n) for (signed i = signed(s) - 1; i >= 0; i--)

#define all(c) begin(c), end(c)
template<typename T>bool maxup(T& a, const T&& b) { if (a < b) { a = b; return true; }; }
template<typename T>bool maxup(T& a, const T& b) { if (a < b) { a = b; return true; }; }
template<typename T>bool minup(T& a, const T&& b) { if (a > b) { a = b; return true; }; }
template<typename T>bool minup(T& a, const T& b) { if (a > b) { a = b; return true; }; }

#define X first
#define Y second

using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using IP = pair<int, P>;

template<typename T>
inline void input(vector<T>& v) { for (auto& x : v) cin >> x; }

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) {}
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

void calc() {
	int n; cin >> n;
	using T = tuple<int, int, int>;
	vector<T> v(n);
	rep(i, n) {
		int x, y; cin >> x >> y;
		v[i] = T(x, y, i);
	}
	sort(all(v));
	auto u = v;
	sort(all(u), [](T p1, T p2) {
		return get<1>(p1) < get<1>(p2);
	});

	vector<T> edge;
	auto& tmp = v;
	rep(i, n - 1) {
		int l = get<0>(tmp[i + 1]) - get<0>(tmp[i]);
		int a = get<2>(tmp[i + 1]), b = get<2>(tmp[i]);
		edge.push_back(T(l, a, b));
	}
	tmp = u;
	rep(i, n - 1) {
		int l = get<1>(tmp[i + 1]) - get<1>(tmp[i]);
		int a = get<2>(tmp[i + 1]), b = get<2>(tmp[i]);
		edge.push_back(T(l, a, b));
	}

	sort(all(edge));
	UnionFind uf(n);
	int ans = 0;
	for (T t : edge) {
		int l, a, b;
		tie(l, a, b) = t;
		if (!uf.findSet(a, b)) {
			uf.unionSet(a, b);
			ans += l;
		}
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	calc();
#ifdef _MSC_VER
	system("pause");
#endif
}