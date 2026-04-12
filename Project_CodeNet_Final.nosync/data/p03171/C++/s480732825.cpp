#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define ar array
#define pb push_back



int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("outputc.txt","w",stdout);
	// #endif
	
	//int t;
	//cin>>t;
	//while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		ll sum=0;
		for(auto &x:a)
		{
			cin>>x;
			sum+=x;
		}
		//dp[i][j] ans for range i...j
		ll dp[n][n][2];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
				{
					dp[i][j][0]=a[i];
					dp[i][j][1]=0;
				}
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=i;j<=n-1;j++)
			{
				if(j<i)continue;
				if(i+1<n&&j-1>=0)
				{
					dp[i][j][0]=max(dp[i][j-1][1]+a[j],dp[i+1][j][1]+a[i]);
					dp[i][j][1]=min(dp[i+1][j][0],dp[i][j-1][0]);
				}
			}
		}
		cout<<2*dp[0][n-1][0]-sum;
		
	}
		
}
