#include <bits/stdc++.h>

typedef long long LL;

#define FOR(i, a, b) for (int i = (a), i##_END_ = (b); i <= i##_END_; ++i)
#define DNF(i, a, b) for (int i = (a), i##_END_ = (b); i >= i##_END_; --i)

template <typename Tp> void in(Tp &x) {
	char ch = getchar(), f = 1; x = 0;
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
}

template <typename Tp> bool chkmax(Tp &x, Tp y) {return x >= y ? 0 : (x=y, 1);}
template <typename Tp> bool chkmin(Tp &x, Tp y) {return x <= y ? 0 : (x=y, 1);}
template <typename Tp> Tp Max(const Tp &x, const Tp &y) {return x > y ? x : y;}
template <typename Tp> Tp Min(const Tp &x, const Tp &y) {return x < y ? x : y;}

int n, k;

int main()
{
	in(n); in(k);

	LL ans = 0;
	
	FOR(b, k + 1, n) {
		int one = b - k;
		int time = n / b;
		ans += time * 1ll * one;
		ans += Max(0, (n - ((n / b) * b + k) + 1));
		if (k == 0) ans--;
	}

	printf("%lld\n", ans);
	
	return 0;
}
