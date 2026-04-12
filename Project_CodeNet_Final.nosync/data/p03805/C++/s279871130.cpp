#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<stack>

int n, m, ans, count;
bool use[8];
std::vector<std::vector<int>>v(8);

void dfs(int now) {
	use[now] = true;
	count++;
	if (count == n) {
		ans++;
		use[now] = false;
		count--;
		return;
	}
	for (auto next : v[now]) {
		if (use[next])continue;
		dfs(next);
	}
	use[now] = false;
	count--;
	return;
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(0);
	printf("%d\n", ans);
}