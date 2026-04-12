#include <iostream>
#include <array>
#include <vector>

static const int MAX_N = 8 + 1;
using Connections = std::array<std::vector<int>, MAX_N>;

size_t traverse(const Connections& c, const int N, int depth, int now_node, std::array<bool, MAX_N>& traversed);

int main() {
	int N, M;
	std::cin >> N >> M;
	Connections a = {};
	for (int i = 0; i < M; ++i) {
		int f, t;
		std::cin >> f >> t;
		a[f].emplace_back(t);
		a[t].emplace_back(f);
	}

	std::array<bool, MAX_N> traversed = {};
	traversed[1] = true;
	std::cout << traverse(a, N, 1, 1, traversed) << std::endl;
}

size_t traverse(const Connections& c, const int N, int depth, int now_node, std::array<bool, MAX_N>& traversed) {
	if (depth == N) {
		return 1;
	}
	size_t sum = 0;
	for (int candidate : c[now_node]) {
		if (!traversed[candidate]) {
			traversed[candidate] = true;
			sum += traverse(c, N, depth + 1, candidate, traversed);
			traversed[candidate] = false;
		}
	}
	return sum;
}
