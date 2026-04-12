#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define ar array
const int mxn=3e3;
int n;
ar<ll,2> dp[mxn+1][mxn+1];

int main()
{
	//#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	//#endif
	
	//int t;
	//cin>>t;
	//while(t--)
	{
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=n-1;i>=0;i--)
		{
			ar<ll,2> tr={a[i],0};
			for(int j=i;j<n;j++)
			{
				if(i+1<n&&j-1>=0&&(dp[i+1][j][1]+a[i]<dp[i][j-1][1]+a[j]))
				{
					tr={dp[i][j-1][1]+a[j],dp[i][j-1][0]};
				}
				else
				{
					tr={dp[i+1][j][1]+a[i],dp[i+1][j][0]};
				}
				dp[i][j]=tr;
			}
		}
		cout<<dp[0][n-1][0]-dp[0][n-1][1]<<'\n';
	}
		
}
