#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int h = ri();
	int w = ri();
	int a[h][w];
	for (auto &i : a) for (auto &j : i) j = ri();
	int dp[w][w];
	for (auto &i : dp) for (auto &j : i) j = -1000000000;
	dp[0][1] = 0;
	for (int i = 0; i < h; i++) {
		int sum[w + 1];
		sum[0] = 0;
		for (int j = 0; j < w; j++) sum[j + 1] = sum[j] + a[i][j];
		std::vector<int> insert[w][w];
		std::vector<int> erase[w][w];
		for (int j = 0; j < w; j++) for (int k = j; k < w; k++) {
			insert[j][k].push_back(dp[j][k] - sum[j]);
			erase[k][k].push_back(dp[j][k] - sum[j]);
		}
		int max[w][w];
		for (int j = 0; j < w; j++) {
			std::multiset<int> all{-1000000000};
			for (int k = 0; k < w; k++) {
				for (auto l : insert[k][j]) all.insert(l);
				for (auto l : erase[k][j]) all.erase(all.find(l));
				max[k][j] = *std::prev(all.end()) + sum[k + 1] + a[i][j];
			}
		}
		for (int j = 0; j < w; j++) for (int k = 0; k + 1 < w; k++)
			max[j][k + 1] = std::max(max[j][k + 1], max[j][k] + a[i][k + 1]);
		memcpy(dp, max, sizeof(max));
	}
	int res = 0;
	for (auto &i : dp) for (auto &j : i) res = std::max(res, j);
	printf("%d\n", res);
	return 0;
}
