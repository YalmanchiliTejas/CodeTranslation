#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
	long long score[5050];
	long long dp[3050][3050];
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>score[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = score[i];
	}
	for (int k = 2; k <= n; k++)
	{
		for (int i = 1; i <= n + 1 - k; i++)
		{
			dp[i][i + k - 1] = max(score[i] - dp[i + 1][i + k - 1], score[i + k - 1] - dp[i][i + k - 1 - 1]);
		}	
	}
	cout<<dp[1][n];
	return 0;
}