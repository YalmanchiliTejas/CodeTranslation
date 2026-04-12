#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <numeric>

std::vector<std::vector<int> > path(8, std::vector<int>(8, 0));


int dfs(std::vector<long long> visited, int pos) {
	int ret = 0;

	if (std::accumulate(visited.begin(), visited.end(), 0) == visited.size()) {
		return 1;
	}

	for (size_t i = 0; i < visited.size(); i++)
	{
		if (path[pos][i] == 1 && visited[i] != 1) {
			visited[i] = 1;
			ret += dfs(visited, i);
			visited[i] = 0;
		}
	}
	return ret;
}

int main()
{
	long long n, m;

	std::cin >> n >> m;

	std::vector<long long> visited(n, 0);

	visited[0] = 1;

	for (size_t i = 0; i < m; i++)
	{
		int a, b;

		std::cin >> a >> b;

		path[a - 1][b - 1] = 1;
		path[b - 1][a - 1] = 1;
	}

	visited[0] = 1;

	std::cout << dfs(visited, 0) << std::endl;

	return 0;
}
