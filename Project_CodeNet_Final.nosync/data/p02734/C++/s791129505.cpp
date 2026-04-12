#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(998244353)
#define INF (2e9)
#define EPS (1e-6)
#ifdef LOCAL_TEST
#define debug(...) do{\
	cerr<<__PRETTY_FUNCTION__<<" - "<<__LINE__<<\
	" : ("#__VA_ARGS__<<") = ";\
	_OUT(__VA_ARGS__);\
}while(0)
template<typename T>void _OUT(T x){cerr<<x<<endl;}
template<typename T,typename...I>void _OUT(T x,I ...tail){cerr<<x<<", ";_OUT(tail...);}
#else
#define debug(...)
#endif
void INIT(){
#ifdef LOCAL_TEST
	freopen("D:\\input.in","r",stdin);
	freopen("D:\\output.out","w",stdout);
	freopen("D:\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll fpow(ll b,ll p){
	b%=MOD;
	ll ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int dp[3050];

int32_t main() {
	INIT();
	//code...
	ll n,s; cin>>n>>s;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	ll ans=0;
	for(ll i=n;i>=1;i--){
		ll t; cin>>t;
		if(t<=s) ans=(ans+i*dp[s-t])%MOD;
		for(ll j=s-1;j>t;j--){
			if(j-t>=0) dp[j]=(dp[j]+dp[j-t])%MOD;
		}
		if(t<s) dp[t]=(dp[t]+n-i+1)%MOD;
		dp[0]++;
		//For(j,0,s) cerr<<dp[j]<<" \n"[j==s];
		//cerr<<t<<" "<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
