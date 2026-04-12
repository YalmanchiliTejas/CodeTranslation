#include<iostream>

int n, m, ans = 0;
bool *use;
bool **map;

void dfs(int now,int old) {
	use[now] |= 1;
	bool flag = true;
	for (int i = 0; i < n; i++)flag &= use[i];
	if (flag) {
		ans++;
		return;
	}
	/*
	for (int i = 0; i < n; i++) {
		printf("%d", use[i]);
	}
	printf("\n");*/
	for (int i = 0; i < n; i++) {
		if (i != old && map[i][now] && !use[i]) {
			dfs(i, now);
			use[i] &= 0;
		}
	}
}

int main() {
	std::cin >> n >> m;
	use = new bool[n];
	map = new bool*[n];
	bool *base = new bool[n*n];
	for (int i = 0; i < n; i++) {
		use[i] = false;
		map[i] = &base[i*n];
		for (int j = 0; j < n; j++) {
			map[i][j] = false;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		map[a][b] = true;
		map[b][a] = true;
	}
	
	/*
	for (int i = 0; i < n*n; i++) {
		printf("%d", map[i / n][i%n]);
		if (i%n == n - 1)printf("\n");
	}
	printf("\n");*/

	dfs(0, -1);

	printf("%d\n",ans);
}