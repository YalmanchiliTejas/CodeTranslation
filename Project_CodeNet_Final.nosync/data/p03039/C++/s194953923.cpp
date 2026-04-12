#include <iostream>

#define MOD ((int)(1e9 + 7))

using namespace std;

long long  powMod(int a, int x) {
	if (x == 1) return a;
	long long num = powMod(a, x / 2) % MOD;
	if (x % 2 == 0) {
		return (num * num) % MOD;
	}
	else {
		return (((a * num) % MOD) * num) % MOD;
	}
}

long long combinationMod(int n, int r) {
	long long  nume = 1, deno = 1;
	for (int i = 1; i <= n; i++)
	{
		nume = (nume * i) % MOD;
	}
	for (int i = 1; i <= n - r; i++)
	{
		deno = (deno * i) % MOD;
	}
	for (int i = 1; i <= r; i++) {
		deno = (deno * i) % MOD;
	}
	//フェルマーの小定理を利用して剰余ありコンビネーション計算
	return (nume * powMod(deno, MOD - 2)) % MOD;
}



int main() {
	long long N, M, K;

	cin >> N >> M >> K;

	long long lenx = 0, leny = 0;
	//x方向
	for (int i = 1; i < M; i++)
	{
		lenx += i * (M - i) * N * N;
		lenx %= MOD;
	}
	long long comb = combinationMod(N * M - 2, K - 2);
	lenx = (lenx * comb) % MOD;

	//y方向
	for (int i = 1; i < N; i++)
	{
		leny += i * (N - i) * M * M;
		leny %= MOD;
	}
	leny = (leny * comb) % MOD;

	long long ans = (lenx + leny) % MOD;

	cout << ans << endl;

	return 0;
}