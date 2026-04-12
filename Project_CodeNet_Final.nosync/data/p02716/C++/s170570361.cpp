#include <bits/stdc++.h>
 
using namespace std;

long long int dp[2][200001];
int n;
long long int t;
vector <long long int> v;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		v.push_back(t);
	}

	fill(dp[0],dp[0]+200001,-1e18);
	fill(dp[1],dp[1]+200001,-1e18);
	if(n%2==0)
	{
		long long int res = -1e18;
		dp[0][0] = v[0];
		dp[0][1] = v[1];
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
			{
				if(i + 2 < n)
				{
					dp[0][i+2] = max(dp[0][i+2],dp[0][i] + v[i+2]);
				}
				if(i + 3 < n)
				{
					dp[0][i+3] = max(dp[0][i+3],dp[0][i] + v[i+3]);
				}
			}
			else
			{
				if(i + 2 < n)
				{
					dp[0][i+2] = max(dp[0][i+2],dp[0][i] + v[i+2]);
				}
			}
		}
		res = max(dp[0][n-1],dp[0][n-2]);
		cout << res << '\n';
	}
	else
	{
		long long int res = -1e18;
		dp[0][0] = v[0];
		dp[0][1] = v[1];
		dp[0][2] = v[2];
		dp[1][0] = v[0];

		for(int i=0;i<n;i++)
		{
			if(i%2==1)
			{
				if(i + 2 < n)
				{
					dp[0][i+2] = max(dp[0][i+2],dp[0][i] + v[i+2]);
				}
				if(i + 3 < n)
				{
					dp[0][i+3] = max(dp[0][i+3],dp[0][i] + v[i+3]);
				}
			}
			else
			{
				if(i!=0)
				{
					if(i+2 < n)
					{
						dp[0][i+2] = max(dp[0][i+2],dp[0][i] + v[i+2]);
					}
					if(i!=n-3)
					{
						if(i+2 < n)
						{
							dp[1][i+2] = max(dp[1][i+2],dp[1][i] + v[i+2]);
						}
					}
					if(i+3 < n)
					{
						dp[0][i+3] = max(dp[0][i+3],dp[1][i] + v[i+3]);
					}
					if(i+4 < n)
					{
						dp[0][i+4] = max(dp[0][i+4],dp[1][i] + v[i+4]);
					}
				}
				else
				{
					if(i!=n-3)
					{
						if(i+2 < n)
						{
							dp[1][i+2] = max(dp[1][i+2],dp[1][i] + v[i+2]);
						}
					}
					if(i+3 < n)
					{
						dp[0][i+3] = max(dp[0][i+3],dp[1][i] + v[i+3]);
					}
					if(i+4 < n)
					{
						dp[0][i+4] = max(dp[0][i+4],dp[1][i] + v[i+4]);
					}
				}
			}
		}
		res = max(dp[1][n-3],max(dp[0][n-1],dp[0][n-2]));
		cout << res << '\n';

	}

	return 0;	
}
