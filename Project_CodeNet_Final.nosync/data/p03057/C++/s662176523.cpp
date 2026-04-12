#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define SIZE 262144
typedef long long ll;
ll mod = 1000000007;
class BIT
{
public:
	ll bit[SIZE + 1];
	void add(int a, ll b)
	{
		a+=120000;
		for (;;)
		{
			bit[a] += b;
			bit[a] %= mod;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	ll get(int a)
	{
		a+=120000;
		ll ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret%mod;
		}
	}
};
BIT bi;
ll dp[202020];
ll sub[2][202020][2];
int main()
{
	int num, len;
	scanf("%d%d", &num, &len);
	string s;
	cin >> s;
	if (s[0] == 'B')
	{
		for (int i = 0; i < s.size(); i++)s[i] = 'R' + 'B' - s[i];
	}
	int mini = 1000000000, cnt = 0;
	bool ff = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'R')cnt++;
		else
		{
			if (!ff)
			{
				if (cnt % 2 == 0)mini = min(mini, cnt + 1);
				else mini = min(mini, cnt);
				ff = true;
			}
			else if (cnt % 2 == 1)mini = min(mini, cnt);
			cnt = 0;
		}
	}
	if (!ff)
	{
		sub[0][0][0] = sub[1][0][1] = 1;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j < num; j++)
			{
				sub[i][j][0] = (sub[i][j - 1][0] + sub[i][j - 1][1]) % mod;
				sub[i][j][1] = sub[i][j - 1][0];
			}
		}
		ll r = sub[0][num - 1][0] + sub[0][num - 1][1] + sub[1][num - 1][0];
		printf("%lld\n", r%mod);
		return 0;
	}
	if (num % 2 == 1)
	{
		printf("0\n");
		return 0;
	}
	mini = (mini + 1) / 2;
	num /= 2;
	mini = min(mini, num);
	dp[0] = 1;
	bi.add(0, 1);
	for (int i = 1; i <= num; i++)
	{
		dp[i] = (bi.get(i - 1) - bi.get(i - mini - 1) + mod) % mod;
		bi.add(i, dp[i]);
		//printf("%d %lld\n", i, dp[i]);
	}
	ll r = 0;
	for (int i = 1; i <= mini; i++)r = (r + dp[num - i] * i * 2) % mod;
	printf("%lld\n", r);
}