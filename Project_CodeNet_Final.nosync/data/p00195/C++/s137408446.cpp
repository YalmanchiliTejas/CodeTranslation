#include<stdio.h>

int main(){
	int mise[5],i,j,s1,s2;
	while(~scanf("%d%d",&s1,&s2)){
		if(s1==0 && s2==0)break;
		mise[0]=s1+s2;
		j=0;
		for(i=0;i<4;i++){
			scanf("%d%d",&s1,&s2);
			if(s1+s2>mise[i]){
				mise[i+1]=s1+s2;
				j=i+1;
				continue;
			}
			mise[i+1]=mise[i];
		}
		printf("%c %d\n",'A'+j,mise[j]);
	}
	return 0;
}