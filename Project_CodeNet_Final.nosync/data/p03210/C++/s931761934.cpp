#include <stdio.h>

int main(void) {
	int year;
	scanf("%d",&year);
	if (year == 3 || year == 5 || year == 7){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}