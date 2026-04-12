#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
#define endl '\n'
#define F first
#define S second
const int MAX_N=3e3+3;

int n;
int a[MAX_N];
ll dp[MAX_N][MAX_N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int d=1,j;d<=n;d++) for(int i=1;i+d-1<=n;i++)
	{
		j=i+d-1;
		if((n-d)&1) dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
		else dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}

