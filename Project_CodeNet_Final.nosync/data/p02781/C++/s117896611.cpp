#include<bits/stdc++.h>

using namespace std;

string S;
int K;
int N;
int dp[110][5][2];

int main()
{
	cin>>S>>K;
	
	N = S.length();
	dp[0][0][1] = 1;
	
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j <= K; j ++)
		{
			int Num = S[i] - '0';
			
			if(Num == 0)
			{
				dp[i + 1][j][0] += dp[i][j][0];
				dp[i + 1][j][1] += dp[i][j][1];
				dp[i + 1][j + 1][0] += (dp[i][j][0] * 9);
			}
			else
			{
				dp[i + 1][j][0] += (dp[i][j][0] + dp[i][j][1]);
				dp[i + 1][j + 1][0] += (dp[i][j][0] * 9);
				dp[i + 1][j + 1][0] += (dp[i][j][1] * (Num - 1));
				dp[i + 1][j + 1][1] += dp[i][j][1];
			}
		}
	}
	
	cout<<dp[N][K][0] + dp[N][K][1]<<endl;
	return 0;
}