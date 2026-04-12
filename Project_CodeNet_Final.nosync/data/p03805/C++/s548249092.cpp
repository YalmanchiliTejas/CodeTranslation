#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define maxn 20
#define llg long long 
#define yyj(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);
llg n,m,d[maxn][maxn],ans,a[maxn],bj[maxn];

void init()
{
	llg x,y;
	cin>>n>>m;
	for (llg i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		d[x][y]=d[y][x]=1;
	}
}

void check()
{
	for (llg i=1;i<n;i++)
		if (d[a[i]][a[i+1]]==0)
			return ;
	ans++;
}

void ss(llg x)
{
	if (x>n)
	{
		check();
		return ;
	}
	for (llg i=1;i<=n;i++)
		if (!bj[i])
		{
			bj[i]=1;
			a[x]=i;
			ss(x+1);
			bj[i]=0;
		}
}

int main()
{
	//yyj("C");
	init();
	a[1]=1;
	bj[1]=1;
	ss(2);
	cout<<ans;
	return 0;
}
