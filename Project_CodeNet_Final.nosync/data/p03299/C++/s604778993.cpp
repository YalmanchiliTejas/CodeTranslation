#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
const int MAXN = 110;
int A[MAXN], n, li[MAXN], bak;
int dp[MAXN][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], li[++bak] = A[i];
	li[++bak] = 1; std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	li[bak + 1] = 0x3f3f3f3f;
	for (int i = 1; i <= n; ++i)
		A[i] = std::lower_bound(li + 1, li + 1 + bak, A[i]) - li;
	dp[0][0] = 1;
	const int inv2 = mod + 1 >> 1;
	auto calc = [] (int l, int r, int H) {
		r = std::min(r, H - 1);
		return pow(2, H, (pow(inv2, l) - pow(inv2, r + 1) + mod) % mod);
	} ;
	for (int i = 1; i < A[1]; ++i) {
		dp[1][i] = pow(2, li[A[1]] - li[i]) - pow(2, li[A[1]] - li[i + 1]);
		reduce(dp[1][i]);
		dp[1][i] = mul(dp[1][i], 2);
	}
	dp[1][A[1]] = 2;
	for (int i = 2; i <= n; ++i) {
		if (A[i] >= A[i - 1]) {
			int delta = li[A[i]] - li[A[i - 1]];
			for (int j = 1; j < A[i - 1]; ++j) {
				reduce(dp[i][j] += pow(2, delta, dp[i - 1][j]) - mod);
			}
			for (int j = A[i - 1]; j <= A[i]; ++j) {
				int t = calc(li[j], li[j + 1] - 1, li[A[i]]) + (j == A[i]);
				t = mul(t, 2);
				reduce(dp[i][j] += mul(t, dp[i - 1][A[i - 1]]) - mod);
			}
		} else {
			for (int j = 1; j <= A[i - 1]; ++j)
				reduce(dp[i][std::min(j, A[i])] += mul(dp[i - 1][j], 1 + (j >= A[i])) - mod);
		}
	}
	std::cout << std::accumulate(dp[n], dp[n + 1], 0ll) % mod << std::endl;
	return 0;
}
