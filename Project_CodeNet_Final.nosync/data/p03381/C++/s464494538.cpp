#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = long long;

void solve();
int main() {
	solve();
#ifdef DBG
	while (true);
#endif
}

void solve() {
	int n, x[200000], s[200000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", x + i), s[i] = x[i];
	sort(s, s + n);
	for (int i = 0; i < n; i++) {
		if (x[i] <= s[n / 2 - 1])
			printf("%d\n", s[n / 2]);
		else
			printf("%d\n", s[n / 2 - 1]);
	}
}