#include<stdio.h>

int main(void)
{
	int X;
	scanf("%d", &X);
	if (X == 5 || X == 7 || X == 3) {
		puts("YES");
	}
	else {
		puts("NO");
	}
	
	return 0;
}