#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>

#define rg register
#define il inline
#define MX (3000 + 5)
#define ll long long

ll n ,m;

ll qpow(ll a ,ll b ,ll mod){
	if(b == 0)	return 1;
	if(b == 1)	return a;
	ll t = qpow(a ,b >> 1 ,mod);
	if(b & 1)	return t * t % mod * a % mod;
	return t * t % mod;
}

int C[MX][MX];
ll g[MX][MX] ,f[MX];

int main(){
	scanf("%lld%lld" ,&n ,&m);
	for(rg int i = 0 ; i <= 3000 ; ++i)	C[i][0] = 1;
	for(rg int i = 1 ; i <= 3000 ; ++i)
		for(rg int j = 1 ; j < MX ; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m;
	//g[i][j]表示选中i个topping不合法放在j碗面里的方案 
	for(rg int i = 0 ; i <= n ; ++i)	g[i][0] = 1;
	for(rg int i = 1 ; i <= n ; ++i)
		for(rg int j = 1 ; j <= i ; ++j)
			g[i][j] = (g[i - 1][j] * (j + 1) % m + g[i - 1][j - 1]) % m;
	ll ans = 0;
	for(rg int i = 0 ; i <= n ; ++i){
		ll tmp = qpow(2LL ,qpow(2LL ,n - i ,m - 1) ,m);
		for(rg int j = 0 ; j <= i ;++j){
			f[i] = (f[i] + g[i][j] * qpow(2LL ,(n - i) * j ,m) % m * tmp % m) % m;
		}
		ans += (i & 1 ? -1 : 1) * (ll)C[n][i] * f[i] % m;
		ans = (ans + m) % m;
	}
	
	
	/*
	for(rg int i = n ; ~i ; --i){
		for(rg int j = i + 1 ; j <= n ; ++j){
			f[i] = (f[i] - f[j] * C[n][j] % m + m) % m;
		}
	}
	*/
	printf("%lld" ,ans);
	return 0;
} 