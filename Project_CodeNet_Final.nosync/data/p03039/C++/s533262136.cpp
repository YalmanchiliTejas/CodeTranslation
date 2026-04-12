#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

long long modpow(int a, int b){
	if(b == 0){
		return 1;
	}else if(b == 1){
		return a%MOD;
	}else if(b%2 == 0){
		long long x = modpow(a, b>>1);
		return x*x%MOD;
	}else{
		long long x = modpow(a, b>>1);
		return (x*x%MOD)*a%MOD;
	}
}

long long fact[200005];

int main(){
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	
	fact[0] = 1;
	for(int i = 1; i <= N*M; i ++){
		fact[i] = (fact[i-1] * i)%MOD;
	}
	long long mul1 = (fact[N*M-2] * modpow(fact[K-2], MOD-2) % MOD) * modpow(fact[N*M-2 - (K-2)], MOD-2) % MOD;
	//printf("%lld ", mul1);
	
	long long ans = 0;
	for(int d = 1; d < N; d ++){
		long long temp = d*(long long)(N-d);
		temp %= MOD;
		temp = (temp*M)%MOD;
		temp = (temp*M)%MOD;
		ans += temp;
	}
	
	for(int d = 1; d < M; d ++){
		long long temp = d*(long long)(M-d);
		temp %= MOD;
		temp = (temp*N)%MOD;
		temp = (temp*N)%MOD;
		ans += temp;
	}
	ans %= MOD;
	ans *= mul1;
	ans %= MOD;
	
	printf("%lld", ans);
	return 0;
}
