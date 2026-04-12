#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define all(f) (f).begin(),(f).end()
#define allr(f) (f).rbegin(),(f).rend()
const int mod = 1e9+7, A = 1e4+5;
string k;
int d, memo[A][105][2];
int dp(int ind, int sum, bool rem)
{
	if (ind == (int)k.size())
		return (sum ? 0 : 1);
	int &ans = memo[ind][sum][rem];
	if (~ans)
		return ans;
	ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		int cur_ind = k[ind] - '0', cur_sum = (sum + i) % d;
		if (rem == 1)
			ans = (ans + dp(ind + 1, cur_sum, 1)) % mod;
		else
		{
			if (i > cur_ind)
				continue;
			ans = (ans + dp(ind + 1, cur_sum, (i == cur_ind ? 0 : 1))) % mod;
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> k >> d;
	memset(memo, -1, sizeof memo);
	cout << (dp(0, 0, 0) - 1 + mod) % mod;
	return 0;
}
