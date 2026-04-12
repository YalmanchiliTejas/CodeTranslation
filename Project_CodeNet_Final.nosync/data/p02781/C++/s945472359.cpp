#include <iostream>
#include <string>
using namespace std;

int dp[101][4][2];

int main(void) {
	string S;
	cin >> S;
	int K;
	cin >> K;

	dp[0][0][0] = 1;
	int x = S.length();
	for (int i = 0; i < x; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k <= 1; k++) {
				int nd = S[i] - '0';
				for (int next = 0; next <= 9; next++) {
					int ni = i+1, nj = j, nk = k;
					if (next != 0) nj++;
					if (nj > K) continue;
					if (k == 0) {
						if (next > nd) continue;
						if (next < nd) nk = 1;
					}
					dp[ni][nj][nk] += dp[i][j][k];
				}
			}
		}
	}
	int ans = dp[x][K][0] + dp[x][K][1];
	cout << ans << endl;
  return 0;
}
