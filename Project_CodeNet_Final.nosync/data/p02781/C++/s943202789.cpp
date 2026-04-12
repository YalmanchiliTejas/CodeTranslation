#include <bits/stdc++.h>
using namespace std;

#define int long long

int k, dp[105][2][105];
string digit;

int digitdp(int id, bool can, int sum)
{
	if(id == digit.size())
	{
		if(sum == k)
			return 1;

		return 0;
	}

	if(dp[id][can][sum] != -1)
		return dp[id][can][sum];

	int d = digit[id] - '0';

	int ans=0;
	for(int i=0; i<10; i++)
		if(i<=d or can)
			ans += digitdp(id+1, i<d or can, sum+(i!=0));

	return dp[id][can][sum] = ans;
}

int32_t main()
{
	cin >> digit >> k;

	memset(dp, -1, sizeof(dp));

	digitdp(0,0,0);

	cout << dp[0][0][0] << '\n';
}