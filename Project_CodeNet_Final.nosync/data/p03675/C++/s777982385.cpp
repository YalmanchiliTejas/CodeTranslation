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
int a[maxn];

bool read()
{
	if (scanf("%d", &n) != 1)
		return false;

	forn (i, n)
		scanf("%d", a + i);

	return true;
}

void solve()
{
	deque<int> d;

	forn (i, n)
		if (i & 1 ^ 1)
			d.push_back(a[i]);
		else
			d.push_front(a[i]);

	if (n & 1)
		reverse(d.begin(), d.end());

	for (auto i : d)
		printf("%d ", i);

	printf("\n");
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
