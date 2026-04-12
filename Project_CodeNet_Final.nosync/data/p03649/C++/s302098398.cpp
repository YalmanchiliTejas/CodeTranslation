#include <bits/stdc++.h>

#define For(i, l, r) for (register int i = (l), i##end = int(r); i <= i##end; ++i)
#define Fordown(i, r, l) for (register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Rep(i, r) for (register int i = (0), i##end = int(r); i < i##end; ++i)
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define debug(x) cout << #x << ": " << (x) << endl

using namespace std;

typedef long long ll;

template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

template<typename T = int>
inline T read() {
	T x(0), sgn(1); char ch(getchar());
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
	return x * sgn;
}

void File() {
#ifdef zjp_shadow
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
#endif
}

const int N = 55;

int n; ll a[N], ans;

inline ll Div(ll a, ll b) {
	return (a + b - 1) / b;
}

int main () {

	File();

	For (i, 1, (n = read())) a[i] = read<ll>();

	for (;;) {
		int p = 0;
		For (i, 1, n) if (a[i] > a[p]) p = i;
		if (a[p] < n) break;
		ll cur = Div(a[p] - (n - 1), n); ans += cur;
		a[p] -= cur * n;
		For (i, 1, n) if (p != i) a[i] += cur;
	}

	printf ("%lld\n", ans);

	return 0;

}