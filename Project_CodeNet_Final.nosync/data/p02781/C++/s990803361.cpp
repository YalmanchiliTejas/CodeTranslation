#include <cstdio>
#include <cstring>

char str[200];
int dp[150][6][3];

int dfs(const int& now, const int& cnt, const int& equal, const int& n,
const int& k) {
	if (now == n + 1) {
		return cnt == k;
	}
	if (cnt > k) {
		return 0;
	}
	if (dp[now][cnt][equal] >= 0 && !equal) {
		return dp[now][cnt][equal];
	}
	int max = equal ? str[now] - '0' : 9;
	int sum = 0;
	for (int i = 0; i <= max; ++i) {
		sum += dfs(now + 1, cnt + !!i, equal && (i == max), n, k);
	}
	return dp[now][cnt][equal] = sum;
}

int main(int argc, char** argv) {
	std::memset(dp, -1, sizeof(dp));
	int k;
	std::scanf("%s%d", str + 1, &k);
	std::printf("%d\n", dfs(1, 0, 1, std::strlen(str + 1), k));
	return 0;
}