#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int,int>;
ll dp[100001];
int main() {
   ll n,x,m;cin>>n>>x>>m;
   ll ans=0;
   ll loop=0, loop_size=0, loop_sum=0, loop_start=0;
   rep(i,200000){
      if(dp[x]==1){
         loop_size++;
         loop_sum+=x;
      }
      if(dp[x]==2){
         loop=((n-i>0)?n-i:0);
         loop_start=x;
         break;
      }
      if(i<n)ans+=x;
      dp[x]++;
      x*=x;
      x%=m;
   }
   if(loop_size>0){
      ans+=(loop/loop_size)*loop_sum;
      rep(i,loop%loop_size){
         ans+=x;
         x*=x;
         x%=m;
      }
   }
   cout<<ans<<endl;
}