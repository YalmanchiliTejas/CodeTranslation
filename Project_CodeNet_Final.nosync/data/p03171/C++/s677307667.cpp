
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <array>
#include <map>
#include <cstring>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctgmath>
#include <set>
#include <queue>
#include <fstream>
#include <ostream>
#include <list>
#include <string>
using namespace std;

#define MOD 1000000007
#define int long long
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> seq;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		seq.push_back(a);
	}

	vector<pair<int, int>> temp(n);
	vector<vector<pair<int, int>>> dp(n, temp);

	for (int i = 0; i < n; i++) 
	{
		dp[i][i].first = seq[i];
	}

	for (int l = 2; l <= n; l++) 
	{
		for (int i = 0; i <= n - l; i++) 
		{
			int j = i + l - 1;
			if (seq[i] + dp[i + 1][j].second > dp[i][j - 1].second + seq[j]) {
				dp[i][j].first = seq[i] + dp[i + 1][j].second;
				dp[i][j].second = dp[i + 1][j].first;
			}
			else {
				dp[i][j].first = seq[j] + dp[i][j - 1].second;
				dp[i][j].second = dp[i][j - 1].first;

			}
		}
	}
	cout << dp[0][n-1].first - dp[0][n-1].second << "\n";
}
