#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const ll MINF = 1000000007;

ll dp[10001][2][101];

int main()
{
	memset(dp,0,10001*2*101*sizeof(ll));
	string N;
	cin >> N;
	ll n = N.size();
	ll d;
	cin >> d;
	dp[0][0][0] = 1;
	for(int i = 1;i <= n;++i)
	{
		for(int j=0;j<d;j++)
		{
			for(char c = '0';c<='9' ; c++)
			{
				if(N[i-1]>c)
				{
					dp[i][1][(j+(c-'0'))%d] =(dp[i][1][(j+(c-'0'))%d]+ dp[i-1][0][j])%MINF;
				}
				else if(N[i-1]==c)
				{
					dp[i][0][(j+(c-'0'))%d] = (dp[i][0][(j+(c-'0'))%d] + dp[i-1][0][j])%MINF;
				}
				dp[i][1][(j+(c-'0'))%d] = (dp[i][1][(j+(c-'0'))%d]+dp[i-1][1][j])%MINF;
				
			}
		}
	}

	cout<<((dp[n][1][0]+dp[n][0][0])-1+MINF)%MINF<<endl;

	return 0;
}