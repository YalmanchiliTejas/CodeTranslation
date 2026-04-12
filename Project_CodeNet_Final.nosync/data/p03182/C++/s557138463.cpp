#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define time_taken_start int begtime = clock();
#define time_taken_end int endtime = clock(); \
cerr << "\n\n" << "Time elapsed: " << \
(endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
return 0;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define inf 1000000000000000007
#define eps 0.0000000001
#define pi acosl(-1)
#define pii pair<int,int>
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vii vector<int>
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset <ll>
#define msetd multiset <ll,greater<ll>>
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound 
#define stp fixed<<setprecision(20)
#define endl '\n'
ll seg[1000009];
ll m[1000009];
pll p[200009];
vll lq[200009];
vll rq[200009];
ll update(ll v,ll vl,ll vr,ll l,ll r,ll add)
{
	if(l>r)
		return (seg[v]+m[v]);
	if(vl==l&&vr==r)
		seg[v]+=add;
	else
	{
		ll mid=(vl+vr)/2;
		m[v]=max(update(2*v,vl,mid,l,min(mid,r),add),update((2*v)+1,mid+1,vr,max(l,mid+1),r,add));
	}
	return seg[v]+m[v];
}
ll get(ll v,ll vl,ll vr,ll l,ll r)
{
	if(l>r)
		return -inf;
	if(vl==l&&vr==r)
		return seg[v]+m[v];
	ll mid=(vl+vr)/2;
	return seg[v]+(max(get(2*v,vl,mid,l,min(mid,r)),get((2*v)+1,mid+1,vr,max(l,mid+1),r)));
}
int main()
{
	FAST
	#ifdef ayk_16
	    time_taken_start
		freopen("input.txt","rt",stdin);
		freopen("output.txt","wt",stdout);
	#endif
	ll n,mq;
	cin>>n>>mq;
	ll x,y,z;
	for(ll i=0;i<mq;i++)
	{
		cin>>x>>y>>z;
		lq[x].pb(i);
		rq[y].pb(i);
		p[i].ff=x;
		p[i].ss=z;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		for(auto z:lq[i])
		{
			pll j=p[z];
			update(1,0,n,0,j.ff-1,j.ss);
		}
		x=get(1,0,n,0,i-1);
		ans=max(ans,x);
		update(1,0,n,i,i,x);
		for(auto z:rq[i])
		{
			pll j=p[z];
			update(1,0,n,0,j.ff-1,-j.ss);
		}
	}
	cout<<ans;
}