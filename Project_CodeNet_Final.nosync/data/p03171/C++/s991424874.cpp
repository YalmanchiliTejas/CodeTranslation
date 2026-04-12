#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int main()
{
	int a; cin >> a;
	lli arr[a + 50], dp[a + 50][a + 50];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=a; i++)
	{
		cin >> arr[i];
		dp[i][i] = arr[i];
	}
	for(int i=2; i<=a; i++)
	{
		for(int j=1; j + i - 1 <= a; j++)
		{
			int l = j, r = j + i - 1;
			dp[l][r] = max(arr[l] - dp[l + 1][r], arr[r] - dp[l][r - 1]);
		}
	}
	cout << dp[1][a] << '\n';
	return 0;
}