#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define ll int
#define pp pair<ll,ll>
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rep(i,a,b) for( ll i = a ; i < b ; i+=1 )
#define sz(v) (ll)(v.size())
#define hell (ll)998244353
#define slld(x) scanf("%lld",&x)
ll t = 1;
const ll inf=hell, N=3005;
ll dp[3005][3005];
inline ll mult(ll x,ll y){return (1LL*x*y)%hell;}
inline ll add(ll x,ll y){x+=y;return x%hell;}
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
	ll n, s, res=0;
	cin>>n>>s;
	memset(dp,0,sizeof dp);
	vector<ll> v(n+1,0);
	rep(i,1,n+1){
		cin>>v[i];
		dp[i][v[i]]=i;
	}
	rep(i,1,n+1){
		rep(j,0,s+1)
			if(j>=v[i])
				dp[i][j]=add(dp[i][j],dp[i-1][j-v[i]]);
		res=add(res,mult(n-i+1,dp[i][s]));
		rep(j,0,s+1)
			dp[i][j]=add(dp[i][j],dp[i-1][j]);
	}
	cout<<res<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //cin >> t ;
    while(t--){
        solve();
    }
    return 0 ;
}
