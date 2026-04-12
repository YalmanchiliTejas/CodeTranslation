#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



ll W,H;
ll inv_6;

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

ll gcd(ll x,ll y){

	x = abs(x);
	y = abs(y);

	if(x < y){
		swap(x,y);
	}
	if(y == 0){
		return x;
	}else{
		return gcd(y,x%y);
	}
}

ll mod_pow(ll x,ll count, ll mod){

	if(count == 0)return 1;
	ll ret = mod_pow((x*x)%mod,count/2,mod);
	if(count%2 == 1){

		ret = (ret*x)%mod;
	}
	return ret;
}


ll numC3(ll num){

	if(num <= 2)return 0;

	ll ret = num;

	ret *= num-1;
	ret %= MOD;
	ret *= num-2;
	ret %= MOD;
	ret *= inv_6;
	ret %= MOD;

	return ret;
}

//https://betrue12.hateblo.jp/entry/2020/05/02/163444

int main(){

	inv_6 = mod_inverse(6,MOD);

	scanf("%lld %lld",&W,&H);

	ll N = (W+1)*(H+1);
	ll mult = mod_pow(2,N-3,MOD);

	ll base = numC3(N);

	ll minus = 0;

	for(ll i = 0; i <= H; i++){
		for(ll k = 0; k <= W; k++){
			if(i ==0 && k == 0)continue;

			ll tmp = (H+1-i)*(W+1-k);
			tmp %= MOD;

			if(i > 0 && k > 0){
				tmp *= 2;
				tmp %= MOD;
			}

			tmp *= gcd(i,k)-1;
			tmp %= MOD;

			minus += tmp;
			minus %= MOD;
		}
	}

	base -= minus;
	if(base < 0){

		base += MOD;
	}

	ll ans = base*mult;
	ans %= MOD;

	printf("%lld\n",ans);

	return 0;
}

