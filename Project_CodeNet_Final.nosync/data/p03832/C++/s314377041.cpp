#include <cstdio>

typedef long long ll;

const int MAXN = 1E3 + 10;
const int MOD = 1E9 + 7;

ll inv[MAXN], fac[MAXN], facinv[MAXN];
ll f[MAXN][MAXN];

void getInv(int n = MAXN - 1){
	inv[0] = 0, inv[1] = 1;
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= n; ++i){
		inv[i] = inv[MOD % i]  * (MOD - MOD / i) % MOD;
		fac[i] = fac[i - 1] * i % MOD;
		facinv[i] = facinv[i - 1] * inv[i] % MOD;
	}	
}

int main(){
	getInv();

	int n, A, B, C, D;
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	f[0][0] = fac[n];
	for (int i = 1; i <= n; ++i){
		ll t0 = 1;
		for (int j = 0; j < C; ++j)
			t0 = t0 * facinv[i] % MOD;

		for (int j = 0; j <= n; ++j){
			f[i][j] = f[i - 1][j];
			if (i < A || B < i || C * i > j)
				continue;

			ll t = t0;
			for (int k = C; k <= D && k * i <= j; ++k, t = t * facinv[i] % MOD)
				f[i][j] = (f[i][j] + f[i - 1][j - k * i] * facinv[k] % MOD * t) % MOD;
		}
	}

	printf("%d\n", (int)f[n][n]);
	return 0;
}
