#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int gcd(int i, int j) {
	while (i && j) {
		if (i > j) i %= j;
		else j %= i;
	}
	return i + j;
}

#define MOD 1000000007
int main() {
	int h = ri() + 1, w = ri() + 1;
	int all = h * w;
	int res = (int64_t) all * (all - 1) * (all - 2) / 6 % MOD;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!i && !j) continue;
			res -= (int64_t) (h - i) * (w - j) % MOD * (gcd(i, j) - 1) * (i && j ? 2 : 1) % MOD;
			if (res < 0) res += MOD;
		}
	}
	for (int i = 0; i < all - 3; i++) res = res * 2 % MOD;
	std::cout << res << std::endl;
	return 0;
}

