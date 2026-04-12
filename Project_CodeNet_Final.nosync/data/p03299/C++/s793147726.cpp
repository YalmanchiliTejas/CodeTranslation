#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ll(x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x,y) (lower_bound(all(x),y)-x.begin())
#define ubd(x,y) (upper_bound(all(x),y)-x.begin())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?llabs(b):gcd(b%a,a); }

typedef long long ll; 
typedef long double ld;
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
typedef pair<ll,ll>pi; typedef pair<ll,pi>spi; typedef pair<pi,pi>dpi;

#define LLINF ((long long)1e18)
#define INF int(1e9+1e6)
#define MAXN (206)
ll n,A[MAXN],dp[MAXN][MAXN],mod=1e9+7,ans=1,no[MAXN];
vector<ll> d;
vector<pi> range;
int main(){
	FAST
	cin>>n;
	FOR(i,1,n)cin>>A[i];
	auto qexp=[&](ll x,ll e){
		ll sum = 1;
		while(e){
			if(e&1) sum*=x, sum%=mod;
			x*=x,x%=mod;
			e>>=1;
		}
		return sum;
	};
	auto calc2=[&](ll x){
		return qexp(2,x+1) - 1;
	};
	auto calc=[&](ll x,ll y){
		return (calc2(y) + mod - calc2(x-1))%mod;
	};
	FOR(i,1,n){
		if(A[i]==1) A[i]=0, ans *= 2, ans %= mod;
	}
	FOR(i,1,n)if(A[i]>A[i-1]&&A[i]>A[i+1]){
		ans*=qexp(2,A[i]-max(A[i-1],A[i+1])),ans%=mod;
		A[i]=max(A[i-1],A[i+1]);
	}
	FOR(i,1,n)if(A[i]) d.eb(A[i]),d.eb(A[i]+1);
	d.eb(ll(1e9) + 1);
	d.eb(1);
	d.eb(2);
	sort(all(d)), d.resize(unique(all(d))-d.begin());
	assert(d[0]==1);
	FOR(i,1,siz(d)-1) range.eb(d[i-1]+1,d[i]);
	FOR(j,0,siz(range)-1)if(range[j].s<=A[1]){
		dp[1][j] = calc(A[1]-range[j].s, A[1]-range[j].f) * 2 % mod;
	}
	no[1]=A[1]>0 ? 2 : 1;
	FOR(i,2,n){
		FOR(j,0,siz(range)-1)if(range[j].s<=A[i]){
			dp[i][j] += dp[i-1][j] * qexp(2, max(0ll, A[i]-A[i-1])) % mod, dp[i][j] %= mod;
			if(range[j].f > A[i-1]) dp[i][j] += no[i-1] * 2 % mod * calc(A[i]-range[j].s, A[i]-range[j].f) % mod, dp[i][j] %= mod;
		}
		FOR(k,0,siz(range)-1)if(range[k].f>A[i]){
			no[i] += dp[i-1][k] * (A[i] > 0 ? 2 : 1) % mod, no[i] %= mod;
		}
		no[i] += no[i-1] * (A[i]>0 ? 2 : 1) % mod, no[i] %= mod;
	}
	ll sum = 0;
	FOR(j,0,siz(range)-1) sum += dp[n][j], sum%=mod;
	sum += no[n], sum %= mod;
	sum *= ans, sum %= mod;
	cout<<sum<<'\n';
}
