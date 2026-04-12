#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int a[110];
int pow(int x, int p) {
	if (p == 0) return 1;
	if (p == 1) return x;
	long long res = pow(x, p / 2);
	res = res * res % mod;
	if (p & 1) {
		res = res * x % mod;
	}
	return res;
}
int dp[110][110][2][2][2];
void add(int &x, long long v) {
	x += v;
	if (x >= mod) x -= mod;
}
void go(int l, int r, int b) {
	int h = *min_element(a + l, a + r);
	for (int i = l; i < r; i++) {
		if (a[i] == h) {
			if (i == l) {
				dp[l][i+1][0][0][0] = 1;
				dp[l][i+1][1][1][0] = 1;
			} else {
				for (int x = 0; x < 2; x++) {
					for (int y = 0; y < 2; y++) {
						for (int z = 0; z < 2; z++) {
							for (int u = 0; u < 2; u++) {
								add(dp[l][i+1][x][u][z|(y==u)], dp[l][i][x][y][z]);
							}
						}
					}
				}
			}
			continue;
		}
		int j = i;
		while (a[j] > h) ++j;
		go(i, j, h);
		if (i > l) {
			for (int x = 0; x < 2; x++) {
				for (int y = 0; y < 2; y++) {
					for (int z = 0; z < 2; z++) {
						long long d = dp[i][j][x][y][z];
						for (int u = 0; u < 2; u++) {
							for (int v = 0; v < 2; v++) {
								for (int w = 0; w < 2; w++) {
									add(dp[l][j][u][y][z|w|(v==x)], ((long long)dp[l][i][u][v][w] * d) % mod);
									if (!z) {
										add(dp[l][j][u][y^1][z|w|(v==(x^1))], ((long long)dp[l][i][u][v][w] * d) % mod);
									}

								}
							}
						}
					}
				}
			}
		} else {
			for (int x = 0; x < 2; x++) {
				int s = dp[l][j][x][0][0];
				add(s, dp[l][j][x^1][1][0]);
				dp[l][j][x][0][0] = dp[l][j][x^1][1][0] = s % mod;
				swap(dp[l][j][x][0][1], dp[l][j][x^1][1][1]);
			}
		}
		i = j - 1;
	}
	if (h - b == 1) return;
	int pa = (h - b - 1) & 1;
	long long m = pow(2, h - b - 2);
	for (int i = 0; i < 2; i++) {
		int s = dp[l][r][i][0][0];
		add(s, dp[l][r][i^1][1][0]);
		dp[l][r][i][0][0] = dp[l][r][i^1][1][0] = m * s % mod;
		swap(dp[l][r][i][0][1], dp[l][r][i^1][1][1]);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	go(0, n, 0);
	int ans = 0;
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			for (int z = 0; z < 2; z++) {
				add(ans, dp[0][n][x][y][z]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
