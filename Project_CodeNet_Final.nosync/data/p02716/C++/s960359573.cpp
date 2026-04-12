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
const ll MOD = 1e9 + 7;
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
 
const int N = 2e5 + 5;
ll dp[N][2];
 
void solve()
{
	int n;
	cin >> n;
	v64 arr(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];
	memset(dp, 0, sizeof(dp));
	dp[2][1] = arr[2];
	dp[2][0] = arr[1];
	for (int i = 3; i < n + 1; i++)
	{
		if (i & 1)
		{
			ll temp = max({dp[i - 3][1], dp[i - 3][0], dp[i - 2][1], dp[i - 2][0]});
			dp[i][1] = arr[i] + temp;
			dp[i][0] = max({arr[i - 1] + dp[i - 2][0], arr[i - 1] + dp[i - 3][1], arr[i - 1] + dp[i - 3][0], arr[i - 2] + dp[i - 3][0]});
		}
		else
		{
			dp[i][1] = arr[i] + max({dp[i - 2][1], dp[i - 2][0], dp[i - 1][0]});
			dp[i][0] = arr[i - 1] + dp[i - 2][0];
		}
	}
	cout << max(dp[n][1], dp[n][0]) << ln;
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