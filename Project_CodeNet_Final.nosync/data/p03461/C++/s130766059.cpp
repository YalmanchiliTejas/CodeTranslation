#include <bits/stdc++.h>
#define MAXN 105
#define N 100
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^'0');
        ch=getchar();
    }
    return x*f;
}
int d[MAXN][MAXN],f[MAXN][MAXN];
int main(){
	// freopen("AT3877.out","w",stdout);
	int A=read(),B=read();
	for (register int i=1;i<=A;++i){
		for (register int j=1;j<=B;++j){
			d[i][j]=read();
		}
	}
	for (register int i=0;i<=N;++i){
		for (register int j=0;j<=N;++j){
			//f[i][j]=0;//构造f[i][j]
			for (register int x=1;x<=A;++x){
				for (register int y=1;y<=B;++y){
					f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
				}
			}
			// printf("%d ",f[i][j]);
		}
		// puts("");
	}
	for (register int x=1;x<=A;++x){
		for (register int y=1;y<=B;++y){
			int ans=0x7fffffff;
			for (register int i=0;i<=N;++i){
				for (register int j=0;j<=N;++j){
					ans=min(ans,f[i][j]+i*x+j*y);
				}
			}
			//printf("%d %d\n",ans,d[x][y]);
			if (ans!=d[x][y]) {
				puts("Impossible");
				return 0;
			}
		}
	}
	puts("Possible");;;;
	printf("%d %d\n",N*2+2,N+N+(N+1)*(N+1));
	for (register int i=1;i<=N;++i){
		printf("%d %d X\n",i,i+1);
	}
	for (register int i=N+2;i<(N+1)*2;++i){//反着搞
		printf("%d %d Y\n",i,i+1);
	}
	for (register int i=0;i<=N;++i){
		for (register int j=0;j<=N;++j){
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
		}
	}
	printf("%d %d\n",1,(N+1)*2);
}