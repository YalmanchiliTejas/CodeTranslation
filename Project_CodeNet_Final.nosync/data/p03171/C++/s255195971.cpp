#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3005][3005];

ll dequeGame(ll arr[], ll n, ll i, ll j)
{
	if (i > j)
		return 0;
	if (j == i + 1)
		return max(arr[i], arr[j]);

	if (dp[i][j] != -1)
		return dp[i][j];

	//I select first;
	ll op1 = min(dequeGame(arr, n, i + 2, j), dequeGame(arr, n, i + 1, j - 1));
	//I select last;
	ll op2 = min(dequeGame(arr, n, i + 1, j - 1), dequeGame(arr, n, i, j - 2));

	return dp[i][j] = max(op1 + arr[i], op2 + arr[j]);
}

int main()
{

	ll n;
	cin >> n;

	ll arr[n + 1];
	ll tot = 0;

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		tot += arr[i];
	}
	memset(dp, -1, sizeof(dp));
	ll tmp = dequeGame(arr, n, 0, n - 1);

	cout << tmp - (tot - tmp);
}