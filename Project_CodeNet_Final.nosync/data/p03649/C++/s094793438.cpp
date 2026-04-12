#include <bits/stdc++.h>

using namespace std;

int n;
long long x[55], lo, hi, mi, u;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", x + i);
		hi += x[i];
	}
	lo = max((long long)0, hi - n * (n - 1));
	hi++;
	for (mi = lo; mi < hi; mi++) {
		u = 0;
		for (int i = 0; i < n && u != -1; i++)
			if ((x[i] + mi) % (n + 1) == n)
				u = -1;
			else
				u += (x[i] + mi) / (n + 1);
		if (u == mi) {
			printf("%lld\n", mi);
			return 0;
		}
	}
	return 0;
}