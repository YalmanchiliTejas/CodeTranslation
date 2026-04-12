#include <iostream>
#include <set>
#include <string>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
	ll i,j,k;
	ll N,M,T;
	ll p[200] = {0};
	string S;
	cin >> S;
	ll s_len = S.size();
	ll dp[128][4] = {0};
	for(i = 0; i< s_len; ++ i)
	{
		p[i] = (int)(S[s_len-i-1]-'0');
	}
	cin >> N;
	dp[0][0] = 1;
	dp[0][1] = 9;
	dp[0][2] = 0;
	dp[0][3] = 0;
	for(i=1;i<s_len;++i)
	{
		dp[i][0] = 1;
		dp[i][1] = dp[i-1][1] + dp[i-1][0]*9;
		dp[i][2] = dp[i-1][2] + dp[i-1][1]*9;
		dp[i][3] = dp[i-1][3] + dp[i-1][2]*9;
	}

	ll ans;
	if(s_len > 1)
	{
		ans = dp[s_len-2][N];
		ans += dp[s_len-2][N-1]*(p[s_len-1]-1);
		k = 1;
		for(i=1;i<N;++i,++k)
		{
			if(s_len-2-k < 0)
			{
				if(N-i-1 == 0)
					ans += p[s_len-k-1];
				break;
			}
			if(p[s_len-k-1] == 0)
			{
				--i;
				continue;
			}
			ans += dp[s_len-2-k][N-i];
			ans += dp[s_len-2-k][N-i-1]*(p[s_len-k-1]-1);
		}
		if(i == N)
			ans ++;
	}
	else
	{
		if(N==1)
			ans = p[0];
		else
			ans = 0;
	}
	cout << ans << endl;
	return 0;
}