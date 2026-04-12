#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], pos[N], p[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		if (i % 2 == (n + 1) % 2) {
			pos[i] = ((n + 1) - i) / 2 + i;
		} else {
			pos[i] = ((n + 1) - (i - 1)) / 2;
		}
	}
	for (int i = 1; i <= n; ++i) p[pos[i]] = a[i];
	for (int i = 1; i <= n; ++i) printf("%d ", p[i]); printf("\n");
}