#include<stdio.h>
int main(void)
{
	int s1,s2,x,x1,i;
	char w[]={"ABCDE"};
	while(1){
		scanf("%d%d",&s1,&s2);
		if(s1==0&&s2==0) break;
		x=s1+s2; x1=0;
		for(i=1;i<5;i++){
			scanf("%d%d",&s1,&s2);
			if(x<s1+s2){
				x=s1+s2; x1=i;
			}
		}
		printf("%c %d\n",w[x1],x);
	}
	return 0;
}