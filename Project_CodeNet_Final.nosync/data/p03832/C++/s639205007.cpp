#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
const int MD = 1e9+7;
const int MX = 1005;
int n, a, b, c, d;
ll dp[MX] = {1}, fact[MX] = {1}, invf[MX];;

ll exp(ll b, ll n){
	ll res = 1;
	for(; n; n/=2,(b*=b)%=MD) if(n%2) (res *= b) %= MD;
	return res;
}
void setcomb(int n){
	for(int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MD;
	invf[n] =  exp(fact[n],MD-2);
	for(int i = n; i > 0; i--) invf[i-1] = (invf[i] * i) % MD;
}

int main(){
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	setcomb(n);
	for(int i = a; i <= b; i++) for(int j = n; j >= 0; j--){
		for(int k = c; k*i <= j && k <= d; k++) (dp[j] += dp[j-k*i] * fact[n-j+k*i] % MD * invf[n-j] % MD * exp(invf[i],k) % MD * invf[k]) %= MD;
	}
	printf("%lld\n", dp[n]);
}