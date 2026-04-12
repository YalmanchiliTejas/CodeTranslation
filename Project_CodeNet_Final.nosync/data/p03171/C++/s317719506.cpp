# include <bits/stdc++.h>
using namespace std;
#define int long long int
int mod = INT_MAX;
int memo[3005][3005];
int n;
int top(int a[], int i, int j)
{
	int &ans = memo[i][j];
	if (i > j)
		return 0;
	if (ans != -1)
		return ans;
	int turn = (n - 1 - (j - i)) % 2;
	if (turn == 0) //player 1 turn
	{
		ans = ((max(a[i] + top(a, i + 1, j), a[j] + top(a, i, j - 1)))) ;
	}
	else//player 2 turn
	{
		ans = (min(top(a, i + 1, j), top(a, i, j - 1)));
	}
	return ans ;
}
int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a[n];
	int sum = 0;
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int x = top(a, 0, n - 1);
	int y = sum - x;
	//cout << x << " " << y << " " << sum << endl;
	cout << (x - y);
	return 0;
}
// 3 8
// 3 30
// 4 50
// 5 60