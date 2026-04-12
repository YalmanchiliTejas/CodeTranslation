#include<iostream>
#include<cstdio>
using namespace std;

#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
const int M=305;

int n,m,f[M][M],d[M][M];

int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=read();
		}
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++){
					f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
				}
			}
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			int now=1e9+7;
			for(int i=0;i<=100;i++){
				for(int j=0;j<=100;j++){
					now=min(now,f[i][j]+i*x+j*y);
				}
			}
			if(now!=d[x][y]){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n202 10401\n");
	for(int i=1;i<=100;i++) printf("%d %d X\n",i,i+1);
	for(int i=102;i<=201;i++) printf("%d %d Y\n",i,i+1);
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
		}
	}
	printf("1 202\n");
}