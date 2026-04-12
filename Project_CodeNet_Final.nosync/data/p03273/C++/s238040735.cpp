#include<stdio.h>
int main(){
	int i,j,n,a,b,x[105][105]={0},flag=0,y[105][105]={0};
	char c[105][105];
	scanf("%d%d",&a,&b);
	for(i=0;i<a;i++){
		scanf("%s",&c[i]);	
	}
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(c[i][j]=='#'){
				flag=1;
				break;
			}
		}
		if(flag==0){
			for(j=0;j<b;j++){
				x[i][j]=1;
			}
		}
		flag=0;
	}
	for(j=0;j<b;j++){
		for(i=0;i<a;i++){
			if(c[i][j]=='#'){
				flag=1;
				break;
			}
		}
		if(flag==0){
			for(i=0;i<a;i++){
				y[i][j]=1;
			}
		}
		flag=0;
	}
	int ok=0;
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(x[i][j]!=1&&y[i][j]!=1){
				printf("%c",c[i][j]);
				ok=1;
			}
		}
		if(ok==1){
			printf("\n");
		}
		ok=0;
	}
	return 0;
} 