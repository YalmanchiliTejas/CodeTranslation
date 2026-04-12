#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
int n;
int64 a[55];

int main() {
	scanf("%d", &n);

	int64 t = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		t += a[i];
	}

	for(int64 s = max(0LL, t - n * (n - 1)); s <= t; s++) {
		int64 tot = 0;
		int bad = 0;

		for(int i = 1; i <= n; i++) {
			int64 x = (a[i] + s + 1) / (n + 1);
			int64 y = (a[i] + s) / (n + 1);

			if(x > y) {
				bad = 1;
				break;
			}

			tot += x;
		}

		if(bad)
			continue;

		if(tot <= s) {
			printf("%lld\n", s);
			break;
		}
	}

	return 0;
}