#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int dp[103][103] , h[103] , lsh[103] , N , cl;

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return times;
}

int main(){
	lsh[++cl] = 1; cin >> N;
	for(int i = 1 ; i <= N ; ++i){cin >> h[i]; lsh[++cl] = h[i];}
	sort(lsh + 1 , lsh + cl + 1); cl = unique(lsh + 1 , lsh + cl + 1) - lsh - 1;
	for(int i = 1 ; i <= N ; ++i) h[i] = lower_bound(lsh + 1 , lsh + cl + 1 , h[i]) - lsh;
	for(int i = 1 ; i <= h[1] ; ++i) dp[1][i] = poww(2 , 1 + lsh[h[1]] - lsh[i]);
	for(int i = 1 ; i <= h[1] ; ++i) dp[1][i] = (dp[1][i] - dp[1][i + 1] + MOD) % MOD;
	for(int i = 1 ; i < N ; ++i)
		if(h[i] >= h[i + 1])
			for(int j = 1 ; j <= h[i] ; ++j)
				dp[i + 1][min(h[i + 1] , j)] = (dp[i + 1][min(h[i + 1] , j)] + 1ll * dp[i][j] * (1 + (j >= h[i + 1]))) % MOD;
		else{
			int pw = poww(2 , lsh[h[i + 1]] - lsh[h[i]]);
			for(int j = 1 ; j < h[i] ; ++j)
				dp[i + 1][j] = 1ll * pw * dp[i][j] % MOD;
			for(int j = h[i] ; j <= h[i + 1] ; ++j)
				dp[i + 1][j] = 2ll * dp[i][h[i]] * poww(2 , lsh[h[i + 1]] - lsh[j]) % MOD;
			for(int j = h[i] ; j <= h[i + 1] ; ++j)
				dp[i + 1][j] = (dp[i + 1][j] - dp[i + 1][j + 1] + MOD) % MOD;
		}
	int sum = 0;
	for(int i = 1 ; i <= cl ; ++i) sum = (sum + dp[N][i]) % MOD;
	cout << sum; return 0;
}