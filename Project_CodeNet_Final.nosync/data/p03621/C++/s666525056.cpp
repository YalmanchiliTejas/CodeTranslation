#include<stdio.h>
#include<cstring>
using namespace std;

const int _ = 1e4 + 7 , MOD = 998244353;
int pw[_] , fac[_] , ifac[_] , f[_] , g[_] , N , c1 , c2;
char A[_] , B[_];

int poww(int a , int b){
	int tms = 1;
	while(b){
		if(b & 1) tms = 1ll * tms * a % MOD;
		a = 1ll * a * a % MOD; b >>= 1;
	}
	return tms;
}

int binom(int a , int b){return 1ll * fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;}

int main(){
	scanf("%s %s" , A + 1 , B + 1); N = strlen(A + 1);
	for(int i = 1 ; i <= N ; ++i) if(A[i] == '1') ++(B[i] == '1' ? c1 : c2);
	fac[0] = 1; for(int i = 1 ; i <= N ; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[N] = poww(fac[N] , MOD - 2); for(int i = N - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % MOD;
	
	for(int i = 0 ; i <= c2 ; ++i) pw[i] = poww(i , c2);
	for(int i = 0 ; i <= c1 ; ++i){
		int sum = 0;
		for(int j = 0 ; j <= c2 ; ++j) sum = (sum + (j & 1 ? -1ll : 1ll) * binom(c2 , j) * pw[c2 - j] % MOD + MOD) % MOD;
		f[i] = 1ll * sum * fac[c1] % MOD * ifac[c1 - i] % MOD * ifac[i + c2] % MOD;
		for(int j = 0 ; j <= c2 ; ++j) pw[j] = 1ll * pw[j] * j % MOD;
	}

	g[0] = 1;
	for(int i = 1 ; i <= c1 ; ++i)
		for(int j = 1 ; j <= i ; ++j)
			g[i] = (g[i] + 1ll * binom(i - 1 , j - 1) * fac[j - 1] % MOD * g[i - j]) % MOD;
	int ans = 0;
	for(int i = 0 ; i <= c1 ; ++i) ans = (ans + 1ll * f[i] * g[c1 - i]) % MOD;
	printf("%lld\n" , 1ll * ans * fac[c1 + c2] % MOD * fac[c2] % MOD); return 0;
}