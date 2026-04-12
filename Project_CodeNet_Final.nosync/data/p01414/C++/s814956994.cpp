#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int dp[1 << 16], n; vector<pair<int, int>>x;
int col[4][4]; queue<int>Q;
int main() {
	for (int i = 0; i < (1 << 16); i++)dp[i] = 999999999; dp[0] = 0;
	cin >> n; for (int i = 0; i < n; i++) { int a, b; cin >> a >> b; x.push_back(make_pair(a, b)); }
	Q.push(0); for (int i = 0; i < 4; i++) { string V; cin >> V; for (int j = 0; j < 4; j++) { if (V[j] == 'R')col[i][j] = 1; if (V[j] == 'B')col[i][j] = 2; if (V[j] == 'G')col[i][j] = 3; } }
	while (!Q.empty()) {
		int a1 = Q.front(); Q.pop(); int F[4][4];
		for (int i = 0; i < 16; i++) {
			if ((a1 / (1 << i)) % 2 == 1)F[i / 4][i % 4] = col[i / 4][i % 4];
			else F[i / 4][i % 4] = 0;
		}
		for (int i = 0; i < x.size(); i++) {
			for (int j = 1 - (int)x[i].first; j <= 3; j++) {
				for (int k = 1 - (int)x[i].second; k <= 3; k++) {
					for (int o = 1; o < 4; o++) {
						int G = a1;
						for (int l = max(-j, 0); l < min(4 - j, x[i].first); l++) {
							for (int m = max(-k, 0); m < min(4 - k, x[i].second); m++) {
								int cx = j + l, cy = k + m, cl = cx * 4 + cy;
								if (F[cx][cy] >= 1 && col[cx][cy] != o) { G -= (1 << cl); }
								else if (F[cx][cy] == 0 && col[cx][cy] == o) { G += (1 << cl); }
							}
						}
						int bits = G;
						if (dp[bits] > dp[a1] + 1) { dp[bits] = dp[a1] + 1; Q.push(bits); }
					}
				}
			}
		}
	}
	cout << dp[65535] << endl;
	return 0;
}