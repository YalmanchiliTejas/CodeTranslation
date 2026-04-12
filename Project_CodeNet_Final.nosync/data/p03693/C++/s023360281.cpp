#include <stdio.h>

int main() {
	int r, g, b;

	scanf("%d %d %d", &r, &g, &b);

	printf((r * 100 + g * 10 + b) % 4 == 0 ? "YES\n" : "NO\n");

	return 0;
}