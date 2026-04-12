#include <bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;

int N;
ll A[MAXN];
ll dp[MAXN][2][2];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; ++i)
		cin>>A[i];
	for(int i = 0; i <= N; ++i)
	{
		dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = (ll)(-1e18);
	}

	if(N % 2 == 0)
	{
			dp[0][0][0] = 0;
			for(int i = 1; i <= N; ++i)
			{
					if(i % 2 == 0)
					{
							dp[i][1][0] = max(dp[i][1][0], dp[i-1][0][0] + A[i]);
							dp[i][0][0] = max(dp[i][0][0], dp[i-1][1][1]);
					}
					else
					{
						dp[i][0][0] = max(dp[i][0][0], dp[i-1][1][0]);
						dp[i][0][0] = max(dp[i][0][0], dp[i-1][0][0]);
						dp[i][1][1] = max(dp[i][1][1], dp[i-1][0][0] + A[i]);
					}
			}
		
	}
	else
	{
		dp[0][0][1] = 0;
			for(int i = 1; i <= N; ++i)
			{
					if(i % 2 == 0)
					{
							dp[i][0][0] = max(dp[i][0][0], dp[i-1][1][0]);
							dp[i][0][0] = max(dp[i][0][0], dp[i-1][0][0]);
							dp[i][0][1] = max(dp[i][0][1], dp[i-1][1][1]);
							dp[i][1][1] = max(dp[i][1][1], dp[i-1][0][0] + A[i]);
					}
					else
					{
						dp[i][0][0] = max(dp[i][0][0], dp[i-1][1][1]);
						dp[i][0][0] = max(dp[i][0][0], dp[i-1][0][1]);
						dp[i][1][0] = max(dp[i][1][0], dp[i-1][0][0] + A[i]);
						dp[i][1][1] = max(dp[i][1][1], dp[i-1][0][1] + A[i]);
					}
			}
	}
	if(N % 2 == 0)
		cout<<max(dp[N][1][0], dp[N][0][0])<<endl;
	else
		cout<<max(dp[N][0][0], dp[N][1][0])<<endl;
}
