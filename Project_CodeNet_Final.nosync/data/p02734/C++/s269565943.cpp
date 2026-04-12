#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 3e3, M = 998244353;
int n, s, a[mxN];
ll dp[mxN + 1][mxN + 1], ans;
//dp[i][sum] = Σf(L, R), 1 ≤ L ≤ R ≤ i
//f(L, R)在這裡定義為 符合 [L <= x1 < x2 < ... < xk <= R 且 Ax1 + Ax2 + ... + Axk = sum] 的 sequence(X1, X2, ..., Xk)數量

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		memcpy(dp[i + 1], dp[i], sizeof(dp[0]));
		//start a new sequence
		//void *memcpy(void*dest, const void *src, size_t n);
		//由src指向地址為起始地址的連續n個位元組的資料複製到以destin指向地址為起始地址的空間內
		//sizeof(dp[0]) = 24008 因為mxN + 1 = 3001，long long佔8個位元組
		dp[i + 1][a[i]] = (dp[i + 1][a[i]] + i + 1) % M;
		//R = i, L從0到i，共有i + 1種 pair(L, R)
		for (int j = 0; j + a[i] <= s; ++j) {	//超過 s 的不用記
			dp[i + 1][j + a[i]] = (dp[i + 1][j + a[i]] + dp[i][j]) % M;
		}
		//cout << "dp[" << i + 1 << "][" << s << "] = "<< dp[i + 1][s] << endl;
		ans = (dp[i + 1][s] + ans) % M;
	}
	cout << ans << endl;
}