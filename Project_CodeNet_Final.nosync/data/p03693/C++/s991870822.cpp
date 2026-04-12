#include<stdio.h>
int main(void) {

	int a = 0;
	int r, g, b;

	scanf("%d %d %d", &r, &g, &b);

	a = 100 * r + 10 * g + b;

	if (a % 4 == 0)printf("YES\n");
	else printf("NO\n");

	return 0;
}