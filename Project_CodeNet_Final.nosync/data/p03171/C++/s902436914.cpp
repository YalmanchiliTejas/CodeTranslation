#include <bits/stdc++.h>
#define ll long long int
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define pb(v, a) v.push_back(a)
#define Sort(v) sort(v.begin(), v.end())
#define For(m) for (auto it = m.begin(); it != m.end(); it++)
#define mod 1000000007
using namespace std;

 ll dp[3005][3005][2];
 bool dp1[3005][3005][2];
 ll arr[3005];

 ll fun(ll l,ll r,ll k)
 {
     if(dp1[l][r][k])
     return dp[l][r][k];
     if(l==r)
     {
         if(k==0)
         {
             dp[l][r][0]=arr[l];
         }
         else
         {
             dp[l][r][1]=-arr[l];
         }
     }
     else
     {
           if(k==0)
         {
             dp[l][r][0]=max(fun(l+1,r,1)+arr[l],fun(l,r-1,1)+arr[r]);
         }
         else
         {
             dp[l][r][1]=min(fun(l+1,r,0)-arr[l],fun(l,r-1,0)-arr[r]);
         }
     }
     dp1[l][r][k]=true;
     return dp[l][r][k];
 }



int main()
{
  ll n;
  cin >> n;
  
  fr(i,0,n)cin >> arr[i];
  fr(i,0,3005)
  {
      fr(j,0,3005)
      {
          fr(k,0,2)
          dp1[i][j][k]=false;
      }
  }

  cout << fun(0,n-1,0);
  

  return 0;
}
