#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
ll a[3005],dp[3005][3005],hell=998244353;
ll add(ll a,ll b){
  a+=b;
  if(a>hell)
    a-=hell;
  return a;
}
void solve(){
  ll n,s,res=0;
  cin>>n>>s;
  for(ll i=1;i<=n;i++)
    cin>>a[i];
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=s;j++){
      dp[i][j]=dp[i-1][j];
      if(j==a[i]){
        dp[i][j]=add(dp[i][j],i);
        if(j==s)
          res=add(res,(i*(n-i+1))%hell);
      }
      else if(j>a[i]){
        dp[i][j]=add(dp[i][j],dp[i-1][j-a[i]]);
        if(j==s)
          res=add(res,(dp[i-1][j-a[i]]*(n-i+1))%hell);
      }
    }
  cout<<res;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll q=1;
  for(ll i=1;i<=q;i++)
    solve();
}