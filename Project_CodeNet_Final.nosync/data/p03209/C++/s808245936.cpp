#include "bits/stdc++.h"
using namespace std;
const int MAX = 700000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
/*第二引数で第一引数を割ったときの切り上げの計算*/
long long int maxtime(long long int x, long long int y) {
	return(x + y - 1) / y;

}
/*最大公約数*/
long long int lcm(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;

	if (number2 > number1) {
		m = number2;
		n = number1;
	}
	long long int s = -1;
	while (s != 0) {
		s = m % n;
		m = n;
		n = s;
	}
	return m;
}
/*最大公倍数*/
long long int gcd(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;
	return m / lcm(m, n) * n;
}
long long int dp[300020] = {};
int main() {
	long long int n, x;
	cin >> x >> n;
	long long int p, b;
	long long int pathi[52] = {};
	long long int bured[52] = {};
	long long int sum[52] = {};
	pathi[0] = 1;
	bured[0] = 0;
	sum[0] = pathi[0] + bured[0];
	for (int i = 1; i <= 50; i++) {
		pathi[i] = pathi[i - 1] * 2 + 1;
		bured[i] = bured[i - 1] * 2 + 2;
		sum[i] = pathi[i] + bured[i];
	}
	long long int ansb = 0;
	long long int ansp = 0;
	while (n > 0) {
		if (x == 0) {
			ansp = ansp + 1;
			break;
		}
		if (sum[x] == n) {
			ansp = ansp + pathi[x];
			ansb = ansb + bured[x];
			break;
		}
		n = n - 1;
		ansb = ansb + 1;
		if (n == sum[x-1]) {
			ansp = ansp + pathi[x - 1];
			ansb = ansb + bured[x - 1];
			break;
		}else if (n > sum[x - 1]) {
			n = n - sum[x - 1] - 1;
			ansp = ansp + 1 + pathi[x - 1];
			ansb = ansb + bured[x - 1];
		}
		x = x - 1;
	}
	cout << ansp;
}