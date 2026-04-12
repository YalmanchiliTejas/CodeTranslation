#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff

int A,B;
int D[15][15],F[305][305];

void init(){
	scanf("%d%d",&A,&B);
	for(int i=1;i<=A;i++){
		for(int j=1;j<=B;j++){
			scanf("%d",&D[i][j]);
		}
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int x=1;x<=A;x++){
				for(int y=1;y<=B;y++){
					F[i][j]=max(F[i][j],D[x][y]-i*x-j*y);
				}
			}
		}
	}
	for(int x=1;x<=A;x++){
		for(int y=1;y<=B;y++){
			int f=INF;
			for(int i=0;i<=100;i++){
				for(int j=0;j<=100;j++){
					f=min(f,F[i][j]+i*x+j*y);
				}
			}
			if(f!=D[x][y]){
				printf("Impossible");
				return;
			}
		}
	}
	printf("Possible\n202 10401\n");
	for(int i=1;i<=100;i++){
		printf("%d %d X\n",i,i+1);
	}
	for(int i=102;i<202;i++){
		printf("%d %d Y\n",i,i+1);
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			printf("%d %d %d\n",i+1,202-j,F[i][j]);
		}
	}
	printf("1 202\n");
}

int main(void){
	init();
	return 0;
}