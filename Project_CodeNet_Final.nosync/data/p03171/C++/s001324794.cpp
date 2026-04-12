#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const long long INF=0x3f3f3f3f3f3f3f3f;
int n,k;
long long a[3005],dp[3005][3005];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) dp[i][i]=a[i];
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	}
	printf("%lld\n",dp[1][n]);
}