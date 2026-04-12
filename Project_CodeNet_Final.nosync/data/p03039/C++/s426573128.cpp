#include <bits/stdc++.h>
using namespace std;

int modPow(int x, int n, int mod)
{
	int ret = 1;
	int mul = x;
	while ( n > 0 ) {
		if ( n & 1 ) ret = (int64_t)ret * mul % mod;
		mul = (int64_t)mul * mul % mod;
		n >>= 1;
	}
	return ( ret );
}

int modInv(int x, int mod)
{
	return ( modPow(x, mod - 2, mod) );
}

int modFactrial(int n, int mod)
{
	return ( n <= 1 ? 1 : (int64_t)n * modFactrial(n - 1, mod) % mod );
}

int modChoose(int n, int k, int mod)
{
	return ( (int64_t)modFactrial(n, mod) * modInv((int64_t)modFactrial(k, mod) * modFactrial(n - k, mod) % mod, mod) % mod );
}

int main()
{
	int N, M, K;
	int pat;
	const int mod = 1000000007;

	cin >> N >> M >> K;
	
	pat = modChoose(N * M - 2, K - 2, mod);
	
	int ans = 0;	
	for ( int i = 1; i < M; i++ ) {
		(ans += ((int64_t)i * (M - i) % mod * N % mod * N) % mod) %= mod;
	}
	for ( int i = 1; i < N; i++ ) {
		(ans += ((int64_t)i * (N - i) % mod * M % mod * M) % mod) %= mod;
	}

	cout << (int64_t)ans * pat % mod << endl;

	return ( 0 );
}
