#include<stdio.h>
int main(void)
{
	int s1[6],s2[6],s3[6],s4[6],i,j,x;
	char a[6]={'A','B','C','D','E'};
	while(1){
		scanf("%d %d",&s1[0],&s2[0]);
		if(s1[0]==0&&s2[0]==0) break;
		else s3[0]=s1[0]+s2[0];
		for(i=1;i<5;i++){
			scanf("%d %d",&s1[i],&s2[i]);
			s3[i]=s1[i]+s2[i];
		}
		for(i=0;i<5;i++) s4[i]=s3[i];
		for(i=0;i<4;i++){
			for(j=i+1;j<5;j++){
				if(s3[i]<s3[j]){
					x=s3[i];
					s3[i]=s3[j];
					s3[j]=x;
				}
			}
		}
		for(i=0;i<5;i++){
			if(s3[0]==s4[i]){
				printf("%c %d\n",a[i],s3[0]);
				break;
			}
		}
	}	
	return 0;
}