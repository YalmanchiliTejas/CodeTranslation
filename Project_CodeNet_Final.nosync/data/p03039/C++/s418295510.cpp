#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

/////////////         modの計算

int mod = 1000000007;

long long mod_adjust(long long a) {//	余りをとる(0～mod-1に調整する)
	if (a > mod) {
		return a % mod;
	}
	if (a < 0) {
		a *= -1;
		a %= mod;
		return mod - a;
	}
	return a;
}
int mod_adjust(int a) {//	余りをとる(0～mod-1に調整する)
	return (int)mod_adjust((long long)a);
}
int mod_add(int a, int b) {//	足し算
	a = mod_adjust(a), b = mod_adjust(b);
	long long k = a % mod; k += b % mod; k %= mod;
	return (int)k;
}
int mod_sub(int a, int b) {//	引き算
	long long k = mod_adjust((long long)a); k += mod_adjust((long long)b); k %= mod;
	return (int)k;
}
int mod_multi(int a, int b) {//	掛け算
	long long k = mod_adjust((long long)a); k *= mod_adjust((long long)b); k %= mod;
	return (int)k;
}
int mod_inv(int a) {//	逆元
	a = mod_adjust(a);
	if (a == 1) { return 1; }
	long long p = mod, q = a, m = 0, n = 1, r, c;

	while (q > 1) {
		r = p % q;
		c = p / q;
		c = mod_adjust(m - n * c);
		p = q, m = n, q = r, n = c;
	}
	return n;
}
int mod_div(int a, int b) {//	割り算
	return mod_multi(a, mod_inv(b));
}
int mod_pow(int x, int n) {//	累乗(logNオーダーなので速い)
	if (n < 0) {
		return mod_pow(mod_div(1, x), -n);
	}
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	if (n % 2 == 0) {
		int k = mod_pow(x, n / 2);
		return mod_multi(k, k);
	}
	else {
		int k = mod_pow(x, n / 2);
		return mod_multi(mod_multi(k, k), x);
	}
}

int* factorial = NULL;			//	階乗
int* factorial_inv = NULL;		//	階乗の逆元

//	階乗を事前に計算しておく関数。
//	Nはmod_combination(n, r)で呼び出されうる最大の数。
void calc_factorial(int N) {////////////////////////// 初めに必ず呼び出すこと！！！
	factorial = new int[N + 1];
	factorial_inv = new int[N + 1];

	factorial[0] = 1;
	factorial_inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		factorial[i] = mod_multi(factorial[i - 1], i);
		factorial_inv[i] = mod_inv(factorial[i]);
	}
}
int mod_combination(int n, int r) {//	nCr	を計算する
	if (n < 0 || r < 0 || r > n) { return 0; }
	return mod_multi(factorial[n], mod_multi(factorial_inv[n - r], factorial_inv[r]));
}

int main() {
	/*
	
	NM_C_K 通りの配置に対して

	K_C_2 通りのマンハッタン距離を計算して

	足し合わせる

	マンハッタン距離の期待値 = (マンハッタン距離の総和の NM_C_2 分 の 1 倍)をK_C_2倍してNM_C_K倍すればいい

	*/
	int N, M, K;
	cin >> N >> M >> K;

	calc_factorial(210000);

	long* a = new long[210000];// 三角数
	a[0] = 0;
	for (long i = 1; i < 210000; i++) {
		a[i] = mod_add(a[i - 1], i);
	}

	long distSum = 0;
	{
		// 横がNマスの場合、i = 0 to N-1
		// i の左側はa[i] * M^2
		for (int i = 0; i < N; i++) {
			distSum = mod_add(distSum, mod_multi(M, mod_multi(a[i], M)));
		}
		for (int i = 0; i < M; i++) {
			distSum = mod_add(distSum, mod_multi(N, mod_multi(a[i], N)));
		}

		distSum = mod_div(distSum, mod_combination(N * M, 2));
	}

	distSum = mod_multi(mod_combination(K, 2), distSum);
	distSum = mod_multi(distSum, mod_combination(N * M, K));

	cout << distSum << endl;

	return 0;
}