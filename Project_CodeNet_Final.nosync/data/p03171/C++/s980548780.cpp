/*
4
10 80 90 30
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long arr[n+1]={0},dp[n+1][n+1]={0,0};
    for(int i=1;i<=n;i++)
    	cin>>arr[i];



    for(int i=n;i>=1;i--)
    {
    	for(int j=i;j<=n;j++)
    	{
    		if(i==j)
    			dp[i][j] = arr[j];
    		else{
    			dp[i][j] = max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
    		}
    	}
    }

    cout<<dp[1][n];
    return 0;
}