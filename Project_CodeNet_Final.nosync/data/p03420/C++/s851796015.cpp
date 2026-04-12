#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long int

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;

	int ans = 0;
	if (K == 0) {
		cout << N * N << endl;
		return 0;
	}
	REP(b, K + 1, N) {
		int l = b - K;
		ans += l * (N / b);
		int tmp = max(0LL, N - (N / b) * b - K + 1);
		ans += tmp;
		// cout << ans << " " << l * (N / b) << " " << tmp << endl;
	}
	cout << ans << endl;

    return 0;
}
