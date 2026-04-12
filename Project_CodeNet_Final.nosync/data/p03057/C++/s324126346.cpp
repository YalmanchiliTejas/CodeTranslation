#include <bits/stdc++.h>

using namespace std;

int n,m;
char str[200050];
const int mod = 1000000007;
int dp[200050];

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str + 1);
	bool c1 = 0,c2 = 0;
	for(int i = 1;i <= m; ++ i)
	{
		c1 |= str[i] == 'R';
		c2 |= str[i] == 'B';
	}
	int p = 1;
	int lim;
	if(c1 && c2)
	{
		if(n & 1)
		{
			printf("0\n");
			return 0;
		}
		for(;str[p + 1] == str[1]; ++ p);
		lim = p + (p % 2 == 0);
		int len = 0;
		for(int i = p + 1;i <= m; ++ i)
		{
			if(str[i] != str[1]) lim = min(lim,len % 2 ? len : 10000000),len = 0;
			else len ++;
		}
		lim ++;
		lim /= 2;
		lim = min(lim,n / 2);
		int pre = 1;
		int cur = 0;
		dp[0] = 1;
		long long ans = 0;
		for(int i = 0;i <= n / 2; ++ i)
		{
			if(i)
			{
				while(i - cur > lim) pre -= dp[cur],pre = (pre + mod) % mod,cur ++;
				dp[i] = pre;
				pre += dp[i];
				pre %= mod;
			}
			if(n - i * 2 > 0 && (n - i * 2) / 2 <= lim)
				ans = ans + 1LL * (n - i * 2) * dp[i] % mod,ans %= mod;
		}
		printf("%lld\n",ans);
	}
	else
	{
		int pre = 0;
		int cur = 0;
		dp[0] = 1;
		long long ans = 0;
		for(int i = 0;i <= n; ++ i)
		{
			if(i > 0)
			{
				dp[i] = pre;
				pre += dp[i - 1];
				pre %= mod;
			}
			if(n - i > 1)
				ans = ans + 1LL * (n - i) * dp[i] % mod,ans %= mod;
		}
		printf("%lld\n",(ans + 1) % mod);
	}
}