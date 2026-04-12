#include <bits/stdc++.h>
using namespace std;

int n, m;
bool adjMat[8][8];
int dp[256][8];

int main() {
	for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) adjMat[i][j] = false;
	for(int i = 0; i < 256; i++) for(int j = 0; j < 8; j++) dp[i][j] = 0;
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b; a--; b--;
		adjMat[a][b] = adjMat[b][a] = true;
	}

	for(int i = 0; i < 8; i++) dp[(1 << n) - 1][i] = 1;
	for(int i = ((1 << n) - 2); i >= 1; i--) {
		for(int j = 0; j < 8; j++) {
			if((i&(1 << j)) == 0) continue;
			for(int k = 0; k < 8; k++) {
				if((i&(1 << k)) == 0 && adjMat[j][k]) dp[i][j] += dp[i + (1 << k)][k];
			}
		}
	}
	cout << dp[1][0] << endl;

	return 0;
}