#include <stdio.h>
#include <algorithm>
using namespace std;
int x[100], y[100], z[100], a, b, c, d, q;
int main() {
	while (true) {
		scanf("%d,%d", &a, &b);
		if (a == 0 && b == 0) break;
		x[c] = a; y[c] = b; c++;
	}
	for (int i = 0; i < c; i++) {
		for (int j = i + 1; j < c; j++) {
			if (y[i] < y[j]) {
				swap(x[i], x[j]);
				swap(y[i], y[j]);
			}
		}
	}
	z[0] = ++d;
	for (int i = 1; i < c; i++) {
		if (y[i - 1] != y[i]) {
			d++;
		}
		z[i] = d;
	}
	while (~scanf("%d", &q)) {
		for (int i = 0; i < c; i++) {
			if (x[i] == q) {
				printf("%d\n", z[i]);
			}
		}
	}
	return 0;
}