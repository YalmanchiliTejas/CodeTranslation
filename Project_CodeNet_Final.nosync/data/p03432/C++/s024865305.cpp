#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)
#define Forr(i, j, k) for (int i = j; i >= k; i--)

using namespace std;

const int Mod = 998244353, r = 3;
const int N = 1 << 15, M = 210;

int Pow(int x, int e) {
	int ret = 1;
	while (e) {
		if (e & 1) ret = 1ll * ret * x % Mod;
		x = 1ll * x * x % Mod;
		e >>= 1;
	}
	return ret;
}

int rev[N];

void DFT(int *A, int n, int f) {
	For(i, 0, n - 1) if (i < rev[i]) swap(A[i], A[rev[i]]);
	static int w[N];
	for (int i = 1; i < n; i <<= 1) {	
		w[0] = 1, w[1] = Pow(r, (Mod - 1) / (i << 1));
		if (f == -1) w[1] = Pow(w[1], Mod - 2);
		for (int j = 2; j < i; ++j) w[j] = 1ll * w[j - 1] * w[1] % Mod;

		for (int j = 0; j < n; j += i << 1)
			for (int k = 0; k < i; ++k) {
				int x = A[j + k], y = 1ll * w[k] * A[i + j + k] % Mod;
				A[j + k] = (x + y) % Mod, A[i + j + k] = (x + Mod - y) % Mod;
			}

	}
}

int dp[M][N];
int fac[N], rfac[N];

int C(int n, int m) {
	return 1ll * fac[n] * rfac[m] % Mod * rfac[n - m] % Mod;
}

int A[N], mul[N];

int main() {

	int n = N - 5, m;
	fac[0] = 1;
	For(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % Mod;
	rfac[n] = Pow(fac[n], Mod - 2);
	Forr(i, n, 1) rfac[i - 1] = 1ll * rfac[i] * i % Mod;

	scanf("%d%d", &n, &m);
	dp[0][0] = 1;

	int l = 1;
	while (l <= n * 2) l <<= 1;
	For(i, 0, l - 1) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? l / 2 : 0);
	For(i, 1, n) mul[i] = rfac[i + 2];
	DFT(mul, l, 1);
	int inv = Pow(l, Mod - 2);

	For(i, 1, m) {
		For(j, 0, l - 1) A[j] = 1ll * dp[i - 1][j] * rfac[j] % Mod;
		DFT(A, l, 1);
		For(j, 0, l - 1) A[j] = 1ll * A[j] * mul[j] % Mod;
		DFT(A, l, -1);
		For(j, 0, l - 1) A[j] = 1ll * A[j] * inv % Mod * fac[j + 2] % Mod;
		For(j, 0, n) dp[i][j] = (A[j] + 1ll * dp[i - 1][j] * (C(j + 1, 2) + 1)) % Mod;
	}

	int ans = 0;
	For(i, 0, n) ans = (ans + 1ll * dp[m][i] * C(n, i)) % Mod;
	printf("%d\n", ans);

	return 0;
}