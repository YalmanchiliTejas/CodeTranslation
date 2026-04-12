#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

std::vector<int> graph[8];
int n, m;

std::vector<int> arrived;
int solve(int x) {
	if (arrived.size() == n - 1)
		return 1;

	int ret = 0;
	arrived.push_back(x);
	for (auto&& e : graph[x]) {
		if ([e]() {
			for (auto&& v : arrived)
				if (v == e)
					return false;

			return true;
		}()) {
			ret += solve(e);
		}
	}
	arrived.pop_back();

	return ret;
}

int main() {
	std::cin >> n >> m;

	arrived.reserve(m);

	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a, --b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	std::cout << solve(0) << std::endl;
}