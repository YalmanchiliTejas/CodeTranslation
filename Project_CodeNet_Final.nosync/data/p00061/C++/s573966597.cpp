#include<stdio.h>
#include<string.h>

int main(){
	int ti[300][3],i,j,k,a,b;
	i=0;
	
	while(0<=scanf("%d,%d",&ti[i][0],&ti[i][1])){
		if(ti[i][0]==0 && ti[i][1]==0)break;
		++i;
	}
	
	for(j=0;j<i;j++){
		for(k=j;k<i;k++){
			if(ti[k][1]>ti[j][1]){
				for(a=0;a<2;a++){
					b=ti[k][a];
					ti[k][a]=ti[j][a];
					ti[j][a]=b;
				}
			}
		}
	}
	j=1;
	ti[0][2]=1;
	for(k=1;k<i;k++){
		if(ti[k-1][1]>ti[k][1])++j;
		ti[k][2]=j;
	}
	
	while(0<=scanf("%d",&i)){
		for(j=0;;j++){
			if(ti[j][0]==i)break;
		}
		printf("%d\n",ti[j][2]);
	}
	return 0;
}