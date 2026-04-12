#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll inv[225816],fac[225816];

ll rwpw(ll a, ll p){
	ll ret = 1ll;
	while(p){
		if(p%2){
			mul_mod(ret,a);
		}
		mul_mod(a,a);
		p /= 2;
	}
	return ret;
}

ll c(ll n, ll k){
	ll ret = 1ll;
	if(n<k){
		return 0ll;
	}
	ret = fac[n];
	mul_mod(ret,(inv[k]*inv[n-k])%MOD);
	return ret;
}

int main(void){
	ll i,n,m,k,f,x=0ll,tmp,ans=0ll;
	cin >> n >> m >> k;
	f = n*m;
	fac[0] = 1ll;
	inv[0] = 1ll;
	for(i=1; i<=n*m; ++i){
		fac[i] = fac[i-1];
		mul_mod(fac[i],i);
		inv[i] = inv[i-1];
		mul_mod(inv[i],rwpw(i,MOD-2));
	}
	for(i=1; i<n; ++i){
		tmp = (n-i);
		mul_mod(tmp,i);
		mul_mod(tmp,(m*m)%MOD);
		mul_mod(tmp,c(n*m-2,k-2));
		add_mod(ans,tmp);
	}
	for(i=1; i<m; ++i){
		tmp = (m-i);
		mul_mod(tmp,i);
		mul_mod(tmp,(n*n)%MOD);
		mul_mod(tmp,c(n*m-2,k-2));
		add_mod(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}
