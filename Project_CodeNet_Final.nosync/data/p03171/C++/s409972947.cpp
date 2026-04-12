#include<bits/stdc++.h>
using namespace std;

#define ll              long long
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
#define inf             (int)(1e18)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define rep(i,j,n)      for(int i=j;i<n;i++)
#define all(p)          p.begin(),p.end()
#define ub(a,b)         upper_bound(all(a),b)
#define lb(a,b)         lower_bound(all(a),b)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void run()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vector<int> a;
vector<vector<int>> dp;
vector<int> sum;
int solve(int i, int j)
{
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	if (i == j)
	{
		dp[i][j] = a[i];
	}
	else {
		int x = solve(i + 1, j);
		int y = solve(i, j - 1);
		x = sum[j] - sum[i + 1] + a[i + 1] - x;
		y = sum[j - 1] - sum[i] + a[i] - y;
		x += a[i];
		y += a[j];
		dp[i][j] = max(x, y);
	}
	return dp[i][j];
}
int32_t main()
{
	run();
	int n;
	cin >> n;
	a.resize(n);
	sum.resize(n);
	dp.assign(n, vector<int>(n, -1));
	rep(i, 0, n)
	{
		cin >> a[i];
	}
	sum[0] = a[0];
	rep(i, 1, n)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = solve(0, n - 1);
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans2 = sum[n - 1] - ans;
	cout << ans - ans2 << endl;
	return 0;
}