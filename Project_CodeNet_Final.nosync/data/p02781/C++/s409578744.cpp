#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	string N;
	int K;
	cin >> N;
	cin >> K;

	int len = N.size();

	vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(2, vector<int>(4, 0)));
	vector<int> digit(len);
	for (int i = 0; i < len; i++)
	{
		digit[i] = N[i] - '0';
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < len; i++)
	{
		dp[i + 1][0][0] = (digit[i] == 0 ? dp[i][0][0] : 0);
		dp[i + 1][0][1] = (digit[i] == 0 ? dp[i][0][1] : dp[i][0][0]);
		dp[i + 1][0][2] = (digit[i] == 0 ? dp[i][0][2] : dp[i][0][1]);
		dp[i + 1][0][3] = (digit[i] == 0 ? dp[i][0][3] : dp[i][0][2]);
		dp[i + 1][1][0] = dp[i][0][0] + dp[i][1][0];
		dp[i + 1][1][1] = dp[i][1][1] + (digit[i] != 0 ? dp[i][0][0] * (digit[i] - 1) + dp[i][0][1] : 0) + dp[i][1][0] * 9;
		dp[i + 1][1][2] = dp[i][1][2] + (digit[i] != 0 ? dp[i][0][1] * (digit[i] - 1) + dp[i][0][2] : 0) + dp[i][1][1] * 9;
		dp[i + 1][1][3] = dp[i][1][3] + (digit[i] != 0 ? dp[i][0][2] * (digit[i] - 1) + dp[i][0][3] : 0) + dp[i][1][2] * 9;
	}
	cout << dp[len][0][K] + dp[len][1][K] << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}