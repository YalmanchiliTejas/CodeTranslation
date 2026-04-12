#include<stdio.h>
int main(void)
{
	int a,b,max,i,x;
	char s[10]="ABCDE";
	while(1){
		scanf("%d%d",&a,&b);
		if(a==0&&b==0) break;
		max=a+b; x=0;
		for(i=1;i<5;i++){
			scanf("%d%d",&a,&b);
			if(max<a+b){
				max=a+b;
				x=i;
			}
		}
		printf("%c %d\n",s[x],max);
	}
	return 0;
}