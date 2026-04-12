#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<cstring>
#include<vector>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<functional>
#define io ios::sync_with_stdio(false)
#define inf 0x3f3f3f3f
#define ll long long
#define P pair<int,int>
#define lc rt*2
#define rc rt*2+1
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;

using namespace std;

string s;

ll dp[105][5][2];

int main()
{
	int k;
	cin >> s >> k;
	int len = s.size();
	dp[len - 1][1][0] = s[len-1] - '0';
	dp[len - 1][1][1] = 9;
	for (int i = len - 1; i >= 0; i--)
		dp[i][0][1] = dp[i][0][0] = 1;
	for (int i = len-2; i >= 0; i--)
		for (int j = 1; j <= k; j++)
		{
			dp[i][j][1] = dp[i + 1][j][1] + dp[i + 1][j - 1][1] * 9;
			if (s[i] - '0')
				dp[i][j][0] = dp[i + 1][j - 1][1] * (s[i] - '1') + dp[i + 1][j - 1][0] + dp[i + 1][j][1];
			else
				dp[i][j][0] = dp[i + 1][j][0];
		}
	cout << dp[0][k][0];
	return 0;
 }