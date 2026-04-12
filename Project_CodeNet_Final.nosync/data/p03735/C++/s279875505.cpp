#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
//#define inf 0x3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define N 300005

using namespace std;
typedef pair<int,int> Pair;
typedef long long ll;

const long double Pi = 3.14159265358979323846l;
const int mod = 1e9 + 7;
inline int add(int x, int y) { return (x += y) - (x >= mod ? mod : 0); }
inline void inc(int &x, int y) { (x += y) -= (x >= mod ? mod : 0); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int Power(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = mul(res, x);
		x = mul(x, x), y >>= 1;
	} return res;
}

template <class T> inline T	input() {
	T x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

template <class T> inline void chkmin(T &x, T y) { x = x < y ? x : y; }
template <class T> inline void chkmax(T &x, T y) { x = x > y ? x : y; }

struct {
	inline operator int () { return input<int>(); }
	inline operator long long () { return input<long long>(); }
	template <class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

int n;
int x[N], y[N];
Pair a[N];

signed main() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(x[i], y[i]);
		if (x[i] > y[i]) swap(x[i], y[i]);
		a[i] = make_pair(x[i], y[i]);
	}

	long long ans = inf;
	int minx = inf, maxx = 0, miny = inf, maxy = 0;

	for (int i = 1; i <= n; ++i) {
		chkmin(minx, x[i]);
		chkmax(maxx, x[i]);
		chkmin(miny, y[i]);
		chkmax(maxy, y[i]);
	}

	chkmin(ans, 1ll * (maxx - minx) * (maxy - miny));

	sort(a + 1, a + n + 1);
	long long D = maxy - minx;

	minx = inf;
	for (int i = 1; i <= n; ++i) {
		chkmax(maxx, a[i].se);
		chkmin(minx, a[i].se);
		if (a[i + 1].fi >= minx) {
			chkmin(ans, D * (maxx - minx));
			break;
		}
		chkmin(ans, D * (maxx - a[i + 1].fi));
	}

	printf("%lld\n", ans);
	return 0;
}
