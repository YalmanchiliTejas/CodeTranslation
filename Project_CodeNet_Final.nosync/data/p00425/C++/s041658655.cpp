#include<stdio.h>
#include<string.h>
int main(void)
{
	int n;
	int i,temp;
	char a[10];
	int men[6]={1,3,6,4,2,5};
	int sum;
	
	scanf("%d",&n);
	while(n!=0){
		sum=1;
		for(i=0;i<n;i++){
			scanf("%s",a);
			if(strcmp(a,"North")==0){
				temp=men[0];
				men[0]=men[4];
				men[4]=men[2];
				men[2]=men[5];
				men[5]=temp;
				sum=sum+men[0];
			}
			else if(strcmp(a,"East")==0){
				temp=men[0];
				men[0]=men[3];
				men[3]=men[2];
				men[2]=men[1];
				men[1]=temp;
				sum=sum+men[0];
			}
			else if(strcmp(a,"West")==0){
				temp=men[0];
				men[0]=men[1];
				men[1]=men[2];
				men[2]=men[3];
				men[3]=temp;
				sum=sum+men[0];
			}
			else if(strcmp(a,"South")==0){
				temp=men[0];
				men[0]=men[5];
				men[5]=men[2];
				men[2]=men[4];
				men[4]=temp;
				sum=sum+men[0];
			}
			else if(strcmp(a,"Right")==0){
				temp=men[1];
				men[1]=men[5];
				men[5]=men[3];
				men[3]=men[4];
				men[4]=temp;
				sum=sum+men[0];
			}
			else if(strcmp(a,"Left")==0){
				temp=men[1];
				men[1]=men[4];
				men[4]=men[3];
				men[3]=men[5];
				men[5]=temp;
				sum=sum+men[0];
			}
		}
		men[0]=1;
		men[1]=3;
 		men[2]=6;
		men[3]=4;
		men[4]=2;
		men[5]=5;
		printf("%d\n",sum);
		scanf("%d",&n);
	}
	return 0;
}