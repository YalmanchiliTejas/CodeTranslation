#include<bits/stdc++.h>
using namespace std;
const int N(1111);
int dp[N], fac[N], inv[N], invFac[N][N];
int modulo(1e9 + 7);
int main() {
	fac[0] = 1;
	invFac[0][1] = 1;
	for(int i(1); i <= 1000; i++) {
		fac[i] = (long long)i * fac[i - 1] % modulo;
		inv[i] = i == 1 ? 1 : inv[i - modulo % i] * (long long)((modulo + i - 1) / i) % modulo;
		invFac[i][1] = (long long)invFac[i - 1][1] * inv[i] % modulo;
		//cout << i << endl;
		for(int j(2); j <= 1000; j++) {
			invFac[i][j] = (long long)invFac[i][j - 1] * invFac[i][1] % modulo;
		}
	}
//	cout << fac[2] << ' ' << invFac[2][1] << endl;
	int n, a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	dp[n] = 1;
	for(int i(a); i <= b; i++) {
		for(int j(0); j <= n; j++) {
			for(int k(max(1, c)); k <= min(d, j / i); k++) {
				dp[j - k * i] = (dp[j - k * i] + (long long)dp[j] * fac[j] % modulo * invFac[i][k] % modulo * invFac[j - k * i][1] % modulo * invFac[k][1]) % modulo;
			}
		}
		//cout << dp[0] << ' ' << dp[3] << endl;
	}
	cout << dp[0] << endl;
}
