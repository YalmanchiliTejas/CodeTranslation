//author Eterna King
#define Hello the_cruel_world!
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<climits>
#include<deque>
#include<functional>
#include<numeric>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
#define lowbit(x) ((x) & (-(x)))
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.in", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.out", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define outd(x) printf("%d\n", x)
#define outld(x) printf("%lld\n", x)
#define memset0(arr) memset(arr, 0, sizeof(arr))
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 2e5;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
il int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll quick_pow(ll base, ll index) {
	ll res = 1;
	while (index) {
		if (index & 1)res = res * base % mod;
		base = base * base % mod;
		index >>= 1;
	}
	return res;
}
int n, m, k, tot;
ll f[maxn + 5], coe, res;
int main()
{
	n = read_int(), m = read_int(), k = read_int();
	tot = n * m;
	f[0] = f[1] = 1;
	for (int i = 2; i <= tot; ++i)f[i] = f[i - 1] * i % mod;
	coe = f[tot - 1] * quick_pow(f[k - 1], mod - 2) % mod * quick_pow(f[tot - k], mod - 2) % mod * quick_pow(tot - 1, mod - 2) % mod;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			ll sum = 0;
			ll a = 1ll * (i - 1) * m, b = 1ll * (n - i) * m;
			sum += a * i - 1ll * m * i * (i - 1) / 2;
			sum %= mod;
			sum += 1ll * (n - i) * (n + i + 1) / 2 % mod * m - b * i;
			sum %= mod;
			res = (res + sum) % mod;
			a = 1ll * (j - 1) * n, b = 1ll * (m - j) * n;
			sum = 0;
			sum += a * j - 1ll * n * j * (j - 1) / 2;
			sum %= mod;
			sum += 1ll * (m - j) * (m + j + 1) / 2 % mod * n - b * j;
			sum %= mod;
			res = (res + sum) % mod;
		}
	res = res * quick_pow(2, mod - 2) % mod;
	res = res * coe % mod;
	res = res * (k - 1) % mod;
	cout << res << endl;
	//system("pause");
	return 0;
}