#include <bits/stdc++.h>

int main() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int a[n + 2];
			a[0] = i;
			a[1] = j;
			for (int k = 1; k <= n; k++) a[k + 1] = a[k] ^ a[k - 1] ^ (s[k % n] == 'x');
			if (a[0] != a[n] || a[1] != a[n + 1]) continue;
			for (int k = 0; k < n; k++) printf("%c", a[k] ? 'W' : 'S');
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}
