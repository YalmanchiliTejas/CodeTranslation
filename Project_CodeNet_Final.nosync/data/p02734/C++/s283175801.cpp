//Himanshu Shukla
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
//#define file_input
//#define multitest
//#define measure_time
#define ll long long
#define v32 vector<int>
#define v64 vector<ll>
#define s32 set<int>
#define s64 set<ll>
#define graph vector<v32>
#define p32 pair<int, int>
#define p64 pair<ll, ll>
#define sz(v) (ll)(v).size()
#define fi first
#define se second
#define ln '\n'
#define debug(x) cerr << (#x) << ": " << (x) << ln
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }
const double EPS = 1e-6;
const ll MOD = 998244353;
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
	out << '[' << p.fi << ", " << p.se << ']';
	return out;
}
template <template <typename, typename...> class ContainerType, typename ValueType, typename... Args>
void print_container(const ContainerType<ValueType, Args...> &c)
{
	cout << "{ ";
	for (const auto &v : c)
		cout << v << ' ';
	cout << '}' << ln;
}

ll dp[3005][3005];

ll go(ll i, ll s, v64 &arr)
{
	if (s == 0)
		return sz(arr) - i + 1;
	if (s < 0)
		return 0;
	if (i >= sz(arr) && s != 0)
		return 0;
	if (dp[i][s] != -1)
		return dp[i][s];
	return (dp[i][s] = add(go(i + 1, s - arr[i], arr), go(i + 1, s, arr), MOD));
}

void solve()
{
	ll n, s;
	cin >> n >> s;
	v64 arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	go(0, s, arr);
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s >= arr[i])
		{
			ll temp = mul(i + 1, go(i + 1, s - arr[i], arr), MOD);
			ans = add(ans, temp, MOD);
		}
	}
	cout << ans << ln;
	return;
}

int main()
{
	FASTIO;
#ifdef file_input
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	clock_t start, stop;
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
#ifdef measure_time
	start = clock();
#endif
	for (int tc = 1; tc < t + 1; tc++)
		solve();
#ifdef measure_time
	stop = clock();
	cerr << "Time :" << fixed << setprecision(5) << double(stop - start) / double(CLOCKS_PER_SEC) << "s" << ln;
#endif
	return 0;
}
