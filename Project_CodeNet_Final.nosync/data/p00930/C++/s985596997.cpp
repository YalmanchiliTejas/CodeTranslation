#include <cstdio>

#include <cmath>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <queue>

#include <vector>

#include <map>



using namespace std;



typedef long long LL;


char s[300005];
int a[300005],sum[300005];
struct Node
{
	int x1,x2,bj;
}tree[3000005];
int n,m,ans,x;
void build(int x,int l,int r)
{
	tree[x].bj=0;tree[x].x1=19950920;tree[x].x2=19950920;
	if (l==r)
	{
		if (a[l]==-1) tree[x].x1=l;
		else tree[x].x1=19950920;
		tree[x].x2=sum[l];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	tree[x].x2=min(tree[x*2].x2,tree[x*2+1].x2);
	tree[x].x1=min(tree[x*2].x1,tree[x*2+1].x1);
}

void change(int x,int l,int r,int ll,int rr,int w)
{
	if (l==ll&&rr==r)
	{
		tree[x].x2+=w;
		tree[x].bj+=w;
		return;
	}
	int mid=(l+r)/2;
	if (tree[x].bj!=0)
	{
		tree[x*2].x2+=tree[x].bj;tree[x*2].bj+=tree[x].bj;
		tree[x*2+1].x2+=tree[x].bj;tree[x*2+1].bj+=tree[x].bj;
		tree[x].bj=0;
	}
	if (rr<=mid) change(x*2,l,mid,ll,rr,w);
	else if (ll>=mid+1) change(x*2+1,mid+1,r,ll,rr,w);
	else 
	{
		change(x*2,l,mid,ll,mid,w);
		change(x*2+1,mid+1,r,mid+1,rr,w);
	}
	tree[x].x2=min(tree[x*2].x2,tree[x*2+1].x2);
	tree[x].x1=min(tree[x*2].x1,tree[x*2+1].x1);
}
int query(int x,int l,int r)
{
	if (l==r) return l;
	int mid=(l+r)/2;
	if (tree[x].bj!=0)
	{
		tree[x*2].x2+=tree[x].bj;tree[x*2].bj+=tree[x].bj;
		tree[x*2+1].x2+=tree[x].bj;tree[x*2+1].bj+=tree[x].bj;
		tree[x].bj=0;
	}
	if (tree[x*2+1].x2<2) return query(x*2+1,mid+1,r);
	else return query(x*2,l,mid);
}
void change2(int x,int l,int r,int pos)
{
	if (l==r)
	{
		if (a[l]==-1) tree[x].x1=l;
		else tree[x].x1=19950920;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid) change2(x*2,l,mid,pos);
	else change2(x*2+1,mid+1,r,pos);
	tree[x].x1=min(tree[x*2].x1,tree[x*2+1].x1);
}

int main()

{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;++i) 
	{
		if (s[i]=='(') a[i]=1;
		else a[i]=-1;
	}
	sum[0]=0;
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	build(1,1,n);
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		if (a[x]==1)
		{
			change(1,1,n,x,n,-2);
			a[x]=-a[x];
			change2(1,1,n,x);
			ans=tree[1].x1;
			change(1,1,n,ans,n,+2);
			a[ans]=-a[ans];
			change2(1,1,n,ans);
		}
		else
		{
			change(1,1,n,x,n,+2);
			a[x]=-a[x];
			change2(1,1,n,x);
			ans=query(1,1,n)+1;
			change(1,1,n,ans,n,-2);
			a[ans]=-a[ans];
			change2(1,1,n,ans);
		}
		printf("%d\n",ans);
		//for (int j=1;j<=n;++j) if (a[j]==1) cout<<"(";
		//else cout<<")";
		//cout<<endl;
	}

	return 0;

}