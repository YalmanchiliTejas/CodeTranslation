#include<bits/stdc++.h>
using namespace std;
#define nn 65536*4
#define ll long long	 
struct segmenttree{
	ll tree[nn*2+10];ll tag[nn*2+10];
	#define lc id<<1
	#define rc id<<1|1
	void add(ll id,ll y)
	{
		tree[id]+=y;
		tag[id]+=y;
	}
	void down(ll id)
	{
		add(lc,tag[id]);
		add(rc,tag[id]);
		tag[id]=0;
	}
	#define mid (l+r)/2
	void update(ll a,ll b,ll l,ll r,ll id,ll y)
	{
		if(l>=a and r<=b)
		{
			add(id,y);
			return ;
		}
		down(id);
		if(a<=mid) update(a,b,l,mid,lc,y);
		if(b>mid) update(a,b,mid+1,r,rc,y);
		tree[id]=max(tree[lc],tree[rc]); 
	}
	ll query(ll a,ll b,ll l,ll r,ll id)
	{
	//	cout<<l<<" "<<r<<":"<<id<<"\n";
		if(l>=a and r<=b) return tree[id];
		ll sm=-1e16;down(id);
		if(a<=mid) sm=max(sm,query(a,b,l,mid,lc));
		if(b>mid) sm=max(sm,query(a,b,mid+1,r,rc));
		return sm;
	}
	ll query(ll l,ll r)
	{
		return query(l+1,r+1,1,nn,1);
	}
	void update(ll l,ll r,ll y)
	{
		update(l+1,r+1,1,nn,1,y);
	}
}trcyx;
struct farmer{
	ll l,r,sm;
	void in()
	{
		scanf("%lld%lld%lld",&l,&r,&sm);
	}
};
vector<farmer> ad[nn],sb[nn];
ll n,m;
ll f[nn];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++)
	{
		farmer a;a.in();
		ad[a.l].push_back(a);
		sb[a.r+1].push_back(a);
	}
	f[0]=0;
	ll cn=0;//cout<<"ag";
	for(ll i=1;i<=n+1;i++)
	{
		for(ll j=0;j<(ll)ad[i].size();j++)
		{
			farmer bow=ad[i][j];
			trcyx.update(bow.l,bow.r,-bow.sm);
			cn+=bow.sm;
		}
		for(ll j=0;j<(ll)sb[i].size();j++)
		{
			farmer bow=sb[i][j];
			trcyx.update(bow.l,bow.r,bow.sm);
			cn-=bow.sm;
		}//cout<<"k";
		f[i]=trcyx.query(0,i-1)+cn;
		trcyx.update(i,i,f[i]);
	}
	cout<<trcyx.query(0,n);
	return 0;
}