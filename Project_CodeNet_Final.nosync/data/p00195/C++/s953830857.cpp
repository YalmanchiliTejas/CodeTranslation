#include<stdio.h>
int main(void)
{
	int a[5],b[5];
	int i;
	int sum[5];
	int max;
	char banmax,ban[5]={'A','B','C','D','E'};
	
	while(scanf("%d %d",&a[0],&b[0])!=EOF){

		if(a[0] == 0 && b[0] == 0)	break;
		sum[0]=a[0]+b[0];
		max=sum[0];
		banmax='A';

		for(i=1;i<5;i++){
			scanf("%d %d",&a[i],&b[i]);
			sum[i]=a[i]+b[i];
		}
		for(i=0;i<5;i++){
			if(max<sum[i]){
				max=sum[i];
				banmax=ban[i];
			}
		}
		printf("%c %d\n",banmax,max);
	}
	return 0;
}