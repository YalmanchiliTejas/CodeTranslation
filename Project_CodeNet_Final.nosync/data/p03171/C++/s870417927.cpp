#include <bits/stdc++.h>
using namespace std;
#define maxn (int)3010
#define int long long
int tab[maxn], dp[maxn][maxn][3], n;
bool odw[maxn][maxn][3];

int rob(int start, int stop, int kto)
{
	if (odw[start][stop][kto]) return dp[start][stop][kto];
	odw[start][stop][kto]=true;
	//printf("Przedzial %lld %lld %lld\n", start, stop, kto);
	if (kto==1)
	{
		if (start==stop) 
		{
			dp[start][stop][kto]=tab[stop]*(-1);
			//printf("DLa przedzialu %lld %lld %lld mamy %lld\n", start, stop, kto, dp[start][stop][kto]);
			return dp[start][stop][kto];
		}
		dp[start][stop][kto]=min(rob(start, stop-1, 2)-tab[stop], rob(start+1, stop, 2)-tab[start]);
		//printf("DLa przedzialu %lld %lld %lld mamy %lld\n", start, stop, kto, dp[start][stop][kto]);
		return dp[start][stop][kto];
	}
	else
	{
		if(start==stop)
		{
			dp[start][stop][kto]=tab[stop];
			//printf("DLa przedzialu %lld %lld %lld mamy %lld\n", start, stop, kto, dp[start][stop][kto]);
			return dp[start][stop][kto];
		}
		dp[start][stop][kto]=max(rob(start, stop-1, 1)+tab[stop], rob(start+1, stop, 1)+tab[start]);
		//printf("DLa przedzialu %lld %lld %lld mamy %lld\n", start, stop, kto, dp[start][stop][kto]);
		return dp[start][stop][kto];
	}
}

int32_t main()
{
	scanf("%lld", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
	}
	rob(1, n, 2);
	printf("%lld", dp[1][n][2]);
}
