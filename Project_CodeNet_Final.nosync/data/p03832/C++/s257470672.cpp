#define _USE_MATH_DEFINES
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cmath>
#define LL long long
LL N, A, B, C, D;
LL DP[1010][1010];
LL kai[1010];
LL fer[1010];
const LL mod = 1e9 + 7;
LL fermat(LL x, int y) {
	if (y == 0)return 1;
	if (y == 1)return x;
	LL F = fermat(x, y / 2);
	F *= F;
	F %= mod;
	if (y % 2)return (F*x) % mod;
	if (!(y % 2))return F;
}


int main() {
	std::cin >> N >> A >> B >> C >> D;
	kai[0] = 1;
	for (LL i = 1; i <= N; i++) {
		kai[i] = kai[i - 1] * i;
		kai[i] %= mod;
	}
	fer[N] = fermat(kai[N], mod - 2);
	for (LL i = N; i >= 1; i--) {
		fer[i - 1] = (fer[i] * i) % mod;
	}
	DP[A - 1][0] = 1;
	for (int i = A; i <= B; i++) {
		for (int j = 0; j <= N; j++) {
			DP[i][j] += DP[i - 1][j];
			DP[i][j] %=mod;
			LL a = 1;
			for (int m = 1; m < C; m++) {
				a *= fer[i];
				a %= mod;
			}
			for (int k = C; k <= D; k++) {
				if (i*k + j > N) {
					break;
				}
				LL KA = kai[N - j] * fer[N - j - i * k];
				KA %= mod;
				a *= fer[i];
				a %= mod;
				KA *= a;
				KA %= mod;
				KA *= fer[k];
				KA %= mod;
				DP[i][i*k + j] += DP[i - 1][j] * KA;
				DP[i][i*k + j] %= mod;
			}
		}
	}
	std::cout << DP[B][N] << std::endl;
	return 0;
}