#include <cstdio>
#include <algorithm>
int n, q, x[100009], y[100009], a[100009], p[100009]; bool ok[100009];
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &x[i], &y[i]); x[i]--, y[i]--; a[i + 1] = a[i];
		if (a[i] == x[i]) a[i + 1] = y[i];
		if (a[i] == y[i]) a[i + 1] = x[i];
	}
	ok[a[q]] = true;
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = q; i >= 0; i--) {
		if (i != q) std::swap(p[x[i]], p[y[i]]);
		if (a[i] != 0) ok[p[a[i] - 1]] = true;
		if (a[i] != n - 1) ok[p[a[i] + 1]] = true;
	}
	int ret = 0;
	for (int i = 0; i < n; i++) ret += ok[i];
	printf("%d\n", ret);
	return 0;
}