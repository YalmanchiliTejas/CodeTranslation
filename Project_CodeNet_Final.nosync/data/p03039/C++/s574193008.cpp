#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 2e5 + 10, MOD = 1e9 + 7;
int N, M, K;
int F[MAX_N];
int Fdiv[MAX_N];

int _sum (int a, int b) {
	int c = a + b;
	if (MOD <= c)
		c -= MOD;

	return c;
}

int _sub (int a, int b) {
	int c = a - b;
	if (c < 0)
		c += MOD;

	return c;
}

int _mul (int a, int b) {
	int c = 1LL * a * b % MOD;
	return c;
}

int _pow (int a, int b) {
	if (!b)
		return 1;

	int res = _pow(a, b >> 1);
	res = _mul(res, res);

	if (b & 1)
		res = _mul(res, a);

	return res;
}

int _choose (int a, int b) {
	if (b < a || min(a, b) < 0)
		return 0;

	return _mul(F[b], _mul(Fdiv[a], Fdiv[b - a]));
}

void preProcess() {
	F[0] = 1;
	for (int i = 1; i < MAX_N; i++)
		F[i] = _mul(i, F[i - 1]);

	Fdiv[0] = 1;
	Fdiv[1] = 1;
	for (int i = 2; i < MAX_N; i++)
		Fdiv[i] = _mul(_sub(0, MOD / i), Fdiv[MOD % i]);

	for (int i = 1; i < MAX_N; i++)
		Fdiv[i] = _mul(Fdiv[i - 1], Fdiv[i]);
}

int main() {
	preProcess();
	cin >> N >> M >> K;
	int A = 0, B = 0;
	for (int i = 1; i <= N; i++)
		A = _sum(A, _mul(i, N - i));

	for (int i = 1; i <= M; i++)
		B = _sum(B, _mul(i, M - i));

	int ans = _sum(_mul(A, _mul(_mul(M, M), _choose(K - 2, N * M - 2))), 
				   _mul(B, _mul(_mul(N, N), _choose(K - 2, N * M - 2))));	

	cout << ans << "\n";
	return 0;
}