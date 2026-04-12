#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int graf[10][10];
int dfs(int v, int n, bool vst[10]) {
	bool flg = true;
	for (int i = 0; i < n; i++) {
		if (!vst[i])flg = false;
	}
	if (flg)return 1;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!graf[v][i])continue;
		if (vst[i])continue;
		vst[i] = true;
		ans += dfs(i, n, vst);
		vst[i] = false;
	}
	return ans;
}
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graf[a - 1][b - 1] = graf[b - 1][a - 1] = true;
	}

	bool vst[10];
	for (int i = 0; i < 10; i++)vst[i] = false;
	vst[0] = true;
	cout << dfs(0, n, vst) << endl;
	getchar();
	getchar();
	return 0;
}