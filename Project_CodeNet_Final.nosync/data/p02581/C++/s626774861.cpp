#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int INF = 0x3f3f3f3f;

int dp[2010][2010], ndp[2010][2010];
int row[2010], MAXJ;
int a[6010];

int Query() {
	return MAXJ;
}

int query(int x) {
	return row[x];
}

void modify(int x, int y) {
	if (dp[x][y] == ndp[x][y]) return ;
	row[x] = max(row[x], ndp[x][y]);
	MAXJ = max(MAXJ, ndp[x][y]);
	dp[x][y] = ndp[x][y];
}

bool check(int a, int b, int c) {
	return a == b && b == c;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < 3 * n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	if (n == 1) {
		if (a[0] == a[1] && a[1] == a[2]) {
			printf("1\n");
		} else printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -INF;
		}
		row[i] = -INF;
	}
	MAXJ = -INF;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			int minj = 0x3f3f3f3f, maxj = -1;
			for (int k = 0; k < 5; k++) {
				if (i == k || j == k) continue;
				minj = min(minj, a[k]), maxj = max(maxj, a[k]);
			}
			dp[a[i]][a[j]] = dp[a[j]][a[i]] = minj == maxj;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			MAXJ = max(MAXJ, dp[i][j]);
			row[i] = max(row[i], dp[i][j]);
		}
	}
	int base = 0, now = 5;
	for (int i = 2; i < n; i++) {
		int x = a[now], y = a[now + 1], z = a[now + 2]; now += 3;
		if (x == y && y == z) {
			base++;
			for (int j = 0; j < n; j++) {
				ndp[x][j] = ndp[j][x] = max(dp[x][j], max(query(j) - 1, dp[j][x]));
			}
			ndp[x][x] = max(ndp[x][x], Query() - 1);
		} else {
			if (x == z) swap(z, y);
			if (y == z) swap(x, z);
			if (x == y) {
				for (int j = 0; j < n; j++) {
					ndp[z][j] = ndp[j][z] = max(dp[z][j], max(query(j), dp[j][x] + 1));
					ndp[x][j] = ndp[j][x] = max(dp[x][j], query(j));
				}
				ndp[x][z] = ndp[z][x] = max(ndp[x][z], max(Query(), dp[y][y] + 1));
				ndp[x][x] = max(ndp[x][x], max(Query(), dp[z][z] + 1));
			} else {
				for (int j = 0; j < n; j++) {
					ndp[x][j] = ndp[j][x] = max(dp[x][j], query(j));
					ndp[y][j] = ndp[j][y] = max(dp[y][j], query(j));
					ndp[z][j] = ndp[j][z] = max(dp[z][j], query(j));
				}
				ndp[x][y] = ndp[y][x] = max(ndp[x][y], max(Query(), dp[z][z] + 1));
				ndp[x][z] = ndp[z][x] = max(ndp[x][z], max(Query(), dp[y][y] + 1));
				ndp[y][z] = ndp[z][y] = max(ndp[y][z], max(Query(), dp[x][x] + 1));
			}
		}
		for (int j = 0; j < n; j++) {
			modify(x, j), modify(j, x);
			modify(y, j), modify(j, y);
			modify(z, j), modify(j, z);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dp[i][j] + check(i, j, a[3 * n - 1]) + base);
		}
	}
	printf("%d\n", ans);
	return 0;
}
