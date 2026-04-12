#include <stdio.h>

int main(){
	int n,i,max,min,sum,num;

	while(1){
		scanf("%d",&n);
		if(n == 0){
			break;
		}

		max = 0;
		min = 1000;
		sum = 0;

		for(i = 0;i < n;i++){
			scanf("%d",&num);
			sum += num;
			if(max < num){
				max = num;
			}
			if(min > num){
				min = num;
			}
		}

		printf("%d\n",(sum-max-min)/(n-2));
	}

	return 0;
}