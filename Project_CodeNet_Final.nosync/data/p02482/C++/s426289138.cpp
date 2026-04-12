#include <stdio.h>


int main(void)
{
	int number1, number2;
	scanf("%d %d", &number1, &number2);

	if (number1 < number2) {
		printf("a < b", number1, number2);
	} else if (number1 > number2) {
		printf("a > b", number1, number2);
	} else {
		printf("a == b", number1, number2);
	}

	printf("\n");

	return 0;
}