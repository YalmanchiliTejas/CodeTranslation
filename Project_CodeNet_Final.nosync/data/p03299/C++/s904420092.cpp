#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 105;
const ll MOD = 1000000007;

int n;
int h[MAXN];

ll f[MAXN][MAXN][2];

bool vis[MAXN][MAXN][2];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

ll dfs(int l,int r,bool fl)
{
	if (l > r)
		return fl;
	if (vis[l][r][fl])
		return f[l][r][fl];
	vis[l][r][fl] = 1;
	int H = max(h[l - 1],h[r + 1]),MN = 1e9;
	ll res = 1;
	for (int i = l;i <= r;i++)
		MN = min(MN,h[i]);
	int lst = l;
	for (int i = l;i <= r;i++)
		if (h[i] == MN)
		{
			(res *= dfs(lst,i - 1,1)) %= MOD;
			lst = i + 1;
		}
	f[l][r][1] = res * dfs(lst,r,1) * 2 % MOD;
	lst = l;
	res = 1;
	for (int i = l;i <= r;i++)
		if (h[i] == MN)
		{
			(res *= (dfs(lst,i - 1,0) + dfs(lst,i - 1,1) * ((i - 1 >= lst) + 1)) * 2) %= MOD;
			lst = i + 1;
		}
	f[l][r][0] = (res * (dfs(lst,r,0) + dfs(lst,r,1) * ((r >= lst) + 1)) - f[l][r][1]) % MOD;
	(f[l][r][1] *= power(2,MN - H - 1)) %= MOD;
	return f[l][r][fl];
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&h[i]);
	printf("%lld\n",(dfs(1,n,0) + dfs(1,n,1) + MOD + MOD) % MOD);
	return 0;
}