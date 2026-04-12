#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
  cin>>n;
  int arr[n+1];
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  	
  long long	int dp[n+1][n+1];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      //for(int k=0;k<=2;k++)
        dp[i][j]=0;
  
  for(int dist=0;dist<n;dist++)
  {
    for(int i=1;i<=n-dist;i++)
    {
      int j=dist+i;
      if(i==j)
      {
        dp[i][j]=arr[i];
        continue;
      }
      dp[i][j]=max(arr[j]-dp[i][j-1],arr[i]-dp[i+1][j]);
     
    }
  }
  
 /** for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }**/
   
  cout<<dp[1][n]<<endl;
  return 0;
}