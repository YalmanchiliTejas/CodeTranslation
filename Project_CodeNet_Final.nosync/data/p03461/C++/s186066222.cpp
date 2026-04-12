#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int n,m;
int d[15][15],f[N][N];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			d[i][j]=read();
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			for(int x=1;x<=n;x++)
				for(int y=1;y<=m;y++)
					f[i][j]=max(f[i][j],d[x][y]-i*x-y*j);
	for(int x=1;x<=n;x++)
		for(int y=1;y<=m;y++)
		{
			int now=100000;
			for(int i=0;i<=100;i++)
				for(int j=0;j<=100;j++)
					now=min(now,f[i][j]+i*x+y*j);
			if(now!=d[x][y]){
				puts("Impossible");
				return 0;
			}
		}
	puts("Possible");
	puts("202 10401");
	for(int i=1;i<101;i++)printf("%d %d X\n",i,i+1);
	for(int i=102;i<202;i++)printf("%d %d Y\n",i,i+1);
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
	puts("1 202");
	return 0;
}