#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Mod = 1e9 + 7;
string s;
int d;

int dp[10005][105][2];

int solve(int idx, int mod, bool smaller)
{
	if(idx == s.size())
		return mod == 0;
	int &ans = dp[idx][mod][smaller];
	if(~ans)
		return ans;
	ans = 0;
	for(int v = 0; v <= 9; v++)
	{
		if(!smaller && v > s[idx] - '0')
			continue;
		ans = (ans + solve(idx + 1, (mod + v) % d, smaller | v < s[idx] - '0')) % Mod;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s >> d;
	memset(dp, -1, sizeof dp);
	cout << (solve(0, 0, 0) - 1 + Mod) % Mod;
	return 0;
}
