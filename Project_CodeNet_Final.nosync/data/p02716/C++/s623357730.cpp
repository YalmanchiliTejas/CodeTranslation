#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
	FIO;
	int n; cin >> n;
	map<int, int> dp[n];

	mk(arr, n, int);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	if (n == 2)
		cout << max(arr[0], arr[1]) << '\n';

	else
	{
		dp[0][0] = dp[1][0] = dp[2][0] = 0;
		dp[0][1] = arr[0];
		dp[1][1] = max(arr[1], arr[0]);
		dp[2][1] = max({arr[0], arr[1], arr[2]});
		dp[2][2] = arr[0] + arr[2];

		for (int i = 3; i < n; ++i)
		{
			dp[i] = dp[i - 1];

			vi rm;

			for (auto el : dp[i - 2])
			{
				if (dp[i].count(el.ff + 1))
					dp[i][el.ff + 1] = max(dp[i][el.ff + 1], el.ss + arr[i]);

				else
					dp[i][el.ff + 1] = el.ss + arr[i];

			}

			for (auto el : dp[i])
				if (el.ff < (i + 1) / 2 - 10 || el.ff > (i + 1) / 2 + 10)
					rm.pb(el.ff);

			for (int id : rm)
				dp[i].erase(id);
		}

		int ans = -inf;

		for (int i = 0; i < n; ++i)
		{
			//cout << dp[i].size() << '\n';
			if (dp[i].count(n / 2))
				ans = max(ans, dp[i][n / 2]);
		}

		cout << ans << '\n';
	}
	return 0;
}