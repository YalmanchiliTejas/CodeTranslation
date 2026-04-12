#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,cnt,ans;
int w[110][110],v[110][110];
bool flag=1,fl;
int main()
{
	//freopen("ans.txt","w",stdout);
	int i,s,a,b,j,k,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	for(s=1;s<=m;s++)
	{
		scanf("%d",&w[i][s]);
		for(k=0;k<=100;k++)
		for(j=0;j<=100;j++)v[k][j]=max(v[k][j],w[i][s]-i*k-s*j);
	}
	for(i=1;i<=n && flag;i++)
	for(s=1;s<=m && flag;s++)
	{
		c=1e9;
		for(k=0;k<=100;k++)
		for(j=0;j<=100;j++)c=min(v[k][j]+i*k+s*j,c);
		if(c!=w[i][s])flag=0;
	}
	if(!flag){printf("Impossible");return 0;}
	printf("Possible\n202 10401\n");
	for(i=1;i<=100;i++)printf("%d %d X\n",i,i+1),printf("%d %d Y\n",i+101,i+102);
	for(i=0;i<=100;i++)
	for(s=0;s<=100;s++)printf("%d %d %d\n",1+i,102+s,v[i][100-s]);
	printf("1 202");
	return 0;
}