#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> v(n);
  for(auto &e:v)
    cin>>e;
  vector<vector<long long> >dp(n,vector<long long>(n,0));
  for(int l=n-1;l>=0;l--)
  {
    for(int r=l;r<n;r++)
    {
      if(l==r)
        dp[l][r]=v[l];
      else
      { 
          dp[l][r]=max(v[l]-dp[l+1][r],v[r]-dp[l][r-1]);
      }
     }
   }
   cout<<dp[0][n-1];                  
  return 0; 
}