#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> // Common file
#include<ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pp pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rep(i,a,b) for( ll i = a ; i < b ; i+=1 )
#define sz(v) (ll)(v.size())
#define hell (ll)1000000007
#define slld(x) scanf("%lld",&x)
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> oset;
#define ld long double
ll t = 1, tt;
inline ll add(ll x,ll y){x+=y;return x%hell;}
inline ll mult(ll x,ll y){x%=hell;y%=hell;return (x*y)%hell;}
inline ll powMod(ll base,ll expo){
	ll ans=1;
	while(expo){
		if(expo&1)ans=mult(ans,base);
		base=mult(base,base);
		expo>>=1;
	}
	return ans;
}
void solve(){
	ll n, maxi, ans=-1e18, mini;
	cin>>n;
	vector<ll> v(n+1);
	rep(i,1,n+1)
		cin>>v[i];
	vector<pp> dp[n+1];
	dp[1].pb({0,0});
	dp[1].pb({v[1],1});
	dp[2].pb({max(v[2],v[1]),1});
	if(n/2==1){
		ans=max(ans,v[1]);
		ans=max(ans,v[2]);
	}
	rep(i,3,n+1){
		maxi=(i+1)/2;
		mini=n/2-(n-i+1)/2;
		mini=max(0LL,mini);
		rep(j,mini,maxi+1)
			dp[i].pb({-1e18,j});
		rep(j,0,sz(dp[i-2])){
			rep(k,0,sz(dp[i])){
				if(dp[i][k].se==dp[i-2][j].se){
					dp[i][k].fi=max(dp[i][k].fi,dp[i-2][j].fi);
				}
				if(dp[i][k].se==dp[i-2][j].se+1){
					dp[i][k].fi=max(dp[i][k].fi,dp[i-2][j].fi+v[i]);
				}
			}
		}
		rep(j,0,sz(dp[i-1])){
			rep(k,0,sz(dp[i])){
				if(dp[i-1][j].se==dp[i][k].se)dp[i][k].fi=max(dp[i][k].fi,dp[i-1][j].fi);
			}
		}
		rep(j,0,sz(dp[i]))
			if(dp[i][j].se==n/2)ans=max(ans,dp[i][j].fi);
	}
	cout<<ans;
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
        if(t!=0)cout<<"\n";
    }
    return 0;
}
