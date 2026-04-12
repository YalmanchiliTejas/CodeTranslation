#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,x,dp[222222],ddp[222222],tree[888888],lazy[888888];
vector<pair<long long,long long> > v[222222];
void push(long long node,long long x)
{
	tree[node]+=x;
	lazy[node]+=x;
}
void pushdown(long long node)
{
	if (lazy[node])
	{
		push(node<<1,lazy[node]);
		push((node<<1)|1,lazy[node]);
		lazy[node]=0;
	}
}
void pushup(long long node)
{
	tree[node]=max(tree[(node<<1)|1],tree[node<<1]);
}
void update(long long beg,long long en,long long l,long long r,long long node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		push(node,x);
		return;
	}
	pushdown(node);
	long long mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	pushup(node);
}
long long query(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return -1e9;
	if (l>=beg && r<=en) return tree[node];
	pushdown(node);
	long long mid=(l+r)>>1;
	return max(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&l,&r,&x);
		v[r].push_back(make_pair(l,x));
	}
	for (long long i=1;i<=n;i++)
	{
		dp[i]=ddp[i-1];
		for (long long j=0;j<v[i].size();j++)
		{
			long long l=v[i][j].first,val=v[i][j].second;
			dp[i]+=val;
			update(l,i-1,1,n,1,val);
		}
		update(i,i,1,n,1,dp[i]);
		ddp[i]=max(0ll,query(1,i,1,n,1));
	}
	printf("%lld\n",ddp[n]);
	return 0;
} 