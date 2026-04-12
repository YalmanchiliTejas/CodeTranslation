#include <bits/stdc++.h>

const int MAXN = 10010;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
const int MAXS = 20010;
int fac[MAXS], inv[MAXS];
int C(int a, int b) { return (LL) fac[a] * inv[b] % mod * inv[a - b] % mod; }
int down(int a, int b) { return (LL) fac[a] * inv[a - b] % mod; }
int dp[MAXN][MAXN];
char s1[MAXN], s2[MAXN];
int A, B;
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXS; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXS; ++i) inv[i] = mul(inv[i - 1], inv[i]);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> s1 >> s2; int n = strlen(s1);
	for (int i = 0; i != n; ++i)
		if (s1[i] == '1' && s2[i] == '1') ++A;
		else if (s1[i] == '1' || s2[i] == '1') ++B;
	B >>= 1;
	dp[0][0] = 1;
	for (int i = 0; i <= A; ++i)
		for (int j = 0; j <= B; ++j) {
			reduce(dp[i + 1][j] += mul(dp[i][j], mul(i + 1, j)) - mod);
			reduce(dp[i][j + 1] += mul(dp[i][j], mul(j + 1, j + 1)) - mod);
		}
	int ans = 0;
	for (int i = 0; i <= A; ++i)
		reduce(ans += (LL) dp[i][B] * down(A, A - i) % mod * C(A + B, A - i) % mod * fac[A - i] % mod - mod);
	std::cout << ans << std::endl;
	return 0;
}
