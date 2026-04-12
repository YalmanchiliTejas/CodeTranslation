#include<stdio.h>
#include<string.h>
int main(void)
{
	char m[11];
	int n,i,sum,x,sa[6];
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		sa[0]=1; sa[1]=5; sa[2]=6;
		sa[3]=2; sa[4]=4; sa[5]=3;
		sum=1;
		for(i=0;i<n;i++){
			scanf("%s",m);
			if(strcmp(m,"North")==0){
				x=sa[0]; sa[0]=sa[3]; sa[3]=sa[2];
				sa[2]=sa[1]; sa[1]=x;
			}
			if(strcmp(m,"East")==0){
				x=sa[0]; sa[0]=sa[4]; sa[4]=sa[2];
				sa[2]=sa[5]; sa[5]=x;
			}
			if(strcmp(m,"West")==0){
				x=sa[0]; sa[0]=sa[5]; sa[5]=sa[2];
				sa[2]=sa[4]; sa[4]=x;
			}
			if(strcmp(m,"South")==0){
				x=sa[0]; sa[0]=sa[1]; sa[1]=sa[2];
				sa[2]=sa[3]; sa[3]=x;
			}
			if(strcmp(m,"Right")==0){
				x=sa[3]; sa[3]=sa[5]; sa[5]=sa[1];
				sa[1]=sa[4]; sa[4]=x;
			}
			if(strcmp(m,"Left")==0){
				x=sa[3]; sa[3]=sa[4]; sa[4]=sa[1];
				sa[1]=sa[5]; sa[5]=x;
			}
			sum+=sa[0];
		}
		printf("%d\n",sum);
	}
	return 0;
}