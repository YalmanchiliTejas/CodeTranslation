#include<iostream>
#include<vector>

int n, m, count, ans;
std::vector<std::vector<int>>v;
std::vector<bool>used(8, 0);

void dfs(int num) {
	used[num] = true;
	count++;
	if (count == n)ans++;
	for (auto i : v[num]) {
		if (used[i])continue;
		dfs(i);
	}
	count--;
	used[num] = false;
}

int main() {

	std::cin >> n >> m;
	v.resize(n);
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