#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main()
 {
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
     pair<int,int> dp[n][n];
     for(int i=0;i<n;i++)
     {
         dp[i][i].first=arr[i];
         dp[i][i].second=0;
     }
     for(int k=1;k<n;k++)
     {
         for(int i=0;i<n;i++)
         {
             int j=i+k;
             if(j>=n) break;
             int a1=dp[i][j-1].second+arr[j];
             int a2=dp[i+1][j].second+arr[i];
             dp[i][j].first=max(a1,a2);
             if(a1>a2)
             {
                 dp[i][j].second=dp[i][j-1].first;
             }
             else
             {
                 dp[i][j].second=dp[i+1][j].first;
             }
             
         }
     }
     cout<<dp[0][n-1].first-dp[0][n-1].second<<"\n";
 }