#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>
#include <cmath>
using namespace std;


const int N = 10000 + 1;
const int M = 100 + 1;

long long dp[N][M][2] = { 0 };

const long long mod = 1e+9 + 7;

void solve()
{
	string s;
	cin >> s;

	int d;
	cin >> d;

	int n = (int)s.length();

	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < d; k++)
		{
			for (int j = 0; j < 2; j++)
			{
				int digit = 9;

				if (j == 0)
				{
					digit = s[i] - '0';
				}

				for (int x = 0; x <= digit; x++)
				{
					int y = j;

					if (x < s[i] - '0')
					{
						y = 1;
					}

					dp[i + 1][(k + x) % d][y] += dp[i][k][j];
					dp[i + 1][(k + x) % d][y] %= mod;
				}
			}
		}
	}

	long long ans = (dp[n][0][0] + dp[n][0][1]) % mod;
	ans = (ans + mod - 1) % mod;
	cout << ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("file.in", "r", stdin);//freopen("file.out", "w", stdout);

	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}