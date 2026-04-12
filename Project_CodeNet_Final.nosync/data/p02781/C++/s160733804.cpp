#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

//1からsentenceまでの内で、含まれている0以外の数がcontain_minからcontain_maxまでを計測する
int DigitDP(string sentence, int contain_min, int contain_max)
{
	int len = sentence.size();
	vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(2, vector<int>(contain_max + 1, 0)));
	vector<int> digit(len);

	for (int i = 0; i < len; i++)
	{
		digit[i] = sentence[i] - '0';
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < len; i++)
	{
		dp[i + 1][0][0] = (digit[i] == 0 ? dp[i][0][0] : 0);
		dp[i + 1][1][0] = dp[i][0][0] + dp[i][1][0];
		for (int j = 0; j < contain_max; j++)
		{
			dp[i + 1][0][j + 1] = (digit[i] != 0 ? dp[i][0][j] : dp[i][0][j + 1]);
			dp[i + 1][1][j + 1] = dp[i][1][j + 1] + (digit[i] != 0 ? dp[i][0][j] * (digit[i] - 1) + dp[i][0][j + 1] : 0) + dp[i][1][j] * 9;
		}
	}
	int re = 0;
	for (int i = contain_min; i <= contain_max; i++)
	{
		re += dp[len][0][i] + dp[len][1][i];
	}
	return re;
}

void execute()
{
	string N;
	int K;
	cin >> N;
	cin >> K;

	cout << DigitDP(N, K, K) << endl;
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