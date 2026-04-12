#include<stdio.h>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define ll long long
#define maxn 105
#define p 1000000007
#define inf 0x3f3f3f3f
using namespace std;
int n,h[maxn],root,tot=1;
int si[maxn],a[maxn];
ll f[maxn][2];// f[maxn][0]è¡¨ç¤ºéžé»‘ç™½ç›¸é—´
vector<int> c[maxn];

inline int read()
{
	int num,sign=1;
	char c;
	while((c=getchar())<'0'||c>'9')
		if(c=='-')sign=-1;
	num=c-'0';
	while((c=getchar())>='0'&&c<='9')
		num=(num<<1)+(num<<3)+c-'0';
	return num*sign;
}

void build(int l,int r,int id)
{
	int minheight=inf,top=0;
	int st[maxn];
	si[id]=r-l+1;
	for(register int i=l;i<=r;++i)
	{
		if(h[i]<=minheight)
		{
			if(h[i]<minheight)
			{
				top=0;
				minheight=h[i];
				st[++top]=i;
			}
			else
				st[++top]=i;
		}
	}
	st[++top]=r+1,a[id]=minheight;
	int lastgo=l;
	for(register int i=1;i<=top;++i)
	{
		if(st[i]==lastgo)
		{
			++lastgo;
			continue;
		}
		++tot;
		c[id].push_back(tot);
		build(lastgo,st[i]-1,tot);
		lastgo=st[i]+1;
	}
}

inline ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=(res*a)%p;
		b>>=1;
		a=(a*a)%p;
	}
	return res;
}

void dfs(int u,int lasth)
{
	int sum=si[u];
	int H=a[u]-lasth;
	f[u][1]=2,f[u][0]=1;
	for(register int i=0;i<c[u].size();++i)
	{
		int v=c[u][i];
		dfs(v,a[u]);
		f[u][0]=(f[u][0]*((f[v][1]+f[v][0])%p)%p+(f[u][0]*f[v][1])%p)%p;
		f[u][1]=(f[v][1]*f[u][1])%p;
		sum-=si[v];
	}
	f[u][0]=((f[u][0]*ksm(2,sum))%p+(p-f[u][1])%p)%p;
	f[u][1]=(f[u][1]*ksm(2,H-1))%p;
}

int main()
{
	n=read();
	for(register int i=1;i<=n;++i)h[i]=read();
	build(1,n,1);
	dfs(1,0);
	printf("%lld\n",(f[1][0]+f[1][1])%p);
	return 0;
}