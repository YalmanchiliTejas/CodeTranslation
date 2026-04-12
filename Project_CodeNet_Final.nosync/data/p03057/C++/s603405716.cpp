#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200100;
const int mod = 1e9 + 7;
const int oo = 1e9;
long long power(long long x, long long k)
{
	long long ans = 1;
	while(k)
	{
		if(k & 1)
			(ans *= x) %= mod;
		k >>= 1;
		(x *= x) %= mod;
	}
	return ans;
}
int n, m;
char s[maxn];
int l = oo;
long long ans = 0;
long long dp[maxn][2][2] = {0}, h[maxn][2][2] = {0}, f[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++)
		cin >> s[i];
	while(s[m] == s[1] && m >= 1)
		m --;
	if(m != 0)
	{
		int len;
		for(len = 1; len <= m && s[len] == s[1]; len ++);
		len --;
		if(len & 1)
			l = min(l, len);
		else
			l = min(l, len + 1);
		int now = 0;
		for(int i = len + 2; i <= m; i ++)
		{
			if(s[i] != s[1])
			{
				if(now & 1)
					l = min(l, now);
				now = 0;
			}
			else
				now ++;
		}
	}
	if(m == 0)
	{
		f[0] = 2;
		f[1] = 1;
		for(int i = 2; i <= n; i ++)
			f[i] = (f[i - 1] + f[i - 2]) % mod;
		cout << f[n] << endl;
		return 0;
	}
	if(n & 1)
	{
		cout << 0 << endl;
		return 0;
	}
	n >>= 1;
	l >>= 1;
	//cout << n << " " << l << endl;
	dp[1][0][0] = h[1][0][0] = 1;
	dp[1][1][1] = h[1][1][1] = (l > 0);
	//dp[0][0][0] = dp[0][1][1] = h[0][0][0] = h[0][1][1] = 1;
	for(int i = 2; i <= n; i ++)
	{
		//cout << i << " : " << endl;
		dp[i][0][0] = (dp[i - 1][0][1] + dp[i - 1][0][0]) % mod;
		dp[i][0][1] = (h[i - 1][0][0] - h[max(0, i - l - 1)][0][0] + mod) % mod;
		dp[i][1][0] = (dp[i - 1][1][1] + dp[i - 1][1][0]) % mod;
		dp[i][1][1] = (h[i - 1][1][0] - h[max(0, i - l - 1)][1][0] + mod) % mod;
		if(i <= l)
			dp[i][1][1] ++;
		for(int asd1 = 0; asd1 < 2; asd1 ++)
			for(int asd2 = 0; asd2 < 2; asd2 ++)
				h[i][asd1][asd2] = (h[i - 1][asd1][asd2] + dp[i][asd1][asd2]) % mod;
		//cout << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << endl;
		//cout << h[i][0][0] << " " << h[i][0][1] << " " << h[i][1][0] << " " << h[i][1][1] << endl;
	}
	for(int i = 1; i <= min(l, n); i ++)
		dp[i][1][1] --;
	long long ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		(ans += (n - i) * dp[i][1][1]) %= mod;
		if(i <= l && n - i > 1)
			(ans += (n - i)) %= mod;
		if(n - i <= l && i >= 2)
			(ans += (n - i) * dp[i][0][0]) %= mod;
		//cout << i << " " << ans << endl;
	}
	ans ++;
	//cout << ans << endl;
	if((l >= n - 1) && n != 1)
		ans += n;
	cout << (ans * 2 + (m == 0 && n != 1)) % mod << endl;
	return 0;
}
/*
1 3
BBB
*/