#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,m,n) for (int i = m; i < n; ++i)

const int MAX_K = 1e4+11;
const int MAX_D = 120;
const int MOD = 1e9+7;
string K;
int D;
ll dp[MAX_K][MAX_D];

int main () {
	cin >> K >> D;
    int l = K.size();
	dp[0][0] = 1;
    FOR (i, 1, MAX_K) REP (j, D) REP (k, 10)
	    (dp[i][j] += dp[i-1][(j-k+10*D)%D]) %= MOD;
	
    ll ans = 0;
	ll s = 0;
    REP (i, l) {
		int k = K[i] - '0';
        FOR (j, 1, k+1) {
			int t = (D*D*D-(s+j-1))%D;
			(ans += dp[l-1-i][t]) %= MOD;	
		}	
		(s += k) %= D;
	}
	if (s%D) (ans += MOD - 1) %= MOD;
	cout << ans << endl;
}