#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<vector<long long>> DP;
vector <vector<long long>> DP2;
const long long inf = 10000000000007;

int main()
{
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i < n + 1; i++)
		cin >> a[i];

	// 2D DP array DP[i][j], taro's move (try to maximize)
	// 2D DP array DP2[i][j], jiro's move (try to minimize)
	// i is the one end of the deque, j is the other end
	// i, 1...n; j, 1...n
	DP.resize(n + 1); DP2.resize(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		DP[i].resize(n + 1, 0);
		DP2[i].resize(n + 1, 0);
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i == j) //last element
			{
				DP[i][j] += a[i];
				DP2[i][j] -= a[i];
			}
			else if (i == j - 1) // last 2 elements
			{
				DP[i][j] += abs(a[i] - a[j]);
				DP2[i][j] -= abs(a[i] - a[j]);
			}
			else if (i > j)
			{
				DP[i][j] = 0;
				DP2[i][j] = 0;
			}
			else // other i<j-1
			{
				// DP[i][j]
				// 1 - i, DP2[i+1][j]
				// 2 - j, DP2[i][j-1]
				// DP[i][j] = max(max(DP[i + 2][j] + a[i] - a[i + 1], DP[i + 1][j - 1] + a[i] - a[j]),max(DP[i + 1][j - 1] + a[j] - a[i], DP[i][j - 2] + a[j] - a[j - 1]));
				DP[i][j] = max(DP2[i + 1][j] + a[i], DP2[i][j - 1] + a[j]);
				DP2[i][j] = min(DP[i + 1][j] - a[i], DP[i][j - 1] - a[j]);
			}
		}
	}
	cout << DP[1][n] << endl;

}