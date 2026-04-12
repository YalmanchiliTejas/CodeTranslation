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


const int maxn = 3000 + 2;

long long dp[maxn][maxn][2];

vector<long long> a;

void solve()
{
	int n;
	cin >> n;

	a.resize(n);


	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}

	for (int l = 2; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++)
		{
			int j = i + l - 1;

			dp[i][j][0] = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j]);

			dp[i][j][1] = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j]);

			//cout << i << " " << j << " " << dp[i][j][0] << "\n";
			//cout << i << " " << j << " " << dp[i][j][1] << "\n";
			//cout << "\n";
		}
	}

	cout << dp[0][n - 1][0];

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