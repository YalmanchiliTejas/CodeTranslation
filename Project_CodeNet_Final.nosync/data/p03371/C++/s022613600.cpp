#include <bits/stdc++.h>

int main() {
	int a, b, c, x, y;

	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

	a = std::min(a, c * 2);
	b = std::min(b, c * 2);

	if (a + b > c * 2) {
		if (x > y)
			printf("%d", y * 2 * c + (x - y) * a);
		else
			printf("%d", x * 2 * c + (y - x) * b);
	}
	else {
		printf("%d", x * a + y * b);
	}

	return 0;
}