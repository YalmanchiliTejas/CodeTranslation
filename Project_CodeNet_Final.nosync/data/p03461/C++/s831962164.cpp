#include<cstdio>
#define reg register
#define MAXN 101
#define MAXI 11
using namespace std;

int dis[MAXI][MAXI];
int f[MAXN][MAXN];
int n,m;

inline int max(int a,int b)
{return(a>b?a:b);}

inline int min(int a,int b)
{return(a<b?a:b);}

int main()
{
	scanf("%d %d",&n,&m);
	for(reg int i=1;i<=n;i++)
		for(reg int j=1;j<=m;j++)
			scanf("%d",&dis[i][j]);
	for(reg int i=0;i<=100;i++)
		for(reg int j=0;j<=100;j++)
			for(reg int px=1;px<=n;px++)
				for(reg int py=1;py<=m;py++)
					f[i][j]=max(f[i][j],dis[px][py]-i*px-j*py);
	for(reg int px=1;px<=n;px++)
		for(reg int py=1;py<=m;py++)
		{
			int tmp=2147483647;
			for(reg int i=0;i<=100;i++)
				for(reg int j=0;j<=100;j++)
					tmp=min(tmp,f[i][j]+i*px+j*py);
			if(tmp!=dis[px][py])
			{
				printf("Impossible");
				return(0);
			}
		}
	puts("Possible\n202 10401");
	for(reg int i=1;i<=100;i++)
		printf("%d %d X\n",i,i+1);
	for(reg int i=102;i<=201;i++)
		printf("%d %d Y\n",i,i+1);
	for(reg int i=0;i<=100;i++)
		for(reg int j=0;j<=100;j++)
			printf("%d %d %d\n",1+i,202-j,f[i][j]);
	printf("1 202");
	return(0);
}