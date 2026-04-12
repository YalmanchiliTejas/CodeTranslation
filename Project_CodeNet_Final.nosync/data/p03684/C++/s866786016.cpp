#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

// --------- UnionFind木 ---------
class UnionFind {
public:
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) std::swap(x, y);
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
private:
	std::vector<int> data;
};

int n;
std::pair<ll, int> xx[100005], yy[100005];
std::vector<std::tuple<ll, int, int>> e;
int main() {
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		ll x, y;

		std::cin >> x >> y;

		xx[i].first = x;
		xx[i].second = i;

		yy[i].first = y;
		yy[i].second = i;
	}

	std::sort(xx, xx + n);
	std::sort(yy, yy + n);

	for (int i = 0, end = n - 1; i < end; ++i)
		e.emplace_back(xx[i + 1].first - xx[i].first, xx[i].second, xx[i + 1].second);

	for (int i = 0, end = n - 1; i < end; ++i)
		e.emplace_back(yy[i + 1].first - yy[i].first, yy[i].second, yy[i + 1].second);

	std::sort(e.begin(), e.end());

	UnionFind uf(n);
	ll ans = 0;
	for (size_t i = 0, end = e.size(); i < end; ++i) {
		ll l;
		int i1, i2;

		std::tie(l, i1, i2) = e[i];

		if (!uf.findSet(i1, i2)) {
			ans += l;
			uf.unionSet(i1, i2);
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
