#include<stdio.h>
#include<string.h>
int main(void)
{
	int a,b,d,i,j;
	char c[6]="ABCDE";
	scanf("%d %d",&a,&b);
	while(a!=0 && b!=0){
		j=0; d=a+b;
		for(i=1;i<5;i++){
			scanf("%d %d",&a,&b);
			if(a+b>d){
				d=a+b; j=i;
			}
		}
		printf("%c %d\n",c[j],d);
		scanf("%d %d",&a,&b);
	}
	return 0;
}