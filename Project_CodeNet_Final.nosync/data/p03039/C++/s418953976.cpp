#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 400000;


ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	// 前処理
	COMinit();

	ll N, M, K;

	cin >> N >> M >> K;

	ll A = COM(N*M - 2, K - 2);

	ll X = 0;
	for (ll i = 1; i <= N - 1; i++) { X += i * (N - i); X %= MOD; }

	ll B = X *M % MOD *M %MOD;

	X = 0;
	for (ll i = 1; i <= M - 1; i++) { X += i * (M - i); X %= MOD; }

	ll C = X *N % MOD *N %MOD;

	cout << A * (B + C) % MOD;

	system("PAUSE");

}