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

int dp[3001][3001];
mk(arr, 3001, int);
int pre_sum[3001];

int max_sum(int i, int j)
{
	if (i > j)
		return dp[i][j] = 0;;

	if (dp[i][j] != 0)
		return dp[i][j];

	if (i == j)
		return dp[i][j] = arr[i];

	int curr_sum = pre_sum[j] - pre_sum[i - 1];
	return dp[i][j] += curr_sum - min(max_sum(i + 1, j), max_sum(i, j - 1));
}

int32_t main()
{
	FIO;

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pre_sum[i] = pre_sum[i - 1] + arr[i];
	}

	cout << 2 * max_sum(1, n) - pre_sum[n] << endl;

	return 0;
}