#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long sum ;
int n;
long long dp[3005][3005],a[3005];
int main(){
	cin>>n;
	for(int i=1;n>=i;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}

	for(int i=1;n>=i;i++)
		dp[i][i]=a[i];
	for(int i=2;n>=i;i++)
	{
		for(int j=1;j+i-1<=n;j++)
		{
			dp[j][j+i-1]=max(a[j]-dp[j+1][j+i-1],-dp[j][j+i-2]+a[i+j-1]);
		}
	}
	cout<<dp[1][n];

	return 0;
}
