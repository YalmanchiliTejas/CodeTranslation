#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define pi 3.1415926535897
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define mod1 998244353
#define inf 1000000000000000000
#define inf1 1000000000
#define endl '\n'
ll val_at_l[200009];
vector<pair<ll,ll>> rem[200009];
ll dp[200009];
ll segtree[800009];
ll lazy[800009];
void push(ll t)
{
	segtree[2*t]+=lazy[t];
	segtree[2*t+1]+=lazy[t];
	lazy[2*t]+=lazy[t];
	lazy[2*t+1]+=lazy[t];
	lazy[t]=0;
	return;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val)
{
	if(l>r)
		return;
	if(tl==l && tr==r)
	{
		segtree[t]+=val;
		lazy[t]+=val;
		return;
	}
	push(t);
	ll tm=(tl+tr)/2;
	update(2*t,tl,tm,l,min(tm,r),val);
	update(2*t+1,tm+1,tr,max(tm+1,l),r,val);
	segtree[t]=max(segtree[2*t],segtree[2*t+1]);
	return;
}
ll get(ll t,ll tl,ll tr,ll l,ll r)
{
	if(l>r)
		return -1*inf;
	if(tl==l && tr==r)
		return segtree[t];
	ll tm=(tl+tr)/2;
	push(t);
	ll a=get(2*t,tl,tm,l,min(tm,r));
	ll b=get(2*t+1,tm+1,tr,max(tm+1,l),r);
	return max(a,b);
}
int main()
{
	fastio;
	#ifdef APNA_IO
		freopen("input.txt" , "rt" ,stdin);
		freopen("output.txt" , "wt" ,stdout);
	#endif
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		val_at_l[a]+=c;
		rem[b].pb(mp(a,c));
	}
	for(ll i=1;i<=n;i++)
	{
		update(1,0,n,0,i-1,val_at_l[i]);
		ll a=get(1,0,n,0,i-1);
		dp[i]=a;
		update(1,0,n,i,i,a);
		for(auto it:rem[i])
			update(1,0,n,0,it.ff-1,-it.ss);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}