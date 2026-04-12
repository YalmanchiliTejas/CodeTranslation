#include <cstdio>
#include <algorithm>
using namespace std;
const int N=15;
const int M=105; 
const int t=100;
int m,n,d[N][N],f[M][M],p;
int read()
{	char x=getchar();
	while(x<48||x>57) x=getchar();
	int ans=0;
	while(x>=48&&x<=57)
	{	ans=(ans<<1)+(ans<<3)+(x^48);
		x=getchar();
	}
	return ans;
}
int main()
{	m=read();n=read();
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	d[i][j]=read();
	for(int i=0;i<=t;i++)
	for(int j=0;j<=t;j++)
	for(int x=1;x<=m;x++)
	for(int y=1;y<=n;y++)
	f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
	for(int x=1;x<=m;x++)
	for(int y=1;y<=n;y++)
	{	p=0x7ffffff;
		for(int i=0;i<=t;i++)
		for(int j=0;j<=t;j++)
		p=min(p,i*x+j*y+f[i][j]);
		if(p!=d[x][y]) {printf("Impossible\n");return 0;}
	}
	printf("Possible\n");
	printf("202 10401\n");
	for(int i=1;i<=t;i++)
	{	printf("%d %d X\n",i,i+1);
		printf("%d %d Y\n",i+101,i+102);
	}
	for(int i=0;i<=t;i++)
	for(int j=0;j<=t;j++)
	printf("%d %d %d\n",i+1,202-j,f[i][j]);
	printf("1 202\n");
	return 0;
}