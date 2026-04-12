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
const int maxn = (int) 2e5 + 17;

int n;
llong a[maxn], b[maxn], c[maxn];

bool read()
{
	if (scanf("%d", &n) != 1)
		return false;

	forn (i, n)
		scanf("%lld", a + i);

	return true;
}

void gen()
{
	n = 1 + mrand() % 10;

	forn (i, n)
		a[i] = 1 + mrand() % 11;
}

llong naive()
{
	forn (i, n)
		c[i] = b[i] = a[i];

	llong res = 0ll;

	while (true)
	{
		sort(b, b + n);
		reverse(b, b + n);

		if (b[0] < n)
			return res;
		
		++res;
		b[0] -= n;
		
		forn (j, n - 1)
			++b[j + 1];
	}
}

void solve()
{
	sort(a, a + n);
	reverse(a, a + n);
	llong ans = 0;
	llong wans;
#ifdef SEREZHKA
	wans = naive();
#endif
	a[n] = -linf;

	forn (i, n - 1)
	{
		if (a[0] - a[i] < n)
		{
			llong l = 1, r = (llong) 1e16;

			for (; l < r; )
			{
				llong m = (l + r) / 2;

				vector<llong> cur(a, a + n);

				forn (j, i + 1)
					cur[j] -= (m - 1) * (n - i);

				for (int j = i + 1; j < n; ++j)
					cur[j] += (i + 1) * (m - 1);

				bool good = true;

				forn (k, i + 1)
				{
					if (cur[i] < cur[i + 1])
					{
						good = false;
						break;
					}

					sort(cur.begin(), cur.begin() + i + 1);
					reverse(cur.begin(), cur.begin() + i + 1);

					forn (j, n)
						++cur[j];

					cur[0] -= n + 1;

					if (cur[0] < cur[i + 1])
					{
						good = false;
						break;
					}
				}

				if (!good)
					r = m;
				else
					l = m + 1;
			}

			ans += (l - 1) * (i + 1);

			forn (j, i + 1)
				a[j] -= (l - 1) * (n - i);

			for (int j = i + 1; j < n; ++j)
				a[j] += (i + 1) * (l - 1);
		}

		while (true)
		{
			sort(a, a + i + 2);
			reverse(a, a + i + 2);

			if (a[0] - a[i + 1] < n)
				break;

			if (min(a[0] - n, a[i + 1] + 1) < a[i + 2] + 1)
				break;

			a[0] -= n;
			++ans;

			forn (j, n - 1)
				++a[j + 1];
		}
	}

	ans += 1ll * n * max(0ll, a[n - 1] - n + 1);

	forn (i, n)
		a[i] -= max(0ll, a[n - 1] - n + 1);

	while (true)
	{
		sort(a, a + n);
		reverse(a, a + n);

		if (a[0] < n)
			break;

		a[0] -= n;
		++ans;

		forn (j, n - 1)
			++a[j + 1];
	}

#ifdef SEREZHKA
	if (ans != wans)
	{
		cout << n << endl;

		forn (i, n)
			cout << c[i] << ' ';

		cout << ans << ' ' << wans << endl;
	}
	else
		return ;
#endif

	printf("%lld\n", ans);
}

int main()
{
#if SEREZHKA
	freopen("file.in", "r", stdin);
#endif

#ifdef SEREZHKA
	while (1)
	{
		gen();
		solve();
	}
#endif

	while (read())
		solve();

	return 0;
}
