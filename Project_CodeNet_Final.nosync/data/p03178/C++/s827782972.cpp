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
		for( int kleiner = 0; kleiner <= 1; ++kleiner ){	
			for( int r = 0; r < d; ++r ){
				int bound = kleiner ? 9 : k[i] - '0'; 
				for( int m = 0; m <= bound; ++m ){
					( dp[i+1][(r+m)%d][ kleiner || m < bound ] += dp[i][r][kleiner] ) %= mod;
				}
			}
		}
	}
	cout << ( dp[n][0][0] + dp[n][0][1] + (mod-1) ) % mod << endl;
}