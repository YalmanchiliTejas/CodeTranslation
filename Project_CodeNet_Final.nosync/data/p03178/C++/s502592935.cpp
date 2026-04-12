#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	string n; cin >> n;
	int nsize = n.l_ength();
	int m; cin >> m;
	ll dp[100010][2][100];
	memset( dp, 0ll, sizeof(dp) );
	dp[0][0][0] = 1;
	for( int i = 0; i < nsize; ++i ){
		for( int less = 0; less <= 1; ++less ){
			for( int k = 0; k < m; ++k ){
				int bound = less ? 9 : n[i] - '0';
				for( int d = 0; d <= bound; ++d ){
					dp[i+1][ less || ( d != bound ) ][ (k+d)%m ] += dp[i][less][k];
                 	dp[i+1][ less || ( d != bound ) ][ (k+d)%m ] %= MOD;
				}
			}
		}
	}
	cout << ( dp[nsize][0][0] + dp[nsize][1][0] + MOD - 1 ) % MOD << endl;
	return 0;
}