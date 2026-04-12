#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long LL;

const int MAXN = 2e5;
const LL INF = 0x3f3f3f3f;

int n;
int mins[MAXN | 1], maxs[MAXN | 1];
LL ans;

struct Num {
	int a, b;
	Num() {}
	friend bool operator < (const Num &x, const Num &y) {
		return x.a < y.a;
	}
} p[MAXN | 1];

inline int read() {
	register int x = 0;
	register char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

int main() {
	n = read();
	int min = 0, max = INF;
	int bmax = -1, rmax = -1;
	int bmin = INF, rmin = INF;
	for (int i = 1; i <= n; ++i) {
		p[i].a = read();
		p[i].b = read();
		if (p[i].a > p[i].b) std::swap(p[i].a, p[i].b);
		bmax = std::max(bmax, p[i].b);
		bmin = std::min(bmin, p[i].b);
		rmax = std::max(rmax, p[i].a);
		rmin = std::min(rmin, p[i].a);
	}
	std::sort(p + 1, p + 1 + n);
	ans = 1LL * (bmax - bmin) * (rmax - rmin);
	bmin = rmin;
	LL ans2 = INF;
	maxs[1] = mins[1] = p[1].b;
	for (int i = 2; i <= n; ++i) {
		maxs[i] = std::max(maxs[i - 1], p[i].b);
		mins[i] = std::min(mins[i - 1], p[i].b);
		if (i != n) ans2 = std::min(ans2, 1LL * std::max(maxs[i], p[n].a) - std::min(mins[i], p[i + 1].a));
	}
	printf("%lld\n", std::min(ans, ans2 * (bmax - bmin)));
	return 0;
}
