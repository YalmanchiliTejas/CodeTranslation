#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[1010][1010];
#define SIZE 2000000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
int main()
{
	int num, a, b, c, d;
	scanf("%d%d%d%d%d", &num, &a, &b, &c, &d);
	invinit();
	dp[0][0] = 1;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= mod;
		}
		if (a <= i&&i <= b)
		{
			for (int j = 0; j <= num; j++)
			{
				ll now = 1;
				for (int k = 1; k <= d && j + k*i <= num; k++)
				{
					now = now*com((num - j) - (k - 1)*i, i) % mod*inv[k] % mod;
					if (c <= k)
					{
						dp[i][j + k*i] += dp[i - 1][j] * now;
						dp[i][j + k*i] %= mod;
					}
				}
			}
		}
		//for (int j = 0; j <= num; j++)printf("%lld ", dp[i][j]); printf("\n");
	}
	printf("%lld\n", dp[num][num]);
}