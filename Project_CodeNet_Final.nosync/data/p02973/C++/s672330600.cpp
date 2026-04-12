#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int INF = 1000000010;

int n;

int v[MAXN];
int dp[MAXN];

int main()
{
	scanf("%d",&n);

	for(int i = n ; i > 0 ; i--)
		scanf("%d",&v[i]);

	for(int i = 1 ; i <= n ; i++)
		dp[i] = INF;

	int ans = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		int ind = upper_bound( dp , dp + n + 1 , v[i] ) - dp;

		dp[ind] = v[i];
		ans = max( ans , ind );
	}

	printf("%d\n",ans);
}