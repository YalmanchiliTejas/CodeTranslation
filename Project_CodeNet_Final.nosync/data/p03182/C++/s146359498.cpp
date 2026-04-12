#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,ll>
#define x first
#define y second
#define mp make_pair
#define pb push_back
struct node
{
	int l,r;
	ll v;
}t[800010];
int n,m;
ll f[200010],vl[200010],lazy[800010],ans;
vector<pii> vr[200010];
void pushdown(int k)
{
	if (!lazy[k])
	{
		return;
	}
	t[k<<1].v+=lazy[k];
	t[k<<1|1].v+=lazy[k];
	lazy[k<<1]+=lazy[k];
	lazy[k<<1|1]+=lazy[k];
	lazy[k]=0;
}
void pushup(int k)
{
	t[k].v=max(t[k<<1].v,t[k<<1|1].v);
}
void build(int k,int l,int r)
{
	t[k].l=l;
	t[k].r=r;
	if (l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void update(int k,int x,int y,ll v)
{
	int l=t[k].l;
	int r=t[k].r;
	if (l==x && r==y)
	{
		t[k].v+=v;
		lazy[k]+=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)>>1;
	if (x>mid)
	{
		update(k<<1|1,x,y,v);
	}
	else if (y<=mid)
	{
		update(k<<1,x,y,v);
	}
	else
	{
		update(k<<1,x,mid,v);
		update(k<<1|1,mid+1,y,v);
	}
	pushup(k);
}
ll query(int k,int x)
{
	int l=t[k].l;
	int r=t[k].r;
	if (x>=r)
	{
		return t[k].v;
	}
	pushdown(k);
	int mid=(l+r)>>1;
	if (x<=mid)
	{
		return query(k<<1,x);
	}
	else
	{
		return max(t[k<<1].v,query(k<<1|1,x));
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int l,r;
		ll a;
		scanf("%d%d%lld",&l,&r,&a);
		vl[l]+=a;
		vr[r].pb(mp(l,a));
	}
	build(1,0,n);
	for (int i=1;i<=n;i++)
	{
		update(1,0,i-1,vl[i]);
		//cerr<<vl[i]<<endl;
		f[i]=query(1,i-1);
		//cerr<<"now: "<<t[8].v<<endl;
		ans=max(ans,f[i]);
		update(1,i,i,f[i]);
		for (int j=0;j<vr[i].size();j++)
		{
			update(1,0,vr[i][j].x-1,-vr[i][j].y);
			//cerr<<-vr[i][j].y<<endl;
		}
		//cerr<<i<<" "<<f[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*
6 8
5 6 3
4 5 1
3 5 -1
2 6 3
1 4 5
1 5 -9
5 6 2
5 5 -3
*/
//ÎªÅÂ¶àÇé£¬²»×÷Á¯»¨¾ä¡£
//¡ª¡ªÄÉÀ¼ÈÝÈô¡¶µûÁµ»¨¡·