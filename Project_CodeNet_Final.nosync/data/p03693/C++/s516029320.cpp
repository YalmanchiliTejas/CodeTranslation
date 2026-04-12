#include <stdio.h>

int main()
{
	int r, g, b, n;

	scanf("%d %d %d", &r, &g, &b);

	n = 0;
	n = 100 * r + 10 * g + b;

	if (n % 4 == 0)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}