 #include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long  long> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	const long long MOD = 1000000000 + 7;
	vector<long  long> acc( N + 1 );
	for( int i = 0; i < N; i++ ) {
		acc[i + 1] = acc[i] + A[i];
		acc[i + 1] %= MOD;
	}
	long long ans = 0;
	for( int i = 0; i < N; i++ ) {
		ans += A[i] * ((acc[N] - acc[i + 1] + MOD) % MOD) % MOD;
		ans %= MOD;
	}

	cout << ans << endl;
}
