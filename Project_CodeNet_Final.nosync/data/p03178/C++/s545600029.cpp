#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define ll long long
#define mod 1000000007
using namespace std;

string s;
//       position,sum,state 
int d, dp[100005][110][2];

// curpos , cursum , state
// base case: curpos = s.size()

int solve(int pos, int cursum, bool state)
{
	if (pos == s.size())
	{
		if (cursum % d == 0)return 1;
		else return 0;
	}
	if (dp[pos][cursum][state] != -1)return dp[pos][cursum][state];
	int tmp = 0;
	for (int i = 0; i < 10; i++)
	{
		if (state)
		{
			tmp = (tmp + solve(pos + 1, (cursum + i) % d, 1)) % mod;
		}
		else
		{
			if (i < s[pos] - '0')
			{
				tmp = (tmp + solve(pos + 1, (cursum + i) % d, 1)) % mod;
			}
			else if (i == s[pos] - '0')
			{
				tmp = (tmp + solve(pos + 1, (cursum + i) % d, 0)) % mod;
			}
		}
	}
	return dp[pos][cursum][state] = tmp;
}

int main()
{
	memset(dp, -1, sizeof dp);
	cin >> s >> d;
	cout << ((solve(0, 0, 0) - 1) + mod) % mod << '\n';
	return 0;
}