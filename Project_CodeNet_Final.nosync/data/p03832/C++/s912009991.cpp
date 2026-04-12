#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000+7;
long long A,B,C,D;
long long dp[1100][1100];

long long ncr[1100][1100];

long long bpow(long long a,long long b,const long long mod){
	return (b?bpow(a*a%mod,b/2,mod)*(b&1?a:1):1)%mod;
}

long long invv[1111];

long long dfs(int g,int r){
	if( g == 0 ) return r == 0;
	if( dp[g][r] != -1 ) return dp[g][r];
	long long ans = dfs(g-1,r);
	
	
	if( A <= g and g <= B ){
		long long sub = 1;
		for(int i = 1 ; i <= D ; i++){
			if( i * g > r ) break;
			
			sub = sub * ncr[r-(i-1)*g][g];
			sub %= mod;
			sub *= invv[i];
			sub %= mod;
			if( i >= C ){
				ans += dfs(g-1,r-i*g) * sub;
				ans %= mod;
			}
		}
	}
	//cout << g << " " << r << ": " << ans << endl;
	return dp[g][r] = ans;	
}
void solve(long long N){
	memset(dp,-1,sizeof(dp));
	cout << dfs(N,N) << endl;
}

int main(){
	for(int i = 0 ; i < 1010 ; i++)
		invv[i] = bpow(i,mod-2,mod);
	ncr[0][0] = 1;
	for(int i = 0 ; i < 1050 ; i++){
		for(int j = 0 ; j < 1050 ; j++){
			ncr[i][j] %= mod;
			ncr[i+1][j] += ncr[i][j];
			ncr[i+1][j+1] += ncr[i][j];
			
		}
	}
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&A);
	scanf("%lld",&B);
	scanf("%lld",&C);
	scanf("%lld",&D);
	solve(N);
	return 0;
}
