#include<stdio.h>

int main(void)
{
	int r, g, b;

	scanf("%d", &r);
	scanf("%d", &g);
	scanf("%d", &b);

	if ((g * 10 + b) % 4 == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}

	return(0);
}