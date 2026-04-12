#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N;
vector <int> E[MAXN];
int dp[MAXN][2];

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

int dfs(int x, int p) {
	int sum = 0, cnt = 0, mx = -1;
	for (auto it : E[x]) 
		if (it != p) {
			sum += dfs(it, x);
			mx = max(mx, dp[it][1] - dp[it][0]);
			cnt++;
		}
	dp[x][0] = sum + mx == cnt;
	dp[x][1] = sum == cnt;
	return dp[x][0];
}

int main() {
	load();
	puts(dfs(1, 0) ? "Second" : "First");
	return 0;
}