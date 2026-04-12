#include "bits/stdc++.h"
#define long int64_t
using namespace std;

struct Solver {
	static const long mod = 1000000007;

	void solve() {
		int N;
		cin >> N;
		vector<int> A( N );
		for( int i = 0; i < N; ++i ) { cin >> A[i]; }
		vector<long> B( N+1 );
		for( int i = 1; i <= N; ++i ) {
			B[i] = B[i-1] + A[i-1];
		}
		long ans = 0;
		for( int i = 0; i < N; ++i ) {
			ans += (B[N] - B[i+1]) % mod * A[i];
			ans %= mod;
		}
		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
