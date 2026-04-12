#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define MOD 1'000'000'007
#define N 212345

ll pw(ll a, ll b){
	ll c=1, d=a;
	while(b){
		if(b&1) c*=d, c%=MOD;
		d*=d, d%=MOD;
		b/=2;
	}
	return c;
}
inline ll dv(ll a, ll b){
	a%=MOD;
	b%=MOD;
	return a*pw(b, MOD-2)%MOD;
}
ll fct[N]={1};
inline ll cmb(ll a, ll b){
	return dv(dv(fct[a], fct[b]), fct[a-b]);
}
ll clc(ll n, ll m, ll k){
	ll ret = 0;
	FOR(i, 1, m){
		ll tmp = i;
		// tmp*=cmb(m, 2);
		// tmp%=MOD;
		tmp*=m-i;
		tmp%=MOD;

		ret += tmp;
		ret %= MOD;
	}
	ret*=k*(k-1);
	ret%=MOD;
	ret*=n*n;
	ret%=MOD;
	ret*=dv(fct[n*m-2], fct[n*m-k]);
	ret%=MOD;
	return ret;
}

int main(){
	FOR(i, 1, N) fct[i]=fct[i-1]*i%MOD;
	ll n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
	ll ans = clc(n, m, k) + clc(m, n, k);
	ans %= MOD;
	printf("%lld\n", dv(ans, fct[k]));
}
