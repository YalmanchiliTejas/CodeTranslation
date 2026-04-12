#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7 , MOD = 1e9 + 7;
char str[_]; int N , M;

int main(){
	scanf("%d %d %s" , &N , &M , str + 1);
	if(str[1] == 'B') for(int i = 1 ; i <= M ; ++i) str[i] = 'B' + 'R' - str[i];
	int limit = 1e9 , pre = 1;
	for(int i = 2 ; i <= M ; ++i)
		if(str[i] == 'B'){
			if(!pre) continue;
			if(pre == 1) limit = min(limit , (i - pre) / 2 * 2 + 1);
			if((i - pre) & 1) limit = min(limit , i - pre);
			pre = 0;
		}
		else if(!pre) pre = i;
	int ans = 0;
	if(limit == 1e9){
		static long long dp[_][2][2]; dp[2][0][0] = dp[2][1][0] = dp[2][0][1] = 1;
		for(int i = 3 ; i <= N ; ++i)
			for(int j = 0 ; j < 2 ; ++j){dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD; dp[i][j][1] = dp[i - 1][j][0];}
		ans = (dp[N][0][0] + dp[N][0][1] + dp[N][1][0]) % MOD;
	}
	else if(!(N & 1)){
		static int dp[_]; dp[1] = 1;
		if(limit >= N - 1) ans = N;
		for(int i = 3 ; i <= N ; i += 2){
			int val = (MOD + dp[i - 2] - dp[max(0 , i - limit - 3)]) % MOD;
			if(N - i <= limit) ans = (ans + 1ll * val * (N - i + 1)) % MOD;
			dp[i] = (dp[i - 2] + val) % MOD;
		}
	}
	cout << ans << endl; return 0;
}