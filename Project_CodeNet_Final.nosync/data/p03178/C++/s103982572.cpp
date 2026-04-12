#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e4 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;

int dp[N][102][2];
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	string k;	int d;
	cin >> k >> d;
	dp[0][0][1] = 1;
	for(int i = 0; i < (int)k.length(); i++){
		for(int x = 0; x < 2; x++){
			for(int d1 = 0; d1 < d; d1++){
				if(x == 0){
					for(int j = 0; j < 10; j++)
						dp[i+1][(d1 + j) % d][x] = (dp[i+1][(d1 + j) % d][0] + dp[i][d1][0]) % mod;
				}
				else{
					int v = k[i]-'0';
					for(int j = 0; j < v; j++)
						dp[i+1][(d1 + j) % d][0] = (dp[i+1][(d1 + j) % d][0] + dp[i][d1][1]) % mod;
					dp[i+1][(d1 + v) % d][1] = (dp[i+1][(d1 + v) % d][1] + dp[i][d1][1]) % mod;
				}
			}
		}
	}
	cout << (dp[k.length()][0][0] + dp[k.length()][0][1] - 1 + mod) % mod;
	return 0;
}