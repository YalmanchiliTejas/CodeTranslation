#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
const int MOD = 998244353;
const int MX = 10000005;
int n;
ll ans = 1, k;
ll exp(ll b, ll n){
	ll res = 1;
	for(; n; n/=2,(b*=b)%=MOD) if(n%2) (res *= b) %= MOD;
	return res;
}
ll fact[MX] = {1}, invf[MX];
void setcomb(int n){
	for(int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MOD;
	invf[n] =  exp(fact[n] ,MOD-2);
	for(int i = n; i > 0; i--) invf[i-1] = (invf[i] * i) % MOD;
}
inline ll comb(int a, int b){return fact[a] * invf[a-b] % MOD * invf[b] % MOD;}
int main(){
	scanf("%d", &n);
	setcomb(n);
	ans = exp(3,n);
	rep(i,n/2) ans -= comb(n,i) * exp(2,i) * 2 % MOD;
	printf("%lld\n", (ans % MOD + MOD) % MOD);
}