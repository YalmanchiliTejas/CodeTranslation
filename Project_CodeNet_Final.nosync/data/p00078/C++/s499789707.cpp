#include<stdio.h>
int main(void)
{
	int map[16][16];
	int suu;
	int i,j;
	int n;
	
	scanf("%d",&n);
	while(n!=0){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				map[i][j]=0;
			}
		}
		i=n/2+1;
		j=n/2;
		map[i][j]=1;
		suu=2;
		while(suu<=n*n){
			i++;
			j++;
			if(i>=n){
				i=0;
			}
			if(j>=n){
				j=0;
			}
			if(map[i][j]!=0){
				i++;
				j--;
				if(j<0){
					j=n-1;
				}
				if(i>=n){
					i=0;
				}
			}
			map[i][j]=suu;
			suu++;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%4d",map[i][j]);
			}
			printf("\n");
		}
		scanf("%d",&n);
	}
	return 0;
}

			