#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef long long int llint;

string S;
int K;
llint dp[105][4][2];

int main() {
	cin >> S >> K;
	int N = S.size();
	dp[0][0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				int nd = S[i] - '0';
				for (int d = 0; d < 10; d++) {
					int ni = i + 1, nj = j, nk = k;
					if (d != 0)nj++;
					if (nj > K)continue;
					if (k == 0) {
						if (d > nd)continue;
						if (d < nd)nk = 1;
					}
					dp[ni][nj][nk] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[N][K][0] + dp[N][K][1] << endl;
}