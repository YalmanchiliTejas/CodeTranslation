#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp1[3001][3001],dp2[3001][3001];
ll a[3001];
ll f(ll i,ll j,ll y){
   if(y == -1){
   if(dp2[i][j] != -1){
     return dp2[i][j];
   }
   if(i == j){
     return dp2[i][j] = y*a[i];
   }
   return dp2[i][j] = min(y*a[i]+ f(i+1,j,-y),y*a[j]+ f(i,j-1,-y));
   }
   if(y == 1){
     if(dp1[i][j] != -1){
     return dp1[i][j];
   }
   if(i == j){
     return dp1[i][j] = y*a[i];
   }
   return dp1[i][j] = max(y*a[i]+ f(i+1,j,-y),y*a[j]+ f(i,j-1,-y));
   }
}
signed main(){
  memset(dp1,-1,sizeof dp1);
  memset(dp2,-1,sizeof dp2);
  ll n;
  cin>>n;
  for(ll i=0;i<n;i++)cin>>a[i];
  if(n == 1){
    cout << a[0] << '\n';
    return 0;
  }
  cout << max(a[0]+f(1,n-1,-1) , a[n-1] + f(0,n-2,-1));
return 0;
}
