#include <cstdio>
#include <cstring>
#define Maxn 300
#define Maxk 10
#define Inf 0x3f3f3f3f
int f[Maxn+5][Maxn+5];
int d[Maxk+5][Maxk+5];
//f[i][j]表示从S到T的路径上有i个x和j个y时其余边的最小可能长度 
//d[x][y]=min{f[i][j]+i*x+j*y}
//f[i][j]=max{d[x][y]-i*x-j*y}
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
struct Edge{
	int u,v,w;
}edge[Maxn*Maxn+5];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&d[i][j]);
		}
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++){
					f[i][j]=mx(f[i][j],d[x][y]-i*x-j*y);
				}
			}
		}
	}
	int now;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			now=Inf;
			for(int i=0;i<=100;i++){
				for(int j=0;j<=100;j++){
					now=mn(now,f[i][j]+i*x+j*y);
				}
			}
			if(now!=d[x][y]){
				puts("Impossible");
				return 0;
			}
		}
	}
	puts("Possible");
	puts("202 10401");
	for(int i=1;i<=100;i++){
		printf("%d %d X\n",i,i+1);
	}
	for(int i=102;i<202;i++){
		printf("%d %d Y\n",i,i+1);
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
		}
	}
	puts("1 202");
	return 0;
}
