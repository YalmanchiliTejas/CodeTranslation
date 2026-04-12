#include <bits/stdc++.h>
 
#define forn(i, n) for (llong i = 0ll; i < (llong) n; ++i)
#define fornn(i, l, r) for (llong i = (llong) l; i < (llong) r; ++i)
#define size(x) ((int) (x.size()))
 
using namespace std;
 
typedef long long llong;
const llong inf = (llong) 1e+9 + 7ll;
const llong linf = (llong) 1e+18 + 7ll;
const long double eps = (long double) 1e-9;
const long double pi = acosl((long double) -1.0);
const int alph = 26;

mt19937 mrand(random_device{} ()); 

template<typename T, typename U> inline llong umin(const T& a, const U& b) { return a < b ? a : b; }
template<typename T, typename U> inline llong umax(const T& a, const U& b) { return a > b ? a : b; }
 
static char buff[(int) 2e6 + 17]; // reads std::string
const int maxn = (int) 2e3 + 17;

int n, a, b, c, d;
llong R[maxn];
llong binomial[maxn][maxn], dp[maxn][maxn];

bool read()
{
	if (scanf("%d", &n) != 1)
		return false;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	return true;
}

llong binpow(llong a, int b)
{
	llong res = 1ll;

	for (; b > 0; b >>= 1, a = a * a % inf)
		if (b & 1) res = res * a % inf;

	return res;
}

void solve()
{
	binomial[0][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		binomial[i][0] = 1;

		for (int j = 1; j <= i; ++j)
		{
			binomial[i][j] = binomial[i - 1][j - 1] + binomial[i - 1][j];
			
			if (binomial[i][j] >= inf)
				binomial[i][j] -= inf;
		}
	}

	llong f = 1;
	R[0] = binpow(f, inf - 2);

	forn (i, n)
	{
		f *= i + 1;
		f %= inf;
		R[i + 1] = binpow(f, inf - 2);
	}

	forn (i, n + 1)
		dp[0][i] = 1ll;

	for (int i = 1; i <= n; ++i)
	{
		for (int len = a; len <= b; ++len)
		{
			int nn = n - i;
			llong cur = 1ll;

			for (int cnt = 1; cnt < c && nn + len <= n; ++cnt, nn += len)
			{
				cur *= binomial[nn + len][len];
				cur %= inf;
			}

			for (int cnt = c; cnt <= d && i - len * cnt >= 0; ++cnt, nn += len)
			{
				cur *= binomial[nn + len][len];
				cur %= inf;
				dp[i][len] += (cur * dp[i - len * cnt][len - 1] % inf) * R[cnt];
				dp[i][len] %= inf;
			}
		}

		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] += dp[i][j - 1];

			if (dp[i][j] >= inf)
				dp[i][j] -= inf;
		}
	}

	printf("%lld\n", dp[n][n]);
}

int main()
{
#if SEREZHKA
	freopen("file.in", "r", stdin);
#endif

	while (read())
		solve();

	return 0;
}
