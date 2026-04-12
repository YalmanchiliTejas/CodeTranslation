#include <bits/stdc++.h>

typedef long long ll;
const int N = 1054, mod = 1000000007;

int n, A, B, C, D;
int fact[N], finv[N];
int dp[2][N], *cur = *dp, *nxt = dp[1];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init() {
	int i;
	for (*fact = i = 1; i < N; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	--i, finv[i] = PowerMod(fact[i], mod - 2);
	for (; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

int main() {
	int i, j, k, ij, I; init();
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	*nxt = 1;
	for (i = A; i <= B; ++i) {
		memcpy(cur, nxt, (n + 1) << 2), I = PowerMod(finv[i], C);
		for (j = C, ij = i * j; j <= D && ij <= n; ++j, ij += i, I = (ll)I * finv[i] % mod)
			for (k = ij; k <= n; ++k) nxt[k] = (nxt[k] + (ll)cur[k - ij] * I % mod * finv[j]) % mod;
	}
	printf("%d\n", int((ll)nxt[n] * fact[n] % mod));
	return 0;
}