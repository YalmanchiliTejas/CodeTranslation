#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= MOD;
	if(k%2 == 1){
		ret *= x; ret %= MOD;
	}
	return ret;
}
ll f(ll n){
	ll ret = 1;
	for(int i = 1 ; i <= n ; i ++){
		ret *= i;
		ret %= MOD;
	}
	return ret;
}

int main(){
	ll n,m,k;
	cin >> n >> m >> k;
	ll a,b,c;
	a = (n-1)*n*(n+1)/6; a %= MOD; a *= m; a %= MOD; a *= m; a %= MOD;
	b = (m-1)*m*(m+1)/6; b %= MOD; b *= n; b %= MOD; b *= n; b %= MOD;
	c = f(n*m-2);
	c *= modpow(f(k-2),MOD-2); c %= MOD;
	c *= modpow(f(n*m-k),MOD-2); c %= MOD;
	cout <<((a+b)*c)%MOD << endl;
}