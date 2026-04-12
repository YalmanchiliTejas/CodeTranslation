#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
 ll dp[3500][3500][3]; 
 int a[3500];
 ll n;
 ll solve(int s,int e,int turn){
     if(s>e||e<s){
         return 0;
     }
     ll &ret=dp[s][e][turn];if(ret!=-1){return ret;}
     if(turn==0){
         ret=max(solve(s+1,e,turn^1)+a[s],solve(s,e-1,turn^1)+a[e]);
     }else{
          ret=min(solve(s+1,e,turn^1)-a[s],solve(s,e-1,turn^1)-a[e]);
     }return ret;
     
   
 }
int main()
{
    
  cin>>n;
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   memset(dp,-1,sizeof dp);
   
  ll ans= solve(0,n-1,0);
  cout<<ans;
  
}