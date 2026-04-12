#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 1005;
const int md = 1e9+7;

void add(int &a, int b)
{
	a += b;
	if(a>= md) a-= md;
}

int mul(int a, int b)
{
	return (1LL*a*b)%md;
}

int bin(int a, int b)
{
	if(b == 0) return 1;
	int x = bin(a, b/2);
	int y = mul(x, x);
	if(b%2) y = mul(y, a);
	return y;
}

int inv(int a)
{
	return bin(a, md-2);
}

int fac[maxn];
int invfac[maxn];

int dp[maxn][maxn];
int n, a, b, c, d;

int f(int i, int a, int k)
{
	int res = fac[i];
	res = mul(res, invfac[i-k*a]);
	res = mul(res, bin(invfac[a], k));
	res = mul(res, invfac[k]);
	return res;
}

int main()
{
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	fac[0] = invfac[0] = 1;
	for(int i = 1; i<= n; i++)
	{
		fac[i] = mul(fac[i-1], i);
		invfac[i] = mul(invfac[i-1], inv(i));
	}
	for(int i = a-1; i<= b; i++) dp[0][i] = 1;
	for(int i = 1; i<= n; i++)
	{
		for(int j = a; j<= b; j++)
		{
			add(dp[i][j], dp[i][j-1]);
			for(int k = c; i-k*j>= 0 && k<= d; k++)
			{
				add(dp[i][j], mul(dp[i-k*j][j-1], f(i, j, k)));
				// printf("f(%d, %d) = %d\n", j, k, f(i, j, k));
			}
			// printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
	}
	printf("%d\n", dp[n][b]);
}