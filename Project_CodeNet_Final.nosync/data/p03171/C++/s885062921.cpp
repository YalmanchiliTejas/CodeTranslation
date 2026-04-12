#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int DN=3005,M=1e9+7;
long long n,a[DN],dp[2][DN][DN];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int l=1;l<=n;l++)
    {
    	for(int i=1;i<=n-l+1;i++)
    	{
    		int j=i+l-1;
    		if(i==j)
    		{
    			dp[0][i][j]=a[i];
    			dp[1][i][j]=-a[i];
    		}
    		dp[0][i][j]=max(a[i]+dp[1][i+1][j],a[j]+dp[1][i][j-1]);
    		
    		dp[1][i][j]=min(-a[i]+dp[0][i+1][j],-a[j]+dp[0][i][j-1]);
    	}
    }
    cout<<dp[0][1][n];
}