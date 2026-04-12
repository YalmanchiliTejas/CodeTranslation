#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 1000005


ll fact[SIZE],inv_fact[SIZE];

ll mod_pow(ll x,ll count, ll mod){

	if(count == 0)return 1;
	ll ret = mod_pow((x*x)%mod,count/2,mod);
	if(count%2 == 1){

		ret = (ret*x)%mod;
	}
	return ret;
}

ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b != 0){
		d = extgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}else{
		x = 1;
		y = 0;
	}
	return d;
}

ll mod_inverse(ll a,ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}

ll nCk(ll n,ll k){

	ll ret = fact[n]*inv_fact[k];
	ret %= MOD;
	ret *= inv_fact[n-k];

	return ret%MOD;
}



int main(){

	fact[0] = 1;
	for(ll i = 1; i < SIZE; i++){
		fact[i] = i*fact[i-1];
		fact[i] %= MOD;
	}
	inv_fact[SIZE-1] = mod_inverse(fact[SIZE-1],MOD);
	for(ll i = SIZE-1; i >= 1; i--){

		inv_fact[i-1] = inv_fact[i]*i;
		inv_fact[i-1] %= MOD;
	}

	ll N,M,K;
	scanf("%lld %lld %lld",&N,&M,&K);

	ll all = N*M;
	ll mult = nCk(all-2,K-2);

	ll ans = 0;

	for(int loop = 0; loop < 2; loop++){
		for(ll diff = 1; diff <= M-1; diff++){

			ll tmp = ((M-diff)%MOD*(N*N)%MOD)%MOD;
			tmp *= diff;
			tmp %= MOD;
			ans += (tmp*mult)%MOD;
			ans %= MOD;
		}
		swap(N,M);
	}

	printf("%lld\n",ans);

	return 0;
}
