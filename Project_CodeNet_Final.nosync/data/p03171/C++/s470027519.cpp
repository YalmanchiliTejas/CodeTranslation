#include<bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

int main()
{


	ll n;
	cin >> n;
	ll arr[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	ll dp[n][n];
	for (int L = n - 1ll; L >= 0ll; L--)
	{
		for (int R = L; R < n; R++)
		{
			if (L == R)
			{
				dp[L][R] = arr[L];
			}
			else
			{
				dp[L][R] = max(arr[L] - dp[L + 1][R] , arr[R] - dp[L][R - 1]);
			}
		}
	}

	cout << dp[0][n - 1];
}