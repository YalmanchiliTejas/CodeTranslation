#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

inline int gi()
{
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

inline LL gl()
{
	LL f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 3003, mod = 998244353;

int n, m;
int a[N];
LL dp[N][N][3];

int main()
{
	//File("");
	n = gi(), m = gi();
	for (int i = 1; i <= n; i+=1) a[i] = gi();
	dp[1][0][0] = 1;
	for (int i = 1; i <= n; i+=1)
	    for (int j = 0; j <= m; j+=1)
	    {
	        dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][0]) % mod;
	        dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][0] + dp[i][j][1]) % mod;
	        dp[i + 1][j][2] = (dp[i + 1][j][2] + dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) % mod;
	        if (j + a[i] <= m)
	            (dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod,
	            (dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
	    }
	printf("%lld\n", dp[n + 1][m][2] % mod);
	return 0;
}
