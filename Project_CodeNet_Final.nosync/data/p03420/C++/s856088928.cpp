#include <bits/stdc++.h>
#define For(i, l, r) for(register int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for(register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Set(a, v) memset(a, v, sizeof(a))
using namespace std;

inline bool chkmin(int &a, int b) {return b < a ? a = b, 1 : 0;}
inline bool chkmax(int &a, int b) {return b > a ? a = b, 1 : 0;}

inline int read() {
    int x = 0, fh = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
    return x * fh;
}

int main () {
	long long n = read(), k = read();
	long long ans = 0;
	if (k == 0) return printf ("%lld\n", n * n), 0;
	For (i, 1, n) {
		ans += n / i * max((i - k), 0ll);
		if (n % i) ans += max(n % i - k + 1, 0ll);
	}
	printf ("%lld\n", ans);
    return 0;
}
