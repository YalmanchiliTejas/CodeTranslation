#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

const int MAXN = 3010;
const int MOD = 998244353;

int n, s;

int v[MAXN];

lli ans;

lli dp[MAXN][2];
lli sumDp[MAXN][2];

void knapsack(int l, int r, int ind)
{
	for(int k = 0 ; k <= s ; k++)
	{
		dp[k][ind] = 0;
		sumDp[k][ind] = 0;
	}

	dp[0][ind] = 1;

	int c = ( l <= r ) ? 1 : -1;

	for(int i = l ; i != r + c ; i += c)
	{
		for(int k = s ; k >= v[i] ; k--)
		{
			dp[k][ind] += dp[ k - v[i] ][ind];
			dp[k][ind] %= MOD;
		}

		for(int k = 0 ; k <= s ; k++)
		{
			sumDp[k][ind] += dp[k][ind];
			sumDp[k][ind] %= MOD;
		}
	}
}

void DivAndConquer(int l, int r)
{
	if( l > r ) return;

	if( l == r )
	{
		if( v[l] == s ) ans++;
		return;
	}

	int mid = ( l + r )/2;

	DivAndConquer( l , mid );
	DivAndConquer( mid + 1 , r );

	knapsack( mid , l , 0 );
	knapsack( mid + 1 , r , 1 );

	for(int k = 0 ; k <= s ; k++)
	{
		ans += sumDp[k][0]*sumDp[s - k][1];
		ans %= MOD;
	}
}

int main()
{
	scanf("%d %d",&n,&s);

	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&v[i]);

	DivAndConquer( 1 , n );

	printf("%lld\n",ans);
}