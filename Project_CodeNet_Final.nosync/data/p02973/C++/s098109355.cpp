#include <bits/stdc++.h>
using namespace std;
int n, l, ans;
int a[100021];
int f[100021];
int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	reverse(a, a + n);
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++) {
		int p = upper_bound(f, f + n, a[i]) - f;
		f[p] = a[i];
	}
	l = lower_bound(f, f + n, 0x3f3f3f3f) - f;
	printf("%d", l);
	return 0;
}