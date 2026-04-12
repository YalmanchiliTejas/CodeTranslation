#include<bits/stdc++.h>
#define re register int
using namespace std;
int n,m,d[15][15],f[110][110];
int main(){
	scanf("%d%d",&n,&m);
	for(re i=1;i<=n;i++)
	for(re j=1;j<=m;j++)scanf("%d",&d[i][j]);
	for(re i=0;i<=100;i++){
		for(re j=0;j<=100;j++){
			for(re k=1;k<=n;k++){
				for(re l=1;l<=m;l++){
					f[i][j]=max(f[i][j],d[k][l]-i*k-j*l);
				}
			}
		}
	}
	for(re i=1;i<=n;i++){
		for(re j=1;j<=m;j++){
			int now=0x3f3f3f;
			for(re k=0;k<=100;k++){
				for(re l=0;l<=100;l++){
					now=min(now,f[k][l]+i*k+j*l);
				}
			}
			if(now!=d[i][j]){
				printf("Impossible");
				return 0;
			}
		}
	}
	printf("Possible\n202 10401\n");
	for(int i=1;i<=100;i++)printf("%d %d X\n",i,i+1);
	for(int i=102;i<202;i++)printf("%d %d Y\n",i,i+1);
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
		}
	}
	printf("1 202");
	return 0;
}