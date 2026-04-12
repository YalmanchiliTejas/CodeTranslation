#include <bits/stdc++.h>
#define mid (l+r)/2
#define ll long long
#define ii pair < int , ll >
#define fi first
#define se second


using namespace std;
const int N=2e5+55;
vector < ii > vec[N];
ll tree[N*4];
ll lazy[N*4];
int n,m;

void propa(int l , int r , int node)
{
	if(l!=r)
	{
		lazy[node*2]+=lazy[node];
		lazy[node*2+1]+=lazy[node];
	}
	tree[node]+=lazy[node];
	lazy[node]=0;
}

void update(int l , int r , int node , int x , int y , ll val)
{
	propa(l,r,node);
	if(l>y||r<x)
		return ;
	if(x<=l&&r<=y)
	{
		lazy[node]+=val;
		propa(l,r,node);
		return ;
	}
	update(l,mid,node*2,x,y,val);
	update(mid+1,r,node*2+1,x,y,val);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}

ll query(int l , int r , int node , int x , int y )
{
	propa(l,r,node);
	if(l>y||r<x)
		return 1e9;
	if(x<=l&&r<=y)
		return tree[node];
	propa(l,mid,node*2);
	propa(mid+1,r,node*2+1);
	return min(
			query(l,mid,node*2,x,y),
			query(mid+1,r,node*2+1,x,y));
}

int main()
{
	scanf("%d %d",&n,&m);
	int l,r;
	ll d;
	ll sum=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %lld",&l,&r,&d);
		vec[r].push_back({l,d});
			sum+=d;
	}
	ll best;
	update(0,n,1,1,n,+1e9);
	for(int i=1;i<=n+1;i++)
	{
		best=query(0,n,1,0,n);
		for(auto q:vec[i])
		{
			update(0,n,1,0,q.fi-1,q.se);
		}
		update(0,n,1,i,i,best-1e9);
	}
	printf("%lld\n",sum-best);
	return 0;
}
