#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define M 505
#define MAXN 149
#define INF 1000000000
using namespace std;
int n,m,f[M][M],g[M][M],S,T;
int read(){
	char c=getchar();int ans=0;
    while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans;
}
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
int main(){
	n=read(),m=read();
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++) f[i][j]=read();
	for (register int i=0;i<=MAXN;i++)
		for (register int j=0;j<=MAXN;j++)
			for (register int k=1;k<=n;k++)
				for (register int l=1;l<=m;l++)
					g[i][j]=max(g[i][j],f[k][l]-k*i-l*j);
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++){
			int now=INF;
			for (register int k=0;k<=MAXN;k++)
				for (register int l=0;l<=MAXN;l++)
					now=min(now,k*i+l*j+g[k][l]);
			if (now!=f[i][j]){printf("Impossible");return 0;}
		}
	for (register int i=0;i<=MAXN;i++)
		for (register int j=0;j<=MAXN;j++)
			if (g[i][j]>100){printf("Impossible");return 0;}
	printf("Possible\n%d %d\n",MAXN+MAXN+2,(MAXN+1)*(MAXN+1)+2*MAXN);
	S=1,T=MAXN+MAXN+2;
	for (register int i=1;i<=MAXN;i++) printf("%d %d X\n",i,i+1);
	for (register int i=MAXN+2;i<=MAXN+MAXN+1;i++) printf("%d %d Y\n",i,i+1);
	for (register int i=0;i<=MAXN;i++)
		for (register int j=0;j<=MAXN;j++)
			printf("%d %d %d\n",i+1,T-j,g[i][j]);
	printf("%d %d\n",S,T);
	return 0;
}
