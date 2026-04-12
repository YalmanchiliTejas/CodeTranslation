#include <algorithm>
#include <stdio.h>
using ll = long long;

int main() {
	int R, G, B, x;
	scanf("%d %d %d", &R, &G, &B);
	x = R * 100 + G * 10 + B;
	printf("%s\n", (x % 4 ? "NO" : "YES"));
}