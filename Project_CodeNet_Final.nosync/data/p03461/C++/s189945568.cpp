#include<bits/stdc++.h>
using namespace std;
const int N=233;
int m,n,a[N][N],b[N][N]; bool vis[N][N];
int main(){
	scanf("%d%d",&m,&n);
	int i,j,x,y;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++) scanf("%d",&a[i][j]);
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			for (x=0; x<=100; x++)
				for (y=0; y<=100; y++) b[x][y]=max(b[x][y],a[i][j]-i*x-j*y);
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			for (x=0; x<=100; x++)
				for (y=0; y<=100; y++)
					if (b[x][y]==a[i][j]-i*x-j*y) vis[i][j]=1;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++) if (!vis[i][j]){
			puts("Impossible"); return 0;
		}
	puts("Possible");
	printf("202 %d\n",200+101*101);
	for (i=1; i<=100; i++) printf("%d %d X\n",i,i+1);
	for (i=102; i<=201; i++) printf("%d %d Y\n",i+1,i);
	for (i=0; i<=100; i++)
		for (j=0; j<=100; j++) printf("%d %d %d\n",i+1,j+102,b[i][j]);
	puts("1 102");
	return 0;
}