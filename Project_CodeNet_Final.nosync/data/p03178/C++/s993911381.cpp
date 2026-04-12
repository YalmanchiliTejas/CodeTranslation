#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using ld = long double;
using namespace std;

int dp[10010][100][2];

int main(){
	string k; cin >> k;
	int n = k.l_ength();
	int d; cin >> d;
	dp[0][0][0] = 1;
	for( int i = 0; i < n; ++i ){
		for( int r = 0; r < d; ++r ){
			for( int m = 0; m <= 9; ++m ){
				dp[i+1][(r+m)%d][1] += dp[i][r][1];
				dp[i+1][(r+m)%d][1] %= mod;
			}
		}
		for( int r = 0; r < d; ++r ){
			for( int m = 0; m <= k[i]-'0'; ++m ){
				dp[i+1][(r+m)%d][(int)(m<k[i]-'0')] += dp[i][r][0];
				dp[i+1][(r+m)%d][(int)(m<k[i]-'0')] %= mod;
			}
		}
	}
	cout << ( dp[n][0][0] + dp[n][0][1] + (mod-1) ) % mod << endl;
}