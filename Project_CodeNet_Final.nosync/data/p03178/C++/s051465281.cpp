#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[2][110][100050];
int seen[2][110][100050];
string digit;
int D, l;

int solve(int id, int can, int r)
{
	if(id == l) return !r;
	int num = digit[id] - '0', ans = 0;
	if(seen[can][r][id]) return dp[can][r][id];
	for(int i = 0; i < 10; i++)
		if(can or i <= num)
			ans = (ans + solve(id + 1, can or i < num, (r + (i % D)) % D)) % 1000000007LL;
	seen[can][r][id] = 1;
	return dp[can][r][id] = ans;
}

int32_t main()
{
	cin >> digit >> D;
	l = digit.size();
	int ans = (solve(0, 0, 0) - 1) % 1000000007LL;
	if(ans < 0) ans += 1000000007LL;
	cout << ans << '\n';

	return 0;
}