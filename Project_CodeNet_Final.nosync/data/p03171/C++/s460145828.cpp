#include<bits/stdc++.h>
using namespace std;
int n,a[3010];
long long dp[3010][3010];
long long s[3010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		dp[i][i]=a[i];
	for(int i=1;i<n;i++)
		for(int j=1;i+j<=n;j++){
			long long a1=a[j]+s[i+j]-s[j]-dp[j+1][i+j];
			long long a2=a[i+j]+s[i+j-1]-s[j-1]-dp[j][i+j-1];
			dp[j][i+j]=max(a1,a2);
		}
	cout<<2*dp[1][n]-s[n];
	return 0;
}