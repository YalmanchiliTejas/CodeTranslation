#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 			1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl 			'\n'
#define inf 			1e18
#define fi 				first
#define se 				second

int XX[8] = { +1, +1, +1, 0, 0, -1, -1, -1};
int YY[8] = { +1, 0, -1, +1, -1, +1, 0, -1};
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n;
int a[3001];
int dp[3001][3001][2];

int solve(int i, int j, int fl) {
	if (i > j) return 0;
	if (dp[i][j][fl] != -1) return dp[i][j][fl];
	if (fl) {
		return dp[i][j][fl] = max(a[i] + solve(i + 1, j, 0), a[j] + solve(i, j - 1, 0));
	}

	return dp[i][j][fl] = min(solve(i + 1, j, 1), solve(i, j - 1, 1));
}

signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin >> n;
	int sum = 0;
	for0(i, n) cin >> a[i], sum += a[i];

	memset(dp, -1, sizeof(dp));

	int x = solve(0, n - 1, 1);
	int y = sum - x;

	cout << x - y << endl;

	return 0;
}