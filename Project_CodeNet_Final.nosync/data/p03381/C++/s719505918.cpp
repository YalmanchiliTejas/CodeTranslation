#include <bits/stdc++.h>

using namespace std;

int n;
int x[202020];
int t[202020];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		t[i] = x[i];
	}
	sort(t, t + n);
	int m = (n - 1) >> 1;
	for (int i = 0; i < n; ++i) {
		int pos = lower_bound(t, t + n, x[i]) - t;
		if (pos <= m) {
			printf("%d\n", t[m + 1]);
		} else {
			printf("%d\n", t[m]);
		}
	}
	return 0;
}