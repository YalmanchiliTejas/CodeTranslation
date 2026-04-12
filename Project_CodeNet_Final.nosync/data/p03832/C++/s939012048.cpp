#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

ll N,A,B,C,D;
const ll MAX_N = 1000;
ll dp [MAX_N + 2] [MAX_N + 1];
ll fact [MAX_N + 1],rfact [MAX_N + 1];
const ll MOD = 1e9 + 7;

ll mod_pow(ll x,ll y = MOD - 2)
{
	ll res = 1;
	while(y){
		if(y & 1){
			(res *= x) %= MOD;
		}
		(x *= x) %= MOD;
		y >>= 1;
	}
	return res;
}

int main()
{
	scanf("%lld%lld%lld%lld%lld",&N,&A,&B,&C,&D);

	fact [0] = rfact [0] = 1;
	FOR(i,1,N + 1){
		(fact [i] = fact [i - 1] * i) %= MOD;
		(rfact [i] = rfact [i - 1] * mod_pow(i)) %= MOD;
	}

	dp [A] [0] = 1;
	FOR(i,A,B + 1) FOR(j,0,N + 1){
		(dp [i + 1] [j] += dp [i] [j]) %= MOD;
		ll x = mod_pow(mod_pow(fact [i],C));
		for(ll k = C;k <= D && i * k <= N - j;k++){
			ll t = fact [N - j] * rfact [N - j - i * k] % MOD * x % MOD * rfact [k] % MOD;
			(dp [i + 1] [j + i * k] += dp [i] [j] * t % MOD) %= MOD;
			(x *= mod_pow(fact [i])) %= MOD;
		}
	}

	printf("%lld\n",dp [B + 1] [N]);

	return 0;
}
