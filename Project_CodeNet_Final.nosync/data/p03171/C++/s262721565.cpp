#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
int main()
{

   ll n;
   cin>>n;
   ll arr[n];
   for(ll i=0;i<n;i++)
   {
        cin>>arr[i];
   }
   ll dp[n][n][2];
   for(int i=0;i<n;i++)
   {
       dp[i][i][0]=arr[i];
       dp[i][i][1]=-arr[i];
   }
   for(int j=1;j<n;j++)
   {
       for(int i=0;i<n;i++)
       {  //cout<<i<<" "<<j<<endl;
            if(i+j>=n)
            continue;
           dp[i][i+j][0]=max(dp[i][i+j-1][1]+arr[i+j],dp[i+1][i+j][1]+arr[i]);
           dp[i][i+j][1]=min(dp[i][i+j-1][0]-arr[i+j],dp[i+1][i+j][0]-arr[i]);
           //scout<<dp[i][i+j][0]<<" ";
       }
     //  cout<<endl;
   }
   cout<<dp[0][n-1][0]<<endl;

  

}