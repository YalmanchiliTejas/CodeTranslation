#include <stdio.h>

int main() {
	int x;

	scanf("%d", &x);
	printf(x == 7 || x == 5 || x == 3 ? "YES\n" : "NO\n");
	return 0;
}
