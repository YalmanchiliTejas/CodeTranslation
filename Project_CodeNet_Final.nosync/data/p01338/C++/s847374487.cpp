#include<iostream>
#include<algorithm>
using namespace std;
int dp[6][3125], n, x[7][5], pp[5] = { 0,0,60,70,80 };
int power4[6] = { 1,4,16,64,256,1024 }, power5[6] = { 1,5,25,125,625,3125 };
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++)cin >> x[j][k];
		}
		for (int j = 0; j < 6; j++) { for (int k = 0; k < 3125; k++) { dp[j][k] = -1; } }
		for (int j = 0; j < 256; j++) {
			int bit[4]; for (int k = 0; k < 4; k++)bit[k] = (j / power4[k]) % 4;
			int y[7][5]; for (int k = 0; k < 35; k++)y[k / 5][k % 5] = x[k / 5][k % 5];
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < bit[k]; l++) {
					if (y[0][k] >= 1) { y[0][k]++; if (y[0][k] == 5)y[0][k] -= 4; }
					if (y[1][k] >= 1) { y[1][k]++; if (y[1][k] == 5)y[1][k] -= 4; }
					if (y[0][k + 1] >= 1) { y[0][k + 1]++; if (y[0][k + 1] == 5)y[0][k + 1] -= 4; }
					if (y[1][k + 1] >= 1) { y[1][k + 1]++; if (y[1][k + 1] == 5)y[1][k + 1] -= 4; }
				}
			}
			int W = 0; for (int k = 0; k < 5; k++)W += power5[k] * y[1][k];
			int W2 = 0; for (int k = 0; k < 5; k++)W2 += pp[y[0][k]];
			dp[0][W] = max(dp[0][W], W2);
		}
		for (int j = 1; j <= 3; j++) {
			for (int k = 0; k < 3125; k++) {
				if (dp[j - 1][k] == -1)continue;
				int bit[5]; for (int l = 0; l < 5; l++)bit[l] = (k / power5[l]) % 5;
				for (int l = 0; l < 256; l++) {
					int y[7][5]; for (int m = 0; m < 35; m++)y[m / 5][m % 5] = x[m / 5][m % 5];
					for (int m = 0; m < 5; m++)y[j][m] = bit[m];
					int bit2[4]; for (int m = 0; m < 4; m++) { bit2[m] = (l / power4[m]) % 4; }
					for (int m = 0; m < 4; m++) {
						for (int o = 0; o < bit2[m]; o++) {
							if (y[j + 0][m + 0] >= 1) { y[j + 0][m + 0]++; if (y[j + 0][m + 0] == 5)y[j + 0][m + 0] -= 4; }
							if (y[j + 1][m + 0] >= 1) { y[j + 1][m + 0]++; if (y[j + 1][m + 0] == 5)y[j + 1][m + 0] -= 4; }
							if (y[j + 0][m + 1] >= 1) { y[j + 0][m + 1]++; if (y[j + 0][m + 1] == 5)y[j + 0][m + 1] -= 4; }
							if (y[j + 1][m + 1] >= 1) { y[j + 1][m + 1]++; if (y[j + 1][m + 1] == 5)y[j + 1][m + 1] -= 4; }
						}
					}
					int W = 0; for (int m = 0; m < 5; m++) W += power5[m] * y[j + 1][m];
					int W2 = 0; for (int m = 0; m < 5; m++)W2 += pp[y[j][m]];
					dp[j][W] = max(dp[j][W], dp[j - 1][k] + W2);
				}
			}
		}
		int maxn = 0;
		for (int j = 0; j < 3125; j++) {
			if (dp[3][j] == -1)continue;
			int sum1 = 0; for (int k = 0; k < 5; k++)sum1 += pp[(j / power5[k]) % 5];
			maxn = max(maxn, dp[3][j] + sum1);
		}
		cout << maxn << endl;
	}
	return 0;
}