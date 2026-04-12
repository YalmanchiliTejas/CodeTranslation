#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 110;
const int K = 3;
int dp[5][N][K];
int n, k;
char str[N];
int ans;

int dfs(int m, int u, int limit) {
	if (u > k)
		return 0;
	if (m > n)
		return (u == k);
	if (dp[u][m][limit] != -1)
		return dp[u][m][limit];

	int t = limit == 1 ? str[m] - '0' : 9, ans = 0;

	for (int i = 0; i <= t; i++)
		ans += dfs(m + 1, u + (i != 0), limit && i == t);
	return dp[u][m][limit] = ans;
}

int main() {
	cin >> (str + 1) >> k;
	n = strlen(str + 1);
	memset(dp, -1, sizeof dp);
	cout << dfs(1, 0, 1) << endl;

	return 0;
}