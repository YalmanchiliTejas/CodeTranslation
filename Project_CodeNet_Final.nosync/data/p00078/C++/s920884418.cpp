#include<stdio.h>
#include<string.h>

int jin[15][15],n,i,j,x,y;

int main(){
	while(0<=scanf("%d",&n)){
		if(n==0)break;
		memset(jin,0,sizeof(jin));
		for(i=1;i<=n*n;i++){
			if(i==1){
				jin[n/2][n/2+1]=i;
				x=n/2+100*n;
				y=n/2+1+100*n;
				continue;
			}
			++x;
			++y;
			if(jin[(x)%n][(y)%n]==0){
				jin[(x)%n][y%n]=i;
				continue;
			}
			
			j=1;
			while(j){
				--x;
				++y;
				if(jin[x%n][y%n]==0){
					jin[x%n][y%n]=i;
					j=0;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%4d",jin[j][i]);
			}
			printf("\n");
		}
	}
	return 0;
}