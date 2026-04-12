#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <climits>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <type_traits>
#include <utility>
#include <vector>

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

class disjoint_set {
	std::vector<std::int_fast32_t> tree;
public:
	disjoint_set(std::uint_fast32_t size) :tree(size, -1) {}
	std::uint_fast32_t find(std::uint_fast32_t x) {
		if (tree[x] < 0) return x;
		return tree[x] = (std::int_fast32_t)find((std::uint_fast32_t)tree[x]);
	}
	bool unite(std::uint_fast32_t x, std::uint_fast32_t y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		if (tree[x] > tree[y]) {
			tree[y] += tree[x];
			tree[x] = y;
		}
		else {
			tree[x] += tree[y];
			tree[y] = x;
		}
		return true;
	}
	std::uint_fast32_t size(std::uint_fast32_t x) {
		return (std::uint_fast32_t)(-tree[find(x)]);
	}
	bool same(std::uint_fast32_t x, std::uint_fast32_t y) {
		return find(x) == find(y);
	}
};

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	uint32 n;
	std::cin >> n;
	disjoint_set S(n);
	std::vector<std::pair<uint32, uint32>> x(n),y(n);
	std::vector<std::pair<uint64, std::pair<uint32, uint32>>> e;
	for (uint32 i = 0;i < n;++i) {
		std::cin >> x[i].first >> y[i].first;
		x[i].second = i;
		y[i].second = i;
	}
	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());
	for (uint32 i = 1;i < n;++i) {
		e.push_back({ x[i].first - x[i - 1].first,{x[i].second,x[i - 1].second} });
		e.push_back({ y[i].first - y[i - 1].first,{ y[i].second,y[i - 1].second } });
	}
	uint64 ans = 0;
	std::sort(e.begin(), e.end());
	for (uint32 i = 0;i < e.size();++i) {
		uint32 a = e[i].second.first, b = e[i].second.second;
		if (S.unite(a, b)) ans += e[i].first;
	}
	std::cout << ans << "\n";
	return 0;
}