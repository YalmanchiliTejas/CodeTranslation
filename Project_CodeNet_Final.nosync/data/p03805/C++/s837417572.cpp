#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

static int32_t N, M;
static vector<vector<int32_t>> g;
static vector<bool> used;
static int32_t dfs(int32_t index, int32_t cnt_visit)
{
	if (cnt_visit >= N - 1)
		return 1;

	int32_t res = 0;
	used[index] = true;
	for (size_t i = 0; i < g[index].size(); i++) {
		if (used[g[index][i]])
			continue;
		res += dfs(g[index][i], cnt_visit + 1);
	}
	used[index] = false;
	return res;
}

int main()
{
	cin >> N >> M;

	used.resize(N);
	std::fill(std::begin(used), std::end(used), false);
	g.resize(N);

	for (int32_t i = 0; i < M; i++) {
		int32_t a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	cout << dfs(0, 0) << endl;

	return 0;
}