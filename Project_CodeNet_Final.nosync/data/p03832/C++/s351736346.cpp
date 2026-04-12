#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const ll mod = 1e9+7;
ll N,A,B,C,D;
ll dp[1060][1060];
ll cdp[1060][1060];
ll fact[1050];
ll fpow(ll a, ll b){
	ll res = 1, t = a;
	while( b ){
		if( b&1 ) res = (res*t)%mod;
		t = (t*t)%mod;
		b >>= 1;
	}
	return res;
}
ll inv(ll a){
	return fpow(a,mod-2);
}

ll comb(ll n, ll m){
	if( n == m || m == 0 ) return 1;
	ll& res = cdp[n][m];
	if( res != -1 ) return res;
	res = (comb(n-1,m) + comb(n-1,m-1))%mod;
	return res;
}


int main(){
	fact[0] = 1;
	for(ll i=1;i<=1000;i++) fact[i] = (fact[i-1]*i)%mod;
	memset(cdp,-1,sizeof cdp);
	scanf("%lld%lld%lld%lld%lld",&N,&A,&B,&C,&D);
	for(int i=0;i<=N;i++) dp[0][i] = 1;

	for(int n=1;n<=N;n++){
		for(int x=A;x<=B;x++){
			dp[n][x] = dp[n][x-1];
			ll cur = n;
			ll tmp = comb(n,x);
			cur -= x;
			for(int y=1;y<=D;y++){
				if( cur < 0 ) break;
				if( y >= C && y <= D ){
					dp[n][x] = (dp[n][x] + ((tmp*inv(fact[y]))%mod)*dp[cur][x-1])%mod;
				}
				tmp = (tmp * comb(cur,x))%mod;
				cur -= x;
			}
		}
	}

	printf("%lld\n",dp[N][B]);
}
