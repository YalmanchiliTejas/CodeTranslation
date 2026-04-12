#include <bits/stdc++.h>
#define maxn 2333
using namespace std;
int a[maxn * 3];
int dp[maxn][maxn];
int DP[maxn][maxn];
int MaxR[maxn], MaxC[maxn];

bool has[maxn]; 
int main() {
//	freopen("F.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 3 * n; ++i) {
		scanf("%d", a + i);
	}
	if(n == 1) {
		printf("%d\n", a[1] == a[2] && a[2] == a[3]);
	} else {
		int Max = 0;
		memset(dp, 0x80, sizeof dp);
		memset(DP, 0x80, sizeof DP);
		memset(MaxR, 0x80, sizeof MaxR);
		memset(MaxC, 0x80, sizeof MaxC);
		dp[a[1]][a[2]] = dp[a[2]][a[1]] = 0;
		has[a[1]] = has[a[2]] = true;
		int tot = 0;
		for(int _ = 1; _ < n; ++_) {
			int id = _ * 3, x, y, z;
			x = a[id], y = a[id + 1], z = a[id + 2];
			if(x == y && y == z) {
				++tot;
				continue;
			}
			for(int i = 1; i <= n; ++i) {
				if(has[i]) DP[x][i] = DP[i][x] = DP[y][i] = DP[i][y] = DP[z][i] = DP[i][z] = 0; // availability 
			}
			has[x] = has[y] = has[z] = true;
			DP[z][x] = DP[x][z] = max(Max, dp[y][y] + 1); // drop 1 card from x, y, z
			DP[x][y] = DP[y][x] = max(Max, dp[z][z] + 1);
			DP[y][z] = DP[z][y] = max(Max, dp[x][x] + 1);
			for(int i = 1; i <= n; ++i) { // drop j, y, z, left i, x
				DP[i][x] = DP[x][i] = max(DP[i][x], max(MaxR[i], MaxC[i]));
				DP[i][y] = DP[y][i] = max(DP[i][y], max(MaxR[i], MaxC[i]));
				DP[i][z] = DP[z][i] = max(DP[i][z], max(MaxR[i], MaxC[i]));
			}
			for(int i = 1; i <= n; ++i) { // drop 2 card from x, y, z
				DP[x][x] = max(DP[x][x], dp[i][x] + (i == y && y == z));
				DP[i][y] = DP[y][i] = max(DP[i][y], dp[i][x] + (x == z));
				DP[i][z] = DP[z][i] = max(DP[i][z], dp[i][x] + (x == y));
			}
			for(int i = 1; i <= n; ++i) {
				DP[y][y] = max(DP[y][y], dp[i][y] + (i == x && x == z));
				DP[i][x] = DP[x][i] = max(DP[i][x], dp[i][y] + (y == z));
				DP[i][z] = DP[z][i] = max(DP[i][z], dp[i][y] + (y == x));
			}
			for(int i = 1; i <= n; ++i) {
				DP[z][z] = max(DP[z][z], dp[i][z] + (i == x && x == y));
				DP[i][x] = DP[x][i] = max(DP[i][x], dp[i][z] + (z == y));
				DP[i][y] = DP[y][i] = max(DP[i][y], dp[i][z] + (z == x));
			}
			for(int i = 1; i <= n; ++i) {
				Max = max(Max, DP[i][x]);
				Max = max(Max, DP[i][y]);
				Max = max(Max, DP[i][z]);
				MaxR[i] = max(MaxR[i], max(DP[i][x], max(DP[i][y], DP[i][z])));
				MaxC[x] = max(MaxC[x], DP[x][i]); 
				MaxC[y] = max(MaxC[y], DP[y][i]); 
				MaxC[z] = max(MaxC[z], DP[z][i]);
				dp[i][x] = dp[x][i] = DP[i][x];
				dp[i][y] = dp[y][i] = DP[i][y];
				dp[i][z] = dp[z][i] = DP[i][z];
			}
			for(int i = 1; i <= n; ++i) DP[i][x] = DP[x][i] = DP[i][y] = DP[y][i] = DP[i][z] = DP[z][i] = 0x80808080;
//			for(int i = 1; i <= n; ++i) 
//				for(int j = 1; j <= n; ++j)
//					assert(dp[i][j] == dp[j][i]);
//			cerr << _ << endl; 
		}
		int Ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				Ans = max(Ans, dp[i][j] + (i == j && j == a[3 * n]));
			}
		}
		Ans += tot;
		printf("%d\n", Ans);
	}
	return 0;
}