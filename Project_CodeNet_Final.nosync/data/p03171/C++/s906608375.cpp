#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() 
{
      int n;
      cin>>n;
      ll arr[n];
      for(int i=0; i<n;i++)
      cin>>arr[i];
      ll dp[n][n];// starting and end point of the subarray
      memset(dp,0,sizeof(dp));
      for(int i=0; i<n; i++)
      {
        for(int j=0; j<n;j++)
        {
            if(i==j)
            dp[i][i]=arr[i];
            
        }
      }
       for(int i=n-1; i>=0; i--)
      {
        for(int j=i; j<n;j++)
        {
            if(i!=j)
            dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
            
        }
      }
       cout<<dp[0][n-1]<<endl;
}