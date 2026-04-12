#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define itn int
#define gI gi
#define int long long 

using namespace std;

inline int gi()
{
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

int k, len, ans, c[103][103], dp[10003][5][3];
char s[10003];
string ss;

int dfs(int x, int y, int z)
{
	if (y > k) return 0;
	if (x > len) return y == k;
	if (dp[x][y][z] != -1) return dp[x][y][z];
	int kk = (z == 1) ? (s[x] - '0') : 9, sum = 0;
	for (int i = 0; i <= kk; i+=1)
		sum += dfs(x + 1, y + (i != 0), z && (i == kk));
	 return dp[x][y][z] = sum;
}

signed main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	scanf("%s", s + 1);
	memset(dp, -1, sizeof(dp));
	k = gi();
	len = strlen(s + 1);
	printf("%lld\n", dfs(1, 0, 1));
	return 0;
}

