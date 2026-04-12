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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void d_m_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

char grid[1002][1002];

int power(int n, int x)
{
	if (x == 0)
		return 1;

	int small = power(n, x / 2) % mod;
	small = (small * small) % mod;

	if (1 & x)
		small = (n * small) % mod;

	return small;
}

bool isPowerOfTwo(int n)
{
	return n && (!(n & (n - 1)));
}


int dp[3002][3002][2];

int solve(int *a, int i, int j, bool turn)
{
	if (i > j)
		return 0;
	if (dp[i][j][turn] != -1)
		return dp[i][j][turn];
	if (turn == 1)
	{
		return dp[i][j][turn] = max(a[i] + solve(a, i + 1, j, 0), a[j] + solve(a, i, j - 1, 0));
	}
	else
		return dp[i][j][turn] = min(solve(a, i + 1, j, 1), solve(a, i, j - 1, 1));

}

int32_t main()
{
	//d_m_c();

	int n;
	cin >> n;

	int sum = 0;

	memset(dp, -1, sizeof dp);
	int a[n + 1];

	for (int i = 1; i <= n; i++)
	{	cin >> a[i];
		sum = sum + a[i];
	}

	int X = solve(a, 1, n, 1);
	int Y = sum - X;

	cout << (X - Y) << endl;

	return 0;
}