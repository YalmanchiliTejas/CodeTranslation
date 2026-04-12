#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)

long long pow( long long x, int n )
{
	long long res = 1;
	while( n > 0 ) {
		if( n & 1 ) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	int N, M, K;

	cin >> N >> M >> K;

	vector<long long> fac( N * M - 1, 1 );
	vector<long long> ifac( N * M - 1, 1 );
	for( int i = 2; i < N * M - 1; i++ ) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	for( int i = 1; i < N * M - 1; i++ ) {
		ifac[i] = pow( fac[i], MOD - 2 );
	}
	long long ans = 0;
	for( int dx = 1; dx < M; dx++ ) {
		long long a = (long long)N * N * (M - dx) % MOD;
		ans += a * dx % MOD;
		ans %= MOD;
	}
	for( int dy = 1; dy < N; dy++ ) {
		long long a = (long long)M * M * (N - dy) % MOD;
		ans += a * dy % MOD;
		ans %= MOD;
	}

	ans *= fac[N * M - 2] * ifac[K - 2] % MOD;
	ans %= MOD;
	ans *= ifac[N * M - K];
	ans %= MOD;

	cout << ans << endl;

	return 0;
}
