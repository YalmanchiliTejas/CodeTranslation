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
const ll N=200005, inf=1e18;
vector<pair<ll,ll> > ending[N];
ll tr[4*N], lazy[4*N], dp[N];
ll combine(ll x,ll y){return min(x,y);}
void lazify(ll node,ll l,ll r){
	if(lazy[node]){
		tr[node]+=lazy[node];
		if(l!=r){
			lazy[node<<1]+=lazy[node];
			lazy[node<<1|1]+=lazy[node];
		}
	}
	lazy[node]=0;
}
void update(ll node,ll l,ll r,ll a,ll b,ll val){
	lazify(node,l,r);
	if(b<l || r<a || l>r)return;
	if(a<=l and r<=b){
		tr[node]+=val;
		if(l!=r){
			lazy[node<<1]+=val;
			lazy[node<<1|1]+=val;
		}
		return;
	}
	ll mid=(l+r)/2;
	update(node<<1,l,mid,a,b,val);
	update(node<<1|1,mid+1,r,a,b,val);
	tr[node]=combine(tr[node<<1],tr[node<<1|1]);
}
void assign(ll node,ll l,ll r,ll id,ll val){
	lazify(node,l,r);
	if(l==r){
		tr[node]=val;
		return;
	}
	ll mid=(l+r)/2;
	if(l<=id and id<=mid)
		assign(node<<1,l,mid,id,val);
	else
		assign(node<<1|1,mid+1,r,id,val);
	tr[node]=combine(tr[node<<1],tr[node<<1|1]);
}
ll query(ll node,ll l,ll r,ll a,ll b){
	lazify(node,l,r);
	if(l>b || a>r || l>r)return inf;
	if(a<=l and r<=b)return tr[node];
	ll mid=(l+r)/2;
	return combine(query(node<<1,l,mid,a,b),query(node<<1|1,mid+1,r,a,b));
}
void solve(){
	ll n, m, tot=0, x, y, ans;
	cin>>n>>m;
	rep(i,0,m){
		cin>>x>>y>>ans;
		tot+=ans;
		ending[y+1].pb({x+1,ans});
	}
	rep(i,1,N-1)assign(1,1,N-1,i,0);
	ans=inf;
	rep(i,2,n+3){
		dp[i]=query(1,1,N-1,1,i-1);
		for(auto u : ending[i]){
			update(1,1,N-1,1,u.fi-1,u.se);
		}
		assign(1,1,N-1,i,dp[i]);
		ans=min(ans,dp[i]);
	}
	cout<<tot-ans<<endl;
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
    return 0;
}
