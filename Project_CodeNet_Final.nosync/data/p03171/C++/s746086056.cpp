#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define AB_BHI_NI_DEGI                \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define int long long
#define pb push_back
#define N 100009
#define inf 1e18
const double PI = 3.141592653589793238462643383279;
int mod = 1e9 + 7;
//int mod = 998244353;
#define P pair<int, int>
#define F first
#define S second
#define ll long long
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define ld long double

#define ordered_set tree<P, null_type, less<P>, rb_tree_tag, tree_order_statistics_node_update>

void end(int n = -1)
{
	cout << n << "\n";
	exit(0);
}
int n;
int a[3009];
int dp[3009][3009][2];
bool vis[3009][3009][2];

int fun(int i, int j, int ch)
{
	if (i > j)
		return 0;
	if (vis[i][j][ch])
		return dp[i][j][ch];
	int ans = 0;
	if (ch)
	{
		ans = max(a[i] + fun(i + 1, j, !ch), a[j] + fun(i, j - 1, !ch));
	}
	else
	{
		ans = min(-a[i] + fun(i + 1, j, !ch), -a[j] + fun(i, j - 1, !ch));
	}
	vis[i][j][ch] = 1;
	return dp[i][j][ch] = ans;
}

int32_t main()
{
	AB_BHI_NI_DEGI
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << -fun(0, n - 1, 0) << "\n";

	return 0;
}