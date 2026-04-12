#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int dp[10010][2][128];

void solve()
{
	string K;
	int D;
	cin >> K >> D;

	int N = K.size();

	dp[0][1][0] = 1;

	for (int i = 0; i < N; i++)
	{
		int d = K[i] - '0';
		for (int f = 0; f < 2; f++)
			for (int m = 0; m < D; m++)
				for (int nd = 0; nd <= (f ? d : 9); nd++)
				{
					dp[i + 1][f & (nd == d)][(m + nd) % D] += dp[i][f][m];
					dp[i + 1][f & (nd == d)][(m + nd) % D] %= MOD;
				}
	}

	cout << (dp[N][0][0] + dp[N][1][0] + MOD - 1) % MOD << endl;

}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
