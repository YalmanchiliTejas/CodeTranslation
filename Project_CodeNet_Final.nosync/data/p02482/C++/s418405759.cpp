#include <stdio.h>

int main(void) {
	int a,b;
	scanf("%d%d", &a, &b);
	printf(a == b ? "a == b\n" : a > b ? "a > b\n" : "a < b\n");
	return 0;
}