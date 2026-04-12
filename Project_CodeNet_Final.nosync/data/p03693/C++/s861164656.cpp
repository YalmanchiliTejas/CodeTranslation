#include <iostream>

int main() {
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	int number = r * 100 + g * 10 + b;
	if (number % 4 == 0)
		printf("YES");
	else
		printf("NO");
	return 0;
}