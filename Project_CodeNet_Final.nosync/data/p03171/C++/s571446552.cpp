#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

const int nax = 3005;
ll dp[nax][nax];

int32_t main()
{
	int n;
	scanf("%lld",&n);
	vector<int> a(n);
	for(int& x : a)
	{
		scanf("%lld",&x);
	}
	for(int R=0;R<n;R++)
	{
		for(int L=R;L>=0;L--)
		{
			if(L == R)
			{
				dp[L][R] = a[L];
			}
			else
			{
				dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
			}
		}
	}
	printf("%lld\n",dp[0][n-1]);
	return 0;
}