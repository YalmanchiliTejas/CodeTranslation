#include <stdio.h>

int main (){
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	
	if (num1 == num2){
		printf("Yes \n", num1);
	}
	else {
		printf("No \n", num1);
	}

	return 0;
}