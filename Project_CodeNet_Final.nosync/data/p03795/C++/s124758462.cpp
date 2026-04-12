#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n, ans, x, y, i;
	scanf("%d", &n);
	x = 800 * n;
	y = 0;
	for (i = 1; i <= n; i++) {
		if (i % 15 == 0) {
			y++;
		}
	}
	y *= 200;
	printf("%d", x - y);
}