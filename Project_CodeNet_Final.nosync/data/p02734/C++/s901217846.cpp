#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
int main()
{
	// Time Complexity: O(NS) Space Complexity: O(S)
	int n, s, mod(998244353);
	cin >> n >> s;
	int a[3000];
	for (int i = 0; i < n; ++i) cin >> a[i];

	ll ans = 0;

	//dp - the sum of left endpoints of all subsequences with weight j that end at i
	vector<ll> dp(s + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		dp[0]++;
		for (int j=s; j >= a[i-1]; --j)
		{
			dp[j] = (dp[j] + dp[j - a[i-1]]) % mod;
		}
		ans = (ans + dp[s]) % mod;
	}



	cout << ans;
	return 0;
}