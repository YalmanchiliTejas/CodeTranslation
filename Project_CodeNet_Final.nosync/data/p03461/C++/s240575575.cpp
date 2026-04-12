#include<cstdio>
namespace QiFeng233{
	const int maxn=310,matsiz=20,inf=0x3f3f3f3f;
	int A,B,d[matsiz][matsiz],f[maxn][maxn];
	int max(int a,int b){
		return a>b?a:b;		
	}
	int min(int a,int b){
		return a<b?a:b;
	}
	void solve(){
		scanf("%d%d",&A,&B);
		for(int i=1;i<=A;++i)
			for(int j=1;j<=B;++j)
				scanf("%d",&d[i][j]);
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				for(int x=1;x<=A;++x)
					for(int y=1;y<=B;++y)
						f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
		for(int x=1;x<=A;++x)
			for(int y=1;y<=B;++y){
				int dxy=inf;
				for(int i=0;i<=100;++i)
					for(int j=0;j<=100;++j)
						dxy=min(dxy,i*x+j*y+f[i][j]);
				if(dxy!=d[x][y]){
					printf("Impossible\n");
					return;
				}
			}
		printf("Possible\n");
		printf("202 10401\n");
		for(int i=1;i<=100;++i)printf("%d %d X\n",i,i+1);
		for(int i=102;i<=201;++i)printf("%d %d Y\n",i,i+1);
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				printf("%d %d %d\n",1+i,202-j,f[i][j]);
		printf("1 202\n");
	}
}
signed main(){
	QiFeng233::solve();
	return 0;
} 