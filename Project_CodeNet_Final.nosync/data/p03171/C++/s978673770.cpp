#include<bits/stdc++.h>
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

void FIO()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n, k;
vector<int> a;
int dp[3001][3001][2];

int solve(int first_index, int last_index, int turn)
{
	if (first_index > last_index)
		return 0;

	if (dp[first_index][last_index][turn] != -1)
		return dp[first_index][last_index][turn];


	if (turn == 1)
	{
		return dp[first_index][last_index][turn] = max(a[first_index] + solve(first_index + 1, last_index, 0), a[last_index] + solve(first_index, last_index - 1, 0));
	}
	else
	{
		return dp[first_index][last_index][turn] = min(solve(first_index + 1, last_index, 1), solve(first_index, last_index - 1, 1));
	}
}

int32_t main()
{
	FIO();
	cin >> n;
	int tot_sum = 0;

	a.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		tot_sum += a[i];
	}

	memset(dp, -1, sizeof(dp));

	int taro = solve(0, n - 1, 1);
	int jiro = tot_sum - taro;

	cout << taro - jiro << '\n';

	return 0;
}