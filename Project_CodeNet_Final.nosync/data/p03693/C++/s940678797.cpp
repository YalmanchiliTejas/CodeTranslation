#include <stdio.h>

int main(){
	int r,g,b,num;

	scanf("%d", &r);
	scanf("%d", &g);
	scanf("%d", &b);

	num = r * 100 + g * 10 + b;

	if(num % 4 == 0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;

}