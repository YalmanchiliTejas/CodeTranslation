#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 3e5;
const int mod = 1e9 + 7;
char s[N];
int n, d;
ll dp[N][101][2];
int main() {
	scanf("%s", s + 1);
	cin >> d;
	n = strlen(s + 1);
	dp[0][0][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < d; ++j) {
			for (int k = 0; k < 10; ++k) {
				(dp[i][(j + k) % d][0] += dp[i - 1][j][0]) %= mod;
				if (s[i] - '0' == k)
					(dp[i][(j + k) % d][1] += dp[i - 1][j][1]) %= mod;
				if (s[i] - '0' > k)
					(dp[i][(j + k) % d][0] += dp[i - 1][j][1]) %= mod;
			}
		}
	}
	cout << (dp[n][0][0] + dp[n][0][1] + mod - 1) % mod;
}

