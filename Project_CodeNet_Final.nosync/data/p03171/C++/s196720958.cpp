#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
  ll n;
  cin>>n;
  ll a[n];
  ll sum =0;
  ll dp[3000][3000][2] ;
  for(ll i=0;i<n;i++){
    cin>>a[i];
    sum+= a[i];
    dp[i][i][0] = a[i];
    dp[i][i][1] = 0;
  }
  for(ll rml=1;rml<n;rml++){
    for(ll L=0;L+rml<n;L++){
      int R = rml+L;
      dp[L][R][0] = max(a[L]+dp[L+1][R][1],a[R]+dp[L][R-1][1]);
      dp[L][R][1] = min(dp[L+1][R][0], dp[L][R-1][0]);
    }
  }
  ll X = dp[0][n-1][0] ;
  cout<<2*X-sum ;
}
