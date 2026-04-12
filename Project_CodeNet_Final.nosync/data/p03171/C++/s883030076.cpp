#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 3005;
typedef long long ll;

int n,a[MAX_N];
ll dp[MAX_N][MAX_N][2];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",a+i);
	for (int s=1; s<=n; s++)
		for (int i=1; i+s-1<=n; i++)
		{
			int j=i+s-1;
			if (i==j)
			{
				dp[i][j][0]=a[i];
				dp[i][j][1]=-a[i];
			}
			else
			{
				dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
				dp[i][j][1]=min(-a[i]+dp[i+1][j][0],-a[j]+dp[i][j-1][0]);
			}
		}
	printf("%lld\n",dp[1][n][0]);
	return 0;
}
