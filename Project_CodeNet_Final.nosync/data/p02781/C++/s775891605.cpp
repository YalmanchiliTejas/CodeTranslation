#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
int main() {
	string s;
	cin >> s;
	int m;
	cin >> m;
	int n = s.size();
	VVV dp(n + 1, VV(m + 5, V(2, 0)));
	int i, j, k;
	dp[0][0][0] = 1; // 初期状態はちゃんと設定しよう!
	for (i = 0; i < n; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k <= 1; k++) {
				int digit = s[i] - '0';
				for (int num = 0; num <= 9; num++) {
					int nj = (num) ? j + 1 : j;
					int nk = k;
					if (nk == 0) {
						if (num > digit) continue;
						if (num == digit) nk = 0;
						if (num < digit) nk = 1;
					}
					dp[i + 1][nj][nk] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[n][m][0] + dp[n][m][1];
	return 0;
}