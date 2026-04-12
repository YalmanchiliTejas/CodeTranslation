#include <bits/stdc++.h>
using namespace std;

struct state
{
	long long int first;
	long long int second;
	long long int move;
};

int main(void)
{
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0;i < n;i++)
		cin >> arr[i];

	vector<vector<struct state>> dp;

	for(int i = 0;i < n;i++)
	{
		vector<struct state> temp;
		for(int j = 0;j < n;j++)
		{
			struct state t;
			t.first = 0;
			t.second = 0;
			t.move = 0;
			temp.push_back(t);
		}
		dp.push_back(temp);
	}

	for(int i = 0;i < n;i++)
	{
		dp[i][i].first = arr[i];
		dp[i][i].second = 0;
		dp[i][i].move = i;
	}

	for(int l = 2;l <= n;l++)
	{
		for(int i = 0;i <= n-l;i++)
		{
			int j = i + l - 1;
			if(arr[i] + dp[i+1][j].second > arr[j] + dp[i][j-1].second)
			{
				dp[i][j].first = arr[i] + dp[i+1][j].second;
				dp[i][j].second = dp[i+1][j].first;
				dp[i][j].move = i;
			}
			else
			{
				dp[i][j].first = arr[j] + dp[i][j-1].second;
				dp[i][j].second = dp[i][j-1].first;
				dp[i][j].move = j;
			}
		}
	}

	cout << dp[0][n-1].first - dp[0][n-1].second;


	return 0;
}