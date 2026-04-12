#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,a[3010],sum[3010],dp[3010][3010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];dp[i][i]=a[i];sum[i]=sum[i-1]+a[i];}
	for(int l=2;l<=n;l++){
		for(int i=1,j=i+l-1;j<=n;i++,j++){
			int val=sum[j]-sum[i-1];
			int ans1=val-dp[i+1][j],ans2=val-dp[i][j-1];
			dp[i][j]=max(ans1,ans2);
		}
	}
	cout<<dp[1][n]-(sum[n]-dp[1][n])<<endl;
	return 0;
}