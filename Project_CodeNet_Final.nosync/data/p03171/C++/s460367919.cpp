#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N;ll a[3001];
ll dp[3001][3001];
ll ans(ll ind1,ll ind2){
      if(ind1==ind2){
            if((N-1+ind1-ind2)%2==0)return a[ind1];
            else return -1*a[ind1];
      }
      if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];ll x;
      if((N-1-ind2+ind1)%2==0)x = 1;
      else x = -1;
      if(x==1)dp[ind1][ind2] = max(ans(ind1+1,ind2)+x*a[ind1],ans(ind1,ind2-1)+x*a[ind2]);
      else dp[ind1][ind2] = min(ans(ind1+1,ind2)+x*a[ind1],ans(ind1,ind2-1)+x*a[ind2]);
      return dp[ind1][ind2];
}
int main(){
      cin>>N;for(ll i=0;i<N;i++)cin>>a[i];memset(dp,-1,sizeof(dp));
      cout<<ans(0,N-1)<<endl;
      return 0;
}
