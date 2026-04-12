#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 100;
const int MOD = 1e9 + 7;

int dp[MAX][2][105];
string s;
int d;

inline int add(int a, int b)
{
	int r = a + b;
	if(r >= MOD)
		r -= MOD;
	return r;
}

inline int sub(int a, int b)
{
	int r = a - b;
	if(r < 0)
		r += MOD;
	return r;
}

int dp_solve(int idx, bool lim, int mod)
{
	if(idx == (int) s.size())
		return (int) mod == 0;

	int &ans = dp[idx][lim][mod];
	if(~ans) return ans;
	ans = 0;
	int limit = lim ? 9 : s[idx] - '0';
	for(int i = 0; i <= limit; i++)
		ans = add(ans, dp_solve(idx+1, lim || i < s[idx] - '0', (mod + i) % d));
	return ans;
}

int main()
{
	cin >> s >> d;
	memset(dp, -1, sizeof dp);
	cout << sub(dp_solve(0, 0, 0), 1) << endl;

	return 0;
}
