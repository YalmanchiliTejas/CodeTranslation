#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()
#pragma endregion

int dp[110][2][110];

ll solver(string s, int x)
{
	int l = s.size();
	rep(i, 110)rep(j, 2)rep(k, 110)dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	rep(i, l)
	{
		int d = s[i] - '0';
		rep(j, 2)
		{
			rep(k, 105)
			{
				for (int m = 0; m <= (j ? 9 : d); ++m)
				{
					if (m == 0)dp[i + 1][j || (m < d)][k] += dp[i][j][k];
					else dp[i + 1][j || (m < d)][k + 1] += dp[i][j][k];
				}
			}
		}
	}
	return dp[l][0][x] + dp[l][1][x];
}

int main()
{
	string n; cin >> n;
	int k; cin >> k;
	cout << solver(n, k) << endl;
}