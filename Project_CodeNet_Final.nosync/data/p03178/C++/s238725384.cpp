#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

string s;
int d;

int dp[10002][102][2];

int solve(int idx, int cur, int tight)
{
	if (idx == s.length())
	{
		return cur == 0;
	}

	int & ans = dp[idx][cur][tight];
	if (ans != -1) return ans;

	ans = 0;
	int end = tight ? s[idx] - '0' : 9;

	for (int i = 0; i <= end; i++)
	{
		ans += solve(idx + 1, (cur + i % d) % d, tight & (i == end));
		ans %= MOD;
	}

	return ans;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FASTIO;

	cin >> s;
	cin >> d;

	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0, 1);
	cout << (ans - 1 + MOD) % MOD;

}