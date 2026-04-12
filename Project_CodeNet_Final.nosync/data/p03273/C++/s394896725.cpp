#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define maxn 150

bool bh[maxn],bw[maxn];
char s[maxn][maxn];
int main()
{
	int n,m,i,t,j;
	scanf("%d%d",&n,&m);
	memset(bh,false,sizeof(bh));
	memset(bw,false,sizeof(bh));
	for (i=1;i<=n;i++)
	 scanf("%s",s[i]+1);
	t=(n>m)?n:m;
	while (t--)
	{
		for (i=1;i<=n;i++) if (!bh[i])
		{
			bool bk=false;
			for (j=1;j<=m;j++)
			 if (!bw[j] && s[i][j]!='.') {bk=true;break;}
			if (!bk) bh[i]=true;
		}
		for (i=1;i<=m;i++) if(!bw[i])
		{
			bool bk=false;
			for (j=1;j<=n;j++)
			 if (!bh[j] && s[j][i]!='.') {bk=true;break;}
			if (!bk) bw[i]=true;
		}
	}
	for (i=1;i<=n;i++) if (!bh[i])
	{
		for (j=1;j<=m;j++) if (!bw[j])
		 printf("%c",s[i][j]);
		printf("\n");
	}
	return 0;
}
//.white #black
