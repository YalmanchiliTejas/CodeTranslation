#include<bits/stdc++.h>
using namespace std;

const int N=109;
const int M=19;

int d[M][M],dis[M][M],f[N][N],n=101,a,b;
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}

int main()
{
	if(fopen("vj.in","r"))
	{
		freopen("vj.in","r",stdin);
		freopen("vj.out","w",stdout);
	}
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
		{
			scanf("%d",&d[i][j]);
			dis[i][j]=1e9;
		}

	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=1;k<=a;k++)
				for(int l=1;l<=b;l++)
					chkmax(f[i][j],d[k][l]-k*i-l*j);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=0;k<=n;k++)
				for(int l=0;l<=n;l++)
					chkmin(dis[i][j],f[k][l]+i*k+j*l);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			if(dis[i][j]!=d[i][j])
				return puts("Impossible"),0;
	puts("Possible");
	printf("%d %d\n",n*2,n*n+2*n-2);
	for(int i=1;i<n;i++)
		printf("%d %d X\n",i,i+1);
	for(int i=1;i<n;i++)
		printf("%d %d Y\n",1+n+i,n+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%d %d %d\n",i,j+n,f[i-1][j-1]);
	printf("%d %d\n",1,n+1);
	return 0;
}
