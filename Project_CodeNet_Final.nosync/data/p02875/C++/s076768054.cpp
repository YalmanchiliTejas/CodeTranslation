#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
const int MOD = 998244353;
const int MX = 10000005;
int n;
ll ans = 1, f = 1, iv[MX];
ll exp(ll b, ll n){
	ll res = 1;
	for(; n; n/=2,(b*=b)%=MOD) if(n%2) (res *= b) %= MOD;
	return res;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) f = f*i % MOD;
	iv[n] =  exp(f,MOD-2);
	for(int i = n; i > 0; i--) iv[i-1] = (iv[i] * i) % MOD;
	ans = exp(3,n);
	rep(i,n/2){
		f = f*2 % MOD;
		(ans -= f * iv[n-i] % MOD * iv[i]) %= MOD;
	}
	if(ans < 0) ans += MOD;
	printf("%lld\n", ans);
}