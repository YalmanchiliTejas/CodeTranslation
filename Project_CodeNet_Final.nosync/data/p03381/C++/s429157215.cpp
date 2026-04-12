#include<cstdio>
#include<algorithm>
int a[200000], b[200000];
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	std::sort(b, b + n);
	for (i = 0; i < n; i++) {
		if (a[i] <= b[n / 2 - 1]) printf("%d\n", b[n / 2]);
		else printf("%d\n", b[n / 2 - 1]);
	}
	return 0;
}