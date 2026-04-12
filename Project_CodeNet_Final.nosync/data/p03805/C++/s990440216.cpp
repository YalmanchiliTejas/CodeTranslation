#include<iostream>

int dfs(int now, int n, int m, bool*arr, bool*use) {
	bool flag = true;

	for (int i = 0; i < n; i++) {
		if (use[i] == false)flag = false;
	}
	if (flag)return 1;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[now * n + i]&&use[i]==false) {
			use[i] = true;
			ans += dfs(i, n, m, arr, use);
			use[i] = false;
		}
	}
	return ans;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	bool *arr =new bool[n*n];
	bool *use = new bool[n];
	for (int i = 0; i < n; i++)use[i] = false;
	for (int i = 0; i < n*n; i++)arr[i] = false;
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		a--; b--;
		arr[b*n + a] = true;
		arr[a*n+ b] = true;
	}
	use[0] = true;
	printf("%d", dfs(0,n, m, arr, use));
}