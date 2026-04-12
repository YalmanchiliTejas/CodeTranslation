#include<stdio.h>

int main(void)
{
	int n[5],m[5];
	int i;
	int sum[5];
	int max;
	char bannmax,bann[5] = {'A','B','C','D','E'};
	
	while (scanf("%d %d",&n[0],&m[0])!=EOF){
	
		if(n[0] == 0 && m[0] == 0) break;

		sum[0]=n[0]+m[0];
		max=sum[0];
		bannmax='A';

		for (i=1;i<5;i++){
			scanf("%d %d",&n[i],&m[i]);
			sum[i]=n[i]+m[i];
		}

		for(i=0;i<5;i++){
			if(max < sum[i]){
			max=sum[i];
			bannmax=bann[i];
		}
	}

	printf("%c %d\n",bannmax,max);
	}
	
	return 0;
}