#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3001;
int n;ll arr[maxn];
ll dp[maxn][maxn];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int k=0;k<n;k++)
	{
		int i=0,j=k;
		while(j<n)
		{
			if(i==j)dp[i][j]=arr[i];
			else dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
			i++;j++;
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}
