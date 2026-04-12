#include <stdio.h>

int main()
{
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	if((g * 10 + b) % 4 == 0) puts("YES");
	else puts("NO");
	return 0;
}