#include<stdio.h>
#include<stdlib.h>

int max(int x, int y) {
	return x >= y ? x : y;
}

int min(int x, int y) {
	return x <= y ? x : y;
}

int main() {
	int a, b, c, x, y, ans, anst;
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	int ma = max(x, y), temp1 = ma * 2 * c, xy = abs(x - y), fees = a * x + b * y;
	ans = min(fees, temp1);
	if (x > y) anst = y * 2 * c + xy * a;
	else anst = x * 2 * c + xy * b;
	ans = min(ans, anst);
	return 0 * printf("%d\n", ans);
}