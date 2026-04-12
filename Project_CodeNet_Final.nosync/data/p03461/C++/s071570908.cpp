#include<cstdio>
#define min(a,b) ((a)<(b)? (a):(b))
#define max(a,b) ((a)>(b)? (a):(b))
int d[15][15],f[305][305];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(register int x=1;x<=n;++x) {
		for(register int y=1;y<=m;++y) {
			scanf("%d",&d[x][y]);
		}	
	}
	for(register int i=0;i<=100;++i) {
		for(register int j=0;j<=100;++j) {
			for(register int x=1;x<=n;++x) {
				for(register int y=1;y<=m;++y) {
					f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
				}
			}
			//if(f[i][j]>0) printf("%d ",f[i][j]);
		}
		//printf("\n");
	}
//	getchar();getchar();
	for(register int x=1;x<=n;++x) {
		for(register int y=1;y<=m;++y) {
			int minn=105;
			for(register int i=0;i<=100;++i) {
				for(register int j=0;j<=100;++j) {
					minn=min(minn,f[i][j]+i*x+j*y);
				}
			}
			if(minn!=d[x][y])  {printf("Impossible\n");return 0;}
		}
	}
	printf("Possible\n");
	printf("202 10401\n");
	for(register int x=1;x<=100;++x) printf("%d %d X\n",x,x+1);
	for(register int x=102;x<=201;++x) printf("%d %d Y\n",x,x+1);
	for(register int i=0;i<=100;++i) {
		for(register int j=0;j<=100;++j) {
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
		}
	}
	printf("1 202\n");
	return 0;
}