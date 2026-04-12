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
pair<int, int> p[maxn];

bool read()
{
	if (scanf("%d", &n) != 1)
		return false;

	forn (i, n)
		scanf("%d %d", &p[i].first, &p[i].second);

	return true;
}

void solve()
{
	llong L = inf, l = inf, R = -inf, r = -inf;

	forn (i, n)
	{
		if (p[i].first > p[i].second)
			swap(p[i].first, p[i].second);

		L = umin(L, p[i].first);
		R = umax(R, p[i].second);
		l = umin(l, p[i].second);
		r = umax(r, p[i].first);
	}

	llong ans = (r - L) * (R - l);
	sort(p, p + n);
	multiset<int> s;

	forn (i, n)
		s.insert(p[i].first);

	ans = min(ans, (R - L) * (*s.rbegin() - *s.begin()));

	forn (i, n)
	{
		s.erase(s.find(p[i].first));
		s.insert(p[i].second);
		ans = min(ans, (R - L) * (*s.rbegin() - *s.begin()));
	}

	printf("%lld\n", ans);
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
