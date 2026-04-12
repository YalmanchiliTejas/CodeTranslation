#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define f first
#define s second
#define cbr cerr<<"hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ll(x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x,y) (lower_bound(all(x),y)-x.begin())
#define ubd(x,y) (upper_bound(all(x),y)-x.begin())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return rng() % (y+1-x) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?llabs(b):gcd(b%a,a); }

using ll=long long; 
using ld=long double;
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
using pi=pair<ll,ll>; using spi=pair<ll,pi>; using dpi=pair<pi,pi>; 

#define LLINF ((long long)1e18)
#define INF int(1e9+1e6)
#define MAXN (10000006)
ll n, f[MAXN], inv[MAXN], p2[MAXN], mod=998244353;
int main(){
	FAST
	cin>>n;
	auto qexp=[&](ll x,ll e){
		ll sum=1;
		for(;e;e>>=1,x*=x,x%=mod)if(e&1)sum*=x,sum%=mod;
		return sum;
	};
	p2[0]=1; FOR(i,1,MAXN-1)p2[i]=p2[i-1]*2%mod;
	f[0]=1; FOR(i,1,MAXN-1)f[i]=f[i-1]*i%mod;
	inv[MAXN-1]=qexp(f[MAXN-1],mod-2);
	DEC(i,MAXN-2,0)inv[i]=inv[i+1]*(i+1)%mod;
	auto C=[&](ll n,ll k){
		return n < k ? 0 : f[n] * inv[k] % mod * inv[n-k] % mod;
	};
	ll ans=qexp(3,n);
	FOR(i,n/2+1,n){
		ans -= 2 * C(n, n-i) % mod * p2[n-i] % mod, ans += mod, ans %= mod;
	}
	cout<<ans<<'\n';
}
