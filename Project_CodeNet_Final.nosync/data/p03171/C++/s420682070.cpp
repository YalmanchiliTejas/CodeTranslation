#include <iostream>
#include<bits/stdc++.h>
#define MAX 3001
#define ll long long

using namespace std;

ll findit(ll arr[],int i,int j,ll dp[MAX][MAX])
{
    
   // pair<int,int> current=make_pair(i,j);
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    
    if(i==j)
    {
        return arr[i];
    }
    
    if(j==i+1)
    {
      return max(arr[i],arr[j]);
    }
    
    ll way1=arr[i]+min( findit(arr,i+2,j,dp) ,findit(arr,i+1,j-1,dp)   );
    ll way2=arr[j]+min(findit(arr,i,j-2,dp) ,findit(arr,i+1,j-1,dp));
    
    
   dp[i][j]=max(way1,way2);
   return dp[i][j];
}


int main() 
{
  int n;
  cin>>n;
  ll arr[n];
 // map< pair<int,int> ,ll> v;
 ll dp[MAX][MAX];
 for(int i=0;i<MAX;i++)
 {
     for(int j=0;j<MAX;j++)
     {
         dp[i][j]=-1;
     }
 }
  ll total=0;
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
      total=total+arr[i];
  }
  
  ll maxxget=findit(arr,0,n-1,dp);
  ll yget=total-maxxget;
  
  cout<<maxxget-yget;
  


	return 0;
}
