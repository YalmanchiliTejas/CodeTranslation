#include <bits/stdc++.h>

#define MAXN (1010)
#define mod (1000000007) 

int N, A, B, C, D;
int fact[MAXN], rfact[MAXN];
int dp[MAXN][MAXN];

int powmod(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1) ret = (1ll) * ret * a % mod;
		b >>= 1;
		a = (1ll) * a * a % mod;
	}
	return ret;
}

int getA(int a, int b){
	return (1ll) * fact[a] * rfact[a - b] % mod;
}

int main(){
	fact[0] = rfact[0] = 1;
	for(int i = 1; i < MAXN; ++ i){
		fact[i] = (1ll) * fact[i - 1] * i % mod;
		rfact[i] = powmod(fact[i], mod - 2);
	}
	scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);
	
	dp[A - 1][0] = 1;
	for(int i = A; i <= B; ++ i){
		//k = 0
		for(int j = 0; j <= N; ++ j){
			dp[i][j] = dp[i - 1][j];
		}
		
		for(int k = C; k <= D && i * k <= N; ++ k){
			for(int j = i * k; j <= N; ++ j){
				dp[i][j] = (dp[i][j] + 
				(1ll) * dp[i - 1][j - i * k] * getA(j, i * k) % mod *
				rfact[k] % mod * powmod(rfact[i], k) % mod) % mod;
			}
		}
	}
	
	printf("%d\n", dp[B][N]);
	return 0;
}