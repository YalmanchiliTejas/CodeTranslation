#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO
#define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n) for (int i = 0; i < n; ++i) cin >> c[i];
#define exit_message(s) return 0 * printf(s)
#define show_all(c) for (auto i: c) cout << i << " "; cout << "\n";
#define display(c, a, n) cout << "Displaying array \"" << #c << "\" : \n"; for (int (i) = (a); (i) < (n); ++(i)) cout << (c)[(i)] << " "; cout << "\n";
#define forl(i, a, n) for (int i = (a); (i) < (n); ++(i))
#define dugbe(k) cout << "-\t> " << #k << " = " << k << "\n";

// What follows is a magical ordered set data structure.
// Supports the following functions:
// find_by_order(int k) - returns k'th smallest element (0-indexed)
// order_of_key(int k) - returns number of elements strictly smaller than k.

// using namespace __gnu_pbds;
// #define ordered_set tree <ll, null_type, greater_equal <ll>, rb_tree_tag, tree_order_statistics_node_update>

/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/

using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const long double eps = 1e-7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long true_rand(long long n)
{
	// Returns a random number between 0 and n - 1 inclusive using mt19937.
    uniform_int_distribution<long long> uid(0, n - 1);
    return uid(rng);
}

ll mod_pow(ll a, ll b)
{
	if (b == 0)
		return 1LL;

	ll res = mod_pow(a, b >> 1);
	res = (res * res) % mod;
	if (b & 1LL)
		res = (res * a) % mod;
	
	return res;
}

const int N = 50 + 5, INF = 1e9 + 100;
string k;
int d, n;

ll solve(int idx, int dd, bool wall)
{
	if (idx == n)
	{
		return 1;
	}

	ll res = 0;
	int tdd;
	for (char x = '0'; x < k[idx]; ++x)
	{
		tdd = ( dd - (x - '0') % d + d) % d;
		res += solve(idx + 1, tdd, false);
		res %= mod;
	}
	tdd = ( dd - (k[idx] - '0') % d + d) % d;
	res += solve(idx + 1, tdd, wall);
	res %= mod;

	return res;
}

ll find()
{
	ll res = 0;
	int tdd;
	for (char x = '0'; x < k[0]; ++x)
	{
		tdd = (d - (x - '0') % d) % d;
		res += solve(1, tdd, false);
		res %= mod;
	}
	tdd = (d - (k[0] - '0') % d) % d;
	res += solve(1, tdd, true);
	res %= mod;

	return res;
}

void add_self(int &a, int b)
{
	a += b;
	a %= mod;
}

int32_t main()
{
	#ifdef FASTIO
		// ios_base::sync_with_stdio(false);
		// cin.tie(NULL);
	#endif
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> k >> d;

	n = (int)k.length();

	vector<vector<int>> dp(d, vector<int>(2, 0));
	// dp[j][w] represents the number of ways until now
	// to get digit sum j modulo d and w = 1 if you're 
	// moving along the upper bound of k and w = 0 otherwise.
	dp[0][0] = 0, dp[0][1] = 1;
	for (int i = 0; i < n; ++i)
	{
		vector<vi> temp_dp(d, vi(2, 0));
		for (int j = 0; j < d; ++j)
		{
			for (int dig = 0; dig < 10; ++dig)
			{
				int temp = (j + dig) % d;
				add_self(temp_dp[temp][0], dp[j][0]);
				// cout << temp << ", " << 0 << " += " << dp[j][0]  << " for " << j << ", " << "0\n";
				// temp_dp[temp][0] += dp[j][0];
				// temp_dp[temp][0] %= mod;
				if (dig < k[i] - '0')
				{
					add_self(temp_dp[temp][0], dp[j][1]);
					// cout << temp << ", " << 0 << " += " << dp[j][1] << " for " << j << ", " << "1\n";
					// temp_dp[temp][0] += dp[j][1];
					// temp_dp[temp][0] %= mod;
				}
				if (dig == k[i] - '0')
				{
					add_self(temp_dp[temp][1], dp[j][1]);
					// cout << temp << ", " << 1 << " += " << dp[j][1] << " for " << j << ", " << "1\n";
					// temp_dp[temp][1] += dp[j][1];
					// temp_dp[temp][1] %= mod;
				}
			}
		}
		forl(j, 0, d)
		{
			forl(b, 0, 2)
			{
				// dugbe(j << " " << b << " " << temp_dp[j][b]);
				dp[j][b] = temp_dp[j][b];
			}
		}
	}

	ll ans = (dp[0][0] + dp[0][1]) % mod;
	ans = (ans - 1 + mod) % mod;
	cout << ans << "\n";

	return 0;
}