#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

string s; int d;
int mod = 1e9 + 7;

void solution(){
	cin >> s >> d;
	int n = s.size(); // num of digits
	// state -- depends only on which position we are at, 
	// if we are on the edge of the given number K, and 
	// the sum we are looking for (also can be thought of 
	// as the remainder of the sum modulo d)
	// dp[i][on_edge][sum] -- number of ways to get 'sum' as sum of digits modulo d
	// upto ith digit, with 'on_edge' telling whether we are on edge of K or not
	// this is kind of state DP that is used in the buy and sell stock problems
	// we create transitions based on the states of the previous digit
	// there are two states, namely on_edge and not_on_edge
	// in the first case, upto the ith digit all other remaining digits have
	// been fixed to their respective values in the corresponding number k
	ll dp[n][2][d];
	memset(dp,0LL,sizeof(dp));
	for(int i = 0; i < (s[0]-'0'); i++) dp[0][0][i%d] += 1;
	dp[0][1][(s[0]-'0')%d] += 1;
	for(int i = 1; i < n; i++){
		int lim = s[i]-'0';
		for(int r = 0; r < d; r++){
			for(int cur = 0; cur < 10; cur++){
				int need = (r-cur%d+d)%d;
				assert(need >= 0 && need < d);
				if(cur < lim){
					dp[i][0][r] += dp[i-1][0][need] + dp[i-1][1][need];
				}
				else if(cur == lim){
					dp[i][1][r] += dp[i-1][1][need];
					dp[i][0][r] += dp[i-1][0][need];
				}
				else{
					dp[i][0][r] += dp[i-1][0][need];
				}
				dp[i][0][r] %= mod;
				dp[i][1][r] %= mod;
			}
		}
	}
	cout << (dp[n-1][0][0] + dp[n-1][1][0] - 1 + mod) % mod << endl;


	

	
}   


int main(){ 

	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}
