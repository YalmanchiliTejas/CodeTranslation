#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)



typedef long long ll;
int H, W;
int A[405][405];
ll dp[405][405][405];
//-----------------------------------------------------------------
int main() {
	cin >> H >> W;
	rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];

	dp[0][0][0] = A[0][0];

	int N = max(H, W);
	rep(i, 0, N * 2) rep(j, 0, N) rep(k, j, N) {
		int ax = j;
		int ay = i - j;
		int bx = k;
		int by = i - k;
		if (ay < 0) continue;
		if (by < 0) continue;

		//printf("dp[%d][%d][%d] = (%d, %d) and (%d, %d)\n", i, j, k, ax, ay, bx, by);

		if (ax < N - 1 && bx < N - 1)
			dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k] + ((ax + 1 == bx + 1 && ay == by) ? A[ay][ax + 1] : A[ay][ax + 1] + A[by][bx + 1]));

		if (ax < N - 1 && by < N - 1)
			dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + ((ax + 1 == bx && ay == by + 1) ? A[ay][ax + 1] : A[ay][ax + 1] + A[by + 1][bx]));

		if (ay < N - 1 && bx < N - 1)
			dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + ((ax == bx + 1 && ay + 1 == by) ? A[ay + 1][ax] : A[ay + 1][ax] + A[by][bx + 1]));

		if (ay < N - 1 && by < N - 1)
			dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + ((ax == bx && ay + 1 == by + 1) ? A[ay + 1][ax] : A[ay + 1][ax] + A[by + 1][bx]));

		if (ax == bx && ay == by) {
			if (ax == W - 1 && ay == H - 1) {
				cout << dp[i][j][k] << endl;
				return 0;
			}
		}

		//printf("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
	}
}