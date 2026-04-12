#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	if (n == 3 || n == 5 || n == 7) {
		puts("YES");
	}
	else {
		puts("NO");
	}
	return 0;
}