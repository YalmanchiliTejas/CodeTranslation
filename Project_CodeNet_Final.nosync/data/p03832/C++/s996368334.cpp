#include<cstdio>
#include<algorithm>
using namespace std;
int n, A, B, C, D;
int DP[1010][1010], Mod = 1000000007, F[1010], invF[1010];
long long po[1010];
int Pow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1)r = 1ll * r*a%Mod;
		a = 1ll * a*a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	int i, j;
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	DP[A - 1][0] = 1;
	F[0] = 1;
	invF[0] = 1;
	for (i = 1; i <= n; i++) {
		F[i] = 1ll * F[i - 1] * i%Mod;
		invF[i] = Pow(F[i], Mod - 2);
	}
	for (i = A; i <= B; i++) {
		long long inv = Pow(F[i], Mod - 2);
		po[0] = 1;
		for (j = 1; j <= n; j++)po[j] = po[j - 1] * inv%Mod;
		for (j = 0; j <= n; j++) {
			DP[i][j] = (DP[i][j] + DP[i - 1][j]) % Mod;
			int M = min(D, (n - j) / i);
			for (int k = C; k <= M; k++) {
				DP[i][j + k * i] = (DP[i][j + k * i] + DP[i - 1][j] * po[k]%Mod*invF[k]) % Mod;
			}
		}
	}
	printf("%lld\n", 1ll * DP[B][n] * F[n] % Mod);
}