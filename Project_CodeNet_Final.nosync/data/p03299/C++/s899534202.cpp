#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define TWO 500000004

int n, x[105], par[105], ta, tc;
set<int> m;
set<int>::iterator it;
long long ya[105], yb[105], tb;

int find(int a) {
	return par[a] == a ? a : par[a] = find(par[a]);
}

long long po(long long b, int p) {
	long long re = 1;
	while (p) {
		if (p & 1)
			re = re * b % MOD;
		b = b * b % MOD;
		p >>= 1;
	}
	return re;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", x + i);
		m.insert(x[i]);
	}
	m.insert(1);
	it = m.end();
	while (it != m.begin()) {
		it--;
		ta = *it;
		for (int i = 1; i <= n; i++)
			if (par[i]) {
				if (par[i] == i) {
					yb[i] = yb[i] * po(2, x[i] - ta) % MOD;
					x[i] = ta;
					if (par[i - 1]) {
						tc = find(i - 1);
						tb = yb[tc] * yb[i] % MOD * TWO % MOD;
						ya[tc] = ((ya[tc] + yb[tc]) * (ya[i] + yb[i]) % MOD + MOD - tb) % MOD;
						yb[tc] = tb;
						par[i] = tc;
					}
				}
			} else if (x[i] == ta) {
				if (par[i - 1]) {
					tc = find(i - 1);
					ya[tc] = (ya[tc] * 2 + yb[tc]) % MOD;
					par[i] = tc;
				} else {
					par[i] = i;
					yb[i] = 2;
				}
			}
		// printf("[%d]\n", ta);
		// for (int i = 1; i <= n; i++) if (par[i] == i) printf("%d  %lld %lld\n", i, ya[i], yb[i]);
	}
	printf("%lld\n", (ya[1] + yb[1]) % MOD);
	return 0;
}
