#include <bits/stdc++.h>
//#define inf 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define MP make_pair
#define PB push_back

using namespace std;
typedef pair<int,int> Pair;
typedef long double ld;
typedef long long ll;

const int mod = 998244353, MAX = 1e5, N = 200005;
//template{{{
const long double Pi = 3.14159265358979323846l;
inline int add(int x, int y) { x += y; return x >= mod ? x - mod : x; };
inline void inc(int &x, int y) { x += y; x -= (x >= mod ? mod : 0); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int Power(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		x = mul(x, x), y >>= 1;
	} return ans;
}

/*char buf[1<<23],obuf[1<<23],*p1=buf,*p2=buf, *O = obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void print(int x) {
    if(x > 9) print(x / 10);
    *O++=x%10+'0';
} */

template <class T> inline T	input() {
	T x; char ch; bool flag = false;
	while (!isdigit(ch = getchar())) flag |= ch == '-';
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return flag ? -x : x;
}

template <class T> inline bool chkmin(T &x, T y) { x = x < y ? x : y; return x == y; }
template <class T> inline bool chkmax(T &x, T y) { x = x > y ? x : y; return x == y; }
template <class T> inline T gcd(T x, T y) { return !y ? x : gcd(y, x % y); }
template <class T> inline T sqrm(T x) { return (ll) x * x % mod; }
template <class T> inline T sqr(T x) { return x * x; }

struct {
	inline operator int () { return input<int>(); }
	inline operator long long () { return input<long long>(); }
	template <class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read; //}}}

int n;
int a[N];
ll dp[N][2][2];

int main() {
#ifdef local
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	freopen("log", "w", stderr);
#endif

	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);

	memset(dp, 0x80, sizeof dp);
	dp[0][1][0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (i & 1) {
			chkmax(dp[i][0][0], dp[i - 1][1][0]);
			chkmax(dp[i][0][0], dp[i - 1][1][1]);
			chkmax(dp[i][0][1], dp[i - 1][0][0] + a[i]);
			chkmax(dp[i][1][1], dp[i - 1][1][0] + a[i]);
		} else {
			chkmax(dp[i][0][0], dp[i - 1][0][0]);
			chkmax(dp[i][0][0], dp[i - 1][0][1]);
			chkmax(dp[i][1][0], dp[i - 1][1][0]);
			chkmax(dp[i][1][0], dp[i - 1][1][1]);
			chkmax(dp[i][1][1], dp[i - 1][0][0] + a[i]);
		}
	}

	printf("%lld\n", max(dp[n][!(n & 1)][0], dp[n][!(n & 1)][1]));
	return 0;
}
