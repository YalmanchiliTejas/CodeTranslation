/*
Miles Morales : When will I know I'm ready?
Peter B. Parker : You won't. It's a leap of faith. That's all it is, Miles. A leap of faith.
*/
//KEEP IT SIMPLE STUPID

#include <bits/stdc++.h>

// #pragma GCC optimize("O3")
// #pragma GCC target("avx")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ll long long
#define MP make_pair
#define ERR cout << "================================================\n"
#define fi first
#define se second
#define PB push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define ford(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
#define print(v)          \
	for (auto x : v)      \
	{                     \
		cout << x << " "; \
	}
#define MAX(v) *max_element(all(v))
#define MIN(v) *min_element(all(v))
#define SP << " " <<
#define W(t)  \
	ll t;     \
	cin >> t; \
	while (t--)
#define FIO                           \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FAST                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll INF = 1e18;
const ll NEG_INF = -1 * (1e18);
const ll MOD = 1e9 + 7;
using namespace std;

void usaco(string prob)
{
	freopen((prob + ".in").c_str(), "r", stdin);
	freopen((prob + ".out").c_str(), "w", stdout);
}

/* Function to check primality in O(sqrt(n)) */
bool prime(int n)
{
	if (n < 2)
		return false;
	for (int x = 2; x * x <= n; x++)
	{
		if (n % x == 0)
			return false;
	}
	return true;
}

/* Function to get prime factorization of n */
vector<int> getFactors(int n)
{
	vector<int> f;
	for (int x = 2; x * x <= n; x++)
	{
		while (n % x == 0)
		{
			f.push_back(x);
			n /= x;
		}
	}
	if (n > 1)
		f.push_back(n);
	return f;
}

void solve()
{
	/* Write Solution Here */
	ll n;
	cin >> n;
	vll a(n);
	forn(i, n) cin >> a[i];
	// sort(all(a));
	vll p(n, 0);
	p[n - 1] = a[n - 1];
	for (ll i = n - 2; i >= 0; i--)
	{
		p[i] = (p[i + 1] + a[i]) % MOD;
	}
	ll sum = 0;

	forn(i, n - 1)
	{
		sum = (sum % MOD + (a[i] * p[i + 1]) % MOD) % MOD;
	}
	cout << sum << "\n";
}

int main()
{
	//FIO
	FAST

		//usaco("cowlands");

		ll TC = 1;
	/*
	Uncomment when multiple test cases
	*/

	// cin>>TC;
	for1(tt, TC)
	{
		solve();
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
