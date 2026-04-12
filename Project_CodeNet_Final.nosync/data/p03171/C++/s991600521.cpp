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
#define w(x)            int x; cin>>x; while(x--)
#define fr(i,a,b)       for(int i = a; i < b; i++)

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int dp[3000][3000][2];
int n;

int dequeue(vi &arr, int x, int y, int player)
{
	if (x > y) return 0;

	if (dp[x][y][player] != -1)
		return dp[x][y][player];

	if (player == 0)
		return dp[x][y][0] = max(arr[x] + dequeue(arr, x + 1, y, 1), arr[y] + dequeue(arr, x, y - 1, 1));
	else
		return dp[x][y][1] = min(dequeue(arr, x + 1, y, 0), dequeue(arr, x, y - 1, 0));
}

void solve()
{
	int total = 0;
	cin >> n;
	vi arr(n);
	fr(i, 0, n)
	{
		cin >> arr[i];
		total += arr[i];
	}
	memset(dp, -1, sizeof(dp));
	int X = dequeue(arr, 0, n - 1, 0);
	int Y = total - X;
	cout << X - Y << endl;

}

int32_t main()
{
	c_p_c();
	solve();
	return 0;
}