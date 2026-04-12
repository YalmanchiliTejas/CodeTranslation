#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int dp[101][4][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S;
	cin >> S;
	int n = S.size();
	int K;
	cin >> K;
	dp[0][0][0] = 1;
	rep(i, n)rep(j, 4)rep(k, 2) {
		int h = S[i] - '0';
		rep(d, 10) {
			//aは桁,bは0出ない個数,cは判定
			//dpだからか...
			int a = i + 1, b = j, c = k;
			if (d != 0) b++;
			if (b > K) continue;
			if (k == 0) {
				if (d > h) continue;
				if (d < h) c = 1;
			}
			dp[a][b][c] += dp[i][j][k];
		}
	}
	int ans = dp[n][K][0] + dp[n][K][1];
	dunk(ans);
	return 0;
}