#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1001;
const ll MOD = (1e9)+7;

ll modPow(ll b, ll e) {
	if(!e) return 1;
	else if(e == 1) return b;
	else return modPow(b*b % MOD, e >> 1) * modPow(b, e & 1) % MOD;
}

int n, a, b, c, d;
ll C[MAX][MAX], dstr[MAX][MAX], dp[MAX][MAX];
int main() {
	cin >> n >> a >> b >> c >> d;
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	for(int i = 1; i <= n; i++) {
		dstr[i][1] = 1;
		for(int j = 2; i*j <= n; j++)
			dstr[i][j] = dstr[i][j-1] * C[i*j][i] % MOD * modPow(j, MOD - 2) % MOD;
	}
	dp[0][a-1] = 1;
	for(int i = 0; i <= n; i++) {
		for(int j = a; j <= b; j++) {
			dp[i][j] = dp[i][j-1];
			for(int k = c; k <= d && j*k <= i; k++) {
				dp[i][j] += dp[i-j*k][j-1] * C[i][j*k] % MOD * dstr[j][k] % MOD;
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[n][b] - dp[n][a-1];
}
