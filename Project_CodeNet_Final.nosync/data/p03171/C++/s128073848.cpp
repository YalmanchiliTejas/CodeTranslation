#pragma GCC optimze("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pp pair<ll,ll>
#define ppp pair<ll,pp >
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(ll i=a;i<b;i+=1)
#define sz(v) (ll)(v.size())
#define hell (ll)1000000007
#define slld(x) scanf("%lld",&x)
ll t=1, tt;
const ll inf=1e18, N=3005;
inline ll mult(ll x,ll y){x%=hell;y%=hell;return (1LL*x*y)%hell;}
inline ll add(ll x,ll y){x+=y;return x%hell;}
inline ll powMod(ll base,ll expo){
	if(base==0)return 0;
	ll ans=1;
	while(expo){
		if(expo&1)ans=mult(ans,base);
		base=mult(base,base); 
		expo>>=1;
	}
	return ans;
}
void solve(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(auto &x : a)
		cin>>x;
	ll dp[n][n];
	rep(i,0,n)
		rep(j,0,n)
			dp[i][j]=-inf;
	rep(len,1,n+1){
		for(ll i=0;i+len-1<n;i++){
			if(len==1)dp[i][i]=a[i];
			else{
				dp[i][i+len-1]=max(dp[i][i+len-1],a[i]-dp[i+1][i+len-1]);
				dp[i][i+len-1]=max(dp[i][i+len-1],a[i+len-1]-dp[i][i+len-2]);
			}
		}
	}
	cout<<dp[0][n-1];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   	//cin>>t;
   	tt=t;
    while(t--){
        solve();
        if(t)cout<<"\n";
    }
    return 0 ;
}
