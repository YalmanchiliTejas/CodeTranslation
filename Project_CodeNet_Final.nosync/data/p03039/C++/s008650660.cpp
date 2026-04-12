#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
using namespace std;

long long MOD = 1000000007;
long long fac[200001];
long long finv[200001];
long long inv[200001];

int BIT_SIZE = 64;
long long power(long long m, long long n) {
	long long ans = 1;
	long long tmp = m;
	for (int i = 0; i < BIT_SIZE; i++) {
		//cout << ans << endl;
		if (((n >> i) & 1) == 1) {
			ans = ans * tmp % MOD;
		}
		tmp = (tmp * tmp) % MOD;
	}
	return ans;
}


void comb_init() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < 200000; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long comb(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/*
long long combination(long long M, long long N) {
	long long ans = 1;
	for (long long i = 0; i < N; i++) {
		cout << ans << endl;
		ans = (ans * (M - i)) % MOD;
	}
	for (long long i = 0; i < N; i++) {
		cout << ans << endl;
		ans = (ans / (N - i)) % MOD;
	}
	//cout << ans << endl;
	return ans;
}
*/

int main() {
	comb_init();
	int N;
	int M;
	long long K;
	cin >> N >> M >> K;

	long long ans = 0;
	for (long long dist = 1; dist < N; dist++) {
		long long tmp = N - dist;
		tmp = (((tmp * M) % MOD) * M) % MOD;
		ans = (ans + (((tmp * comb(N * M - 2, K - 2)) % MOD) * dist % MOD)) % MOD;
		//cout << tmp << endl;
		//cout << comb(N * M - 2, K - 2) << endl;
	}
	//cout << ans << endl;
	for (long long dist = 1; dist < M; dist++) {
		long long tmp = M - dist;
		tmp = (((tmp * N) % MOD) * N) % MOD;
		ans = (ans + (((tmp * comb(N * M - 2, K - 2)) % MOD) * dist % MOD)) % MOD;
	}
	cout << ans << endl;
	//cout << comb(20, 2) << endl;
	//cout << N * M - 2 << " " << K - 2 << endl;

	return 0;
}