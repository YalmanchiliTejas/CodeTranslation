#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=-9e18;
struct node
{
	ll sum,maxn,tag;
};
struct node1
{
	ll l,a;
};
node t[800080];
ll n,m,sum;
vector <node1> q[200020];
void build(ll l1,ll r1,ll p)
{
	t[p].tag=0;
	if(l1==r1)
	{
		t[p].sum=0;
		t[p].maxn=0;
		return ;
	}
	ll mid=(l1+r1)>>1;
	build(l1,mid,p<<1);
	build(mid+1,r1,p<<1|1);
}
void pushdown(ll l1,ll r1,ll p)
{
	ll mid=(r1+l1)>>1;
	t[p<<1].sum+=(mid-l1+1)*t[p].tag;
	t[p<<1].maxn+=t[p].tag;
	t[p<<1].tag+=t[p].tag;
	t[p<<1|1].sum+=(r1-mid)*t[p].tag;
	t[p<<1|1].maxn+=t[p].tag;
	t[p<<1|1].tag+=t[p].tag;
	t[p].tag=0;
}
void plu(ll l1,ll r1,ll p,ll l2,ll r2,ll k)
{
	if(l1>r2 || r1<l2)
		return ;
	if(l1>=l2 && r1<=r2)
	{
		t[p].maxn+=k;
		t[p].sum+=(r1-l1+1)*k;
		t[p].tag+=k;
		return ;
	}
	ll mid=(l1+r1)>>1;
	pushdown(l1,r1,p);
	plu(l1,mid,p<<1,l2,r2,k);
	plu(mid+1,r1,p<<1|1,l2,r2,k);
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
	t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);
}
void insert(ll l1,ll r1,ll p,ll p1,ll k)
{
	if(l1>p1 || r1<p1)
		return ;
	if(l1==r1)
	{
		t[p].sum=t[p].maxn=k;
		return ;
	}
	ll mid=(l1+r1)>>1;
	insert(l1,mid,p<<1,p1,k);
	insert(mid+1,r1,p<<1|1,p1,k);
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
	t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);
}
ll quary(ll l1,ll r1,ll p,ll l2,ll r2)
{
	if(l1>r2 || r1<l2)
		return inf;
	if(l1>=l2 && r1<=r2)
		return t[p].maxn;
	ll mid=(l1+r1)>>1,res;
	pushdown(l1,r1,p);
	res=max(quary(l1,mid,p<<1,l2,r2),quary(mid+1,r1,p<<1|1,l2,r2));
	return res;
}
void search(ll l1,ll r1,ll p,ll l2,ll r2)
{
	if(l1==r1)
	{
		cout<<l1<<' '<<t[p].sum<<endl;
		return ;
	}
	cout<<l1<<' '<<r1<<' '<<t[p].sum<<' '<<t[p].maxn<<' '<<t[p].tag<<endl;
	ll mid=(l1+r1)>>1;
	pushdown(l1,r1,p);
	search(l1,mid,p<<1,l2,r2);
	search(mid+1,r1,p<<1|1,l2,r2);
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		node1 x;
		ll r1;
		cin>>x.l>>r1>>x.a;
		q[r1].push_back(x);
		sum+=x.a;
	}
	build(0,n+1,1);
	for(int i=1;i<=n+1;i++)
	{
		for(int j=0;j<q[i-1].size();j++)
		{
		//	cout<<q[i][j].a<<endl;
			plu(0,n+1,1,0,q[i-1][j].l-1,-q[i-1][j].a);
		}
		insert(0,n+1,1,i,quary(0,n,1,0,i-1));
	//	search(0,n+1,1,0,n+1);
	}
	cout<<sum+quary(0,n+1,1,0,n+1)<<endl;
//	search(0,n+1,1,0,n+1);
	return 0;
}
