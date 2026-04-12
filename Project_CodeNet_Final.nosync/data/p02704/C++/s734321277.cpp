#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n,s[510],t[510],l[2][510],h[2][510],now[510][510];
unsigned long long u[510],v[510],a[510][510];
bool ok=1;
inline void init()
{
	memset(l,0,sizeof l); 
	memset(h,0,sizeof h); 
	memset(now,-1,sizeof now);
}
bool solve(int k)
{
	for (int i=1;i<=n;i++)
	if (s[i]==0 && (u[i]&1))
	{
		for (int j=1;j<=n;j++)
		{
			if (now[i][j]!=-1 && now[i][j]!=1) return 0;
			if (now[i][j]==-1)
			{
				now[i][j]=1; h[1][i]++; l[1][j]++;
			}
		}
	}// and==1 all 1
	else if (s[i]==1 && !(u[i]&1))
	{
		for (int j=1;j<=n;j++)
		{
			if (now[i][j]!=-1 && now[i][j]!=0) return 0;
			if (now[i][j]==-1)
			{
				now[i][j]=0; h[0][i]++; l[0][j]++;
			}
		}
	}// or==0 all 0
	for (int j=1;j<=n;j++)
	if (t[j]==0 && (v[j]&1))
	{
		for (int i=1;i<=n;i++)
		{
			if (now[i][j]!=-1 && now[i][j]!=1) return 0;
			if (now[i][j]==-1)
			{
				now[i][j]=1; h[1][i]++; l[1][j]++;
			}
		}
	}// and==1 all 1
	else if (t[j]==1 && !(v[j]&1))
	{
		for (int i=1;i<=n;i++)
		{
			if (now[i][j]!=-1 && now[i][j]!=0) return 0;
			if (now[i][j]==-1)
			{
				now[i][j]=0; h[0][i]++; l[0][j]++;
			}
		}
	}// or==0 all 0
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  if (s[i]==1 && t[j]==1 && (u[i]&1) && (v[j]&1) && now[i][j]==-1)
	  {
	  	now[i][j]=1; h[1][i]++; l[1][j]++;
	  }
	// both or 1 val=1
	//printf("lala %d %d %d %d\n",h[0][1],h[0][2],l[0][1],l[0][2]);  
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  if (now[i][j]==-1)
	  {
	  	now[i][j]=0; h[0][i]++; l[0][j]++;
	  }
	// else goes 0
	 
	for (int i=1;i<=n;i++)
	if (s[i]==1 && (u[i]&1))
	{
		if (h[1][i]) continue;
		bool ff=0;
		for (int j=1;j<=n;j++)
		if (((t[j]==0 && !(v[j]&1) && l[0][j]>1)||(t[j]==1 && (v[j]&1))) && now[i][j]==0)
		{
			ff=1; now[i][j]=1; h[0][i]--; l[0][j]--; h[1][i]++; l[1][j]++;
			break;
		}
		if (!ff) return 0;
	}
	for (int j=1;j<=n;j++)
	if (t[j]==1 && (v[j]&1))
	{
		if (l[1][j]) continue;
		bool ff=0;
		for (int i=1;i<=n;i++)
		if (((s[i]==0 && !(u[i]&1) && h[0][i]>1)||(s[i]==1 && (u[i]&1))) && now[i][j]==0)
		{
			ff=1; now[i][j]=1; h[0][i]--; l[0][j]--; h[1][i]++; l[1][j]++;
			break;
		}
		if (!ff) return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (s[i]==0 && (u[i]&1) && h[1][i]!=n) return 0;
		if (s[i]==0 && !(u[i]&1) && h[0][i]==0) return 0;
		if (s[i]==1 && (u[i]&1) && h[1][i]==0) return 0;
		if (s[i]==1 && !(u[i]&1) && h[0][i]!=n) return 0;
	}
	for (int j=1;j<=n;j++)
	{
		if (t[j]==0 && (v[j]&1) && l[1][j]!=n) return 0;
		if (t[j]==0 && !(v[j]&1) && l[0][j]==0) return 0;
		if (t[j]==1 && (v[j]&1) && l[1][j]==0) return 0;
		if (t[j]==1 && !(v[j]&1) && l[0][j]!=n) return 0;
	}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++) if (now[i][j]==1) a[i][j]+=(1ull<<k);
return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&s[i]);
	for (int i=1;i<=n;i++) scanf("%d",&t[i]);
	for (int i=1;i<=n;i++) scanf("%llu",&u[i]);
	for (int i=1;i<=n;i++) scanf("%llu",&v[i]);
	for (int i=0;i<=63 && ok;i++)
	{
		init(); ok&=solve(i);
		for (int j=1;j<=n;j++) u[j]>>=1,v[j]>>=1;
	}
	if (!ok) {printf("-1\n"); return 0;}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++) printf("%llu%c",a[i][j],(j==n?'\n':' '));
return 0;
}