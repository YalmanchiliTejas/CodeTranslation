#include<bits/stdc++.h>
using namespace std;

const int N=800005;
int n,m;
int v[N],nxt[N],head[N];
long long s[N],w[N],tag[N];

void pushdown(int x,int l,int r)
{
	int mid=(l+r)>>1;
	s[x<<1]+=tag[x],s[x<<1|1]+=tag[x];
	tag[x<<1]+=tag[x],tag[x<<1|1]+=tag[x];
	tag[x]=0;
}

void modify(int x,int l,int r,int L,int R,long long val)
{
	if(l>=L&&R>=r)
	{
		s[x]+=val,tag[x]+=val;
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)>>1;
	if(L<=mid) modify(x<<1,l,mid,L,R,val);
	if(R>mid) modify(x<<1|1,mid+1,r,L,R,val);
	s[x]=max(s[x<<1],s[x<<1|1]);
}

long long query(int x,int l,int r,int L,int R)
{
	if(l>=L&&R>=r) return s[x];
	pushdown(x,l,r);
	int mid=(l+r)>>1;
	long long res=-0x3f3f3f3f3f3f3f3f;
	if(L<=mid) res=max(res,query(x<<1,l,mid,L,R));
	if(R>mid) res=max(res,query(x<<1|1,mid+1,r,L,R));
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&y,&x,&z);
		v[i]=y,w[i]=z;
		nxt[i]=head[x],head[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		modify(1,1,n,i,i,query(1,1,n,1,i));
		for(int j=head[i];j>0;j=nxt[j])
		{
			modify(1,1,n,v[j],i,w[j]);
		}
	}
//	cout<<query(1,1,n,1,n)<<endl;
	printf("%lld\n",max(s[1],0ll));
}