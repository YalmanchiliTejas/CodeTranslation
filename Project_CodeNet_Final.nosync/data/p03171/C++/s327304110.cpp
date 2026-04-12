#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
const ll mod=1e9+7;
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
const ll N=1e6+8;
const ll INF=1e18;
ll n;
ll a[3005];
ll dp[3005][3005][2];
ll sharingan(ll i,ll j,ll ch){
  if(i==j){
    if(ch==0)
      return a[i];
    else 
    return (-1*a[i]);
  }
  if(dp[i][j][ch]!=-1)
  return dp[i][j][ch];
  
  if(ch==0)
  return dp[i][j][ch]=max(a[i]+sharingan(i+1,j,1ll),a[j]+sharingan(i,j-1,1ll));
  else 
   return dp[i][j][ch]=min(sharingan(i+1,j,0ll)-a[i],sharingan(i,j-1,0ll)-a[j]);
}
int main(){
  IOS;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<sharingan(0,n-1,0ll);
}