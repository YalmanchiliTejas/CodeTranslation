#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=3e3+55;
ll dp[N][N];
ll a[N];
int n;
	

int main()
{
	memset(dp,-1,sizeof dp);
	ios::sync_with_stdio(false);
	cin>>n;
	int t=(n%2)*2-1;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int k=0,i=0,j=0;;i++,j++)
	{
		if(i==n)
		{
			k++;
			i=k;
			j=0;
			t*=-1;
		}
		if(k==n)
		break;
		if(i==j)
		{
			dp[i][j]=a[i]*t;
			continue ;
		}
		dp[i][j]=max(t*(dp[i-1][j]+t*a[i]),t*(dp[i][j+1]+t*a[j]));
		dp[i][j]*=t;
	}
	cout<<dp[n-1][0]<<endl;
	return 0;
}
