#include<stdio.h>
int main(void)
{
	int a,s,d,f=-1,g,h,j,i;
	scanf("%d %d",&a,&s);
	while(1){
		if(a==0&&s==0){
			break;
		}
		d=a+s;
		//printf("%d\n",d);
		g=1;
		for(i=2;i<=5;i++){
			scanf("%d %d",&a,&s);
			if(d<a+s){
				d=a+s;
				g=i;
			}
		}
		if(g==1)
			printf("A ");
		if(g==2)
			printf("B ");
		if(g==3)
			printf("C ");
		if(g==4)
			printf("D ");
		if(g==5)
			printf("E ");
		printf("%d\n",d);
		scanf("%d %d",&a,&s);
	}

	return 0;
}
	