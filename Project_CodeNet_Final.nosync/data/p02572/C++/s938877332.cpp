#include "bits/stdc++.h"
using namespace std;

constexpr long long MOD = 1000000007;

int main() {
	int N;
	cin >> N;
	long long COUNT1 = 0, COUNT2 = 0;
	for (int i = 0; i < N; i++) {
		long long A;
		cin >> A;
		COUNT1 += A;
		COUNT1 %= MOD;
		COUNT2 += (A * A) % MOD;
		COUNT2 %= MOD;
	}
	long long ANS = (COUNT1 * COUNT1 - COUNT2 + MOD) % MOD;
	if (ANS % 2 == 0) cout << ANS / 2 << endl;
	else cout << (ANS + MOD) / 2 << endl;
}