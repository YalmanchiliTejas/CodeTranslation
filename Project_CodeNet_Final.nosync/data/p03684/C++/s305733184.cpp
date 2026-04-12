#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll n,m,ans,cnt,fa[100001],k1,k2;

struct node{
	ll x,y,id;
}a[100001];

bool operator < (node u,node v)
{
	return u.x<v.x;
}

bool cmp(node u,node v)
{
	return u.y<v.y;
}

struct node1{
	ll x,y,val;
}c[800001];

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f; 
}

int find(int u)
{
	return fa[u]==u ? u:fa[u]=find(fa[u]);
}

void add(int u,int vv,int val)
{
	c[++cnt]=(node1){u,vv,val};
}

bool operator < (node1 u,node1 v)
{
	return u.val<v.val;
}

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) add(a[i].id,a[i+1].id,a[i+1].x-a[i].x);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++) add(a[i].id,a[i+1].id,a[i+1].y-a[i].y);
	sort(c+1,c+cnt+1);
	for(int i=1;i<=cnt;i++)
	  if((k1=find(c[i].x))!=(k2=find(c[i].y)))
	  {
	  	fa[k1]=k2;ans+=c[i].val;
	  }
	printf("%lld\n",ans);
	return 0;
}