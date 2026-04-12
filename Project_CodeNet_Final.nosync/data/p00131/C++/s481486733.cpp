#include<stdio.h>
int t[10][10];
int s[10][10];
int u[10][10];
int main(){
	int a;
	scanf("%d",&a);
	while(a--){
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				scanf("%d",&t[i][j]);
		for(int i=0;i<(1<<10);i++){
			for(int j=0;j<10;j++)
				for(int k=0;k<10;k++){
					s[j][k]=t[j][k];
					u[j][k]=0;
				}
			for(int j=0;j<10;j++)if(i&(1<<j)){
				s[0][j]=(s[0][j]+1)%2;
				if(j<9)s[0][j+1]=(s[0][j+1]+1)%2;
				if(j)s[0][j-1]=(s[0][j-1]+1)%2;
				s[1][j]=(s[1][j]+1)%2;
				u[0][j]=1;
			}
			for(int j=1;j<10;j++){
				for(int k=0;k<10;k++){
					if(s[j-1][k]%2){
						u[j][k]=1;
						s[j][k]=(s[j][k]+1)%2;
						s[j-1][k]=(s[j-1][k]+1)%2;
						if(k)s[j][k-1]=(s[j][k-1]+1)%2;
						if(k<9)s[j][k+1]=(s[j][k+1]+1)%2;
						if(j<9)s[j+1][k]=(s[j+1][k]+1)%2;
					}
				}
			}
			bool ok=true;
			for(int j=0;j<10;j++)if(s[9][j]%2)ok=false;
			if(!ok)continue;
			else{
				for(int j=0;j<10;j++){
					for(int k=0;k<10;k++){
						if(k)printf(" ");
						printf("%d",u[j][k]);
					}
					printf("\n");
				}
				break;
			}
		}
	}
}