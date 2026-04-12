#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 10000005;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
	if(p % 2 == 1)return a * modpow(a, p - 1) % MOD;
	
	long long r = modpow(a, p / 2);
	return r * r % MOD;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}

int N;
long long fact[MAXN], invfact[MAXN];

long long C(int n, int r){
	return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main(){	
	scanf("%d", &N);
	
	for(int i = 0; i <= N; i++){
		if(i == 0)fact[i] = 1;
		else fact[i] = i * fact[i - 1] % MOD;
	}
	
	for(int i = N; i >= 0; i--){
		if(i == N)invfact[i] = modinv(fact[i]);
		else invfact[i] = (i + 1) * invfact[i + 1] % MOD;
	}
	
	long long res = 0, cur = 1;
	for(int c = 0; c <= N; c++){
		res = (res + cur * C(N, c)) % MOD;
		
		if(c < N){
			cur = cur * 2 % MOD;
			if(c >= N / 2)cur = (cur - 2 * C(c, N / 2) + 2LL * MOD) % MOD;
		}
	}
	
	printf("%lld\n", res);
	
	return 0;
}
