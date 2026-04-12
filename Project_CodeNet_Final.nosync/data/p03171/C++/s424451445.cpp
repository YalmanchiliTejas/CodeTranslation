#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define iter vector<int>::iterator
#define mod 998244353
#define inf 1e16

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	sum+=a[i];
    }
    int dp[n][n];//dp[i][j] gives the maximum points scored in the interval i to j
    int x,y,z;
    for(int k=0;k<n;k++)
    {
    	for(int i=0,j=k;j<n;j++,i++)
    	{
    		x=0;y=0;z=0;
    		if(i+2<=j)
    			x=dp[i+2][j];
    		if(i+1<=j-1)
    			y=dp[i+1][j-1];
    		if(i<=j-2)
    			z=dp[i][j-2];

    		dp[i][j]=max(a[i]+min(x,y),a[j]+min(y,z));
    	}
    }
    int ans=(2*dp[0][n-1])-sum;
    //cout<<dp[0][n-1]<<" "<<sum-dp[0][n-1]<<"\n";
    cout<<ans<<"\n";
}