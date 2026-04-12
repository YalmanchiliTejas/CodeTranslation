#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int x[101][101]; vector<int>D;
int n, m, p, dp[100000];
queue<int>Q;
int main() {
	cin >> n >> m >> p;
	for (int i = 0; i < m; i++) { int r; cin >> r; D.push_back(r); }
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < p; j++)cin >> x[i][j];
	}
	for (int i = 1; i < 100000; i++)dp[i] = 998244353; Q.push(0);
	while (!Q.empty()) {
		int i = Q.front(); Q.pop();
		int bit[16]; for (int j = 0; j < m; j++)bit[j] = (i / (1 << j)) % 2;

		for (int o = 0; o < p; o++) {
			int bit2[16]; for (int k = 0; k < m; k++)bit2[k] = 1;
			for (int j = 0; j < m; j++)
			{
				if (bit[j] == 0) {
					int to = x[D[j]][o];
					for (int l = 0; l < m; l++) {
						if (D[l] == to)bit2[l] = 0;
					}
				}
			}
			int cnt = 0;
			for (int j = 0; j < m; j++)cnt += (1 << j)*bit2[j];
			if (dp[cnt] == 998244353) {
				dp[cnt] = min(dp[cnt], dp[i] + 1);
				Q.push(cnt);
			}
		}
	}
	cout << dp[(1 << m) - 1] << endl;
	return 0;
}