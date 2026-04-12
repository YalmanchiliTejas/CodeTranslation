#include <stdio.h>

#pragma warning (disable:4996)


int main() {
	int X;
	(void)scanf("%d", &X);
	if (X >= 30) printf("Yes"); else printf("No");
}