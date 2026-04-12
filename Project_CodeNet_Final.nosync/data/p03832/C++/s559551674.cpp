//TLE
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n, a, b, c, d;
int comb[1001][1001];
int mod = 1000000007;
int dp[1001][1001];

void make_comb() {
	comb[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
			comb[i][j] %= mod;
		}
	}
}

//x～b人グループを作る。残りn人いる。何通り？
int dfs(int x, int n) {
	if (x == b + 1) {
		return (n == 0);
	}
	if (dp[x][n] != -1) {
		return dp[x][n];
	}
	
	int ret = dfs(x + 1, n);
	
	for (int i = c; i <= d; i++) {
		if (n - x * i < 0) { break; }
		
		int cnt = comb[n][x * i];
		for (int j = 0; j < i; j++) {
			cnt *= comb[x * (i - j) - 1][x - 1];
			cnt %= mod;
		}
		
		ret += cnt * dfs(x + 1, n - x * i);
		ret %= mod;
	}
	return (dp[x][n] = ret);
}

signed main() {
	cin >> n >> a >> b >> c >> d;
	make_comb();
	for (int i = a; i <= b; i++) { for (int j = 0; j <= n; j++) { dp[i][j] = -1; } }
	
	cout << dfs(a, n) << endl;
	return 0;
}