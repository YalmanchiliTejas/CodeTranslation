#include<stdio.h>

int main(void)
{
	int r, g, b,kazu;

	scanf("%d%d%d", &r, &g, &b);

	kazu = r * 100 + g * 10 + b;

	if (kazu % 4 == 0)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}