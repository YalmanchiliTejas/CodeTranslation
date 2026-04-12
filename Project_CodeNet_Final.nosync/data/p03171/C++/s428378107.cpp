#include <iostream>
#include<algorithm>
#include<cstring>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define nt _int128
#define inf (int)1e9
ll dp[3001][3001];
ll game(ll arr[], ll n, ll i, ll j)
{
	if (i > j) return dp[i][j] = 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	ll a = arr[i] + min(game(arr, n, i + 2, j), game(arr, n, i + 1, j - 1));
	ll b = arr[j] + min(game(arr, n, i, j - 2), game(arr, n, i + 1, j - 1));
	return dp[i][j] = max(a, b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	// cin >> t;
	t  = 1;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		ll n;
		cin >> n;
		ll arr[n];
		ll sum = 0;
		for (ll i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		ll p = game(arr, n, 0, n - 1);
		ll q = sum - p;
		cout << p - q << endl;
	}
	return 0;
}
