#include <iostream>
#include <vector>
#include <numeric>

constexpr int Mod = 1e9 + 7;

struct UnionFind {
	std::vector<int> parent;
	int size = 0;

	int root(int x) {
		return (parent[x] == x ? x : parent[x] = root(parent[x]));
	}

	void unite(int x, int y) {
		x = root(x), y = root(y);
		if (x == y)
			return;

		--size;
		parent[y] = x;
	}

	void reset(int n) {
		parent.resize(n);
		size = n;
		std::iota(parent.begin(), parent.end(), 0);
	}
};

int pow2[100001];

int main() {
	pow2[0] = 1;
	for (int i = 1; i < 100001; ++i)
		pow2[i] = (2 * pow2[i - 1]) % Mod;

	int n, m;
	UnionFind uf;
	while (true) {
		std::cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		uf.reset(n);
		
		for (int i = 0; i < m; ++i) {
			int a, b;
			std::cin >> a >> b;
			--a, --b;

			uf.unite(a, b);
		}

		int ans = pow2[uf.size];
		if (uf.size != n)
			ans = (ans + 1) % Mod;

		std::cout << ans << std::endl;
	}
}
