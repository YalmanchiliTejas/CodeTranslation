#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cfloat>
#include <climits>
#include <cassert>
#include <random>
class UnionFind {
	std::vector<int> vec;
public:
	UnionFind(int size) : vec(size, -1) {}
	int find(int a) {
		return vec[a] < 0 ? a : vec[a] = find(vec[a]);
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) {
			if (vec[a] > vec[b]) std::swap(a, b);
			vec[a] += vec[b];
			vec[b] = a;
		}
	}
	int size_of(int a) {
		return -vec[find(a)];
	}

};

int main(){
	constexpr long long int MOD = 1000000007;
	while (true) {
		int n, m; std::cin >> n >> m; if (n == 0 && m == 0) break;
		UnionFind uft(n + 1);
		for (auto i = 0; i < m; ++i) {
			int a, b; std::cin >> a >> b; --a; --b;
			uft.unite(a, b);
		}
		long long int result = 1;
		for (auto i = 0; i < n; ++i) if (!uft.same(i, n)){
			result <<= 1;
			result %= MOD;
			uft.unite(i, n);
		}
		if (m != 0) ++result;
		std::cout << result << std::endl;
	}
}
