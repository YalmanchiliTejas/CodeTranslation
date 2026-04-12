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
const ll inf=1e18, N=100005;
vector<ll> adj[N];
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
ll n,d,dp[2][105][10005];
string s;
ll go(ll f,ll cur,ll pos){
	if(pos>=n)return cur%d==0;
	if(dp[f][cur][pos]!=-1)return dp[f][cur][pos];
	dp[f][cur][pos]=0;
	ll newf,maxi,curD;
	if(f)maxi=9;
	else
		maxi=s[pos]-'0';
	//st=0;
	//if(pos==n-1 and f==0)st=1;
	for(curD=0;curD<=maxi;curD++){
		if(f)newf=1;
		else
			newf=(curD<maxi);
		dp[f][cur][pos]=add(dp[f][cur][pos],go(newf,(cur+curD)%d,pos+1));
	}
	return dp[f][cur][pos];
}
void solve(){
	cin>>s>>d;
	n=sz(s);
	memset(dp,-1,sizeof dp);
	ll ans=go(0,0,0);
	ans=add(ans,hell-1);
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
        if(t)cout<<"\n";
    }
    return 0 ;
}
