#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << a << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  lvector A(n+1,0);
  rep(i,n) cin>>A[i+1];
  vector<lvector> dp(3,lvector(n+2,-1e18));
  dp[0][0]=0;
  rep(i,n+1) {
    rep(j,3) if(i) dp[j][i+1]=max(dp[j][i+1],dp[j][i-1]+A[i]);
    rep(j,2) dp[j+1][i+1]=max(dp[j+1][i+1],dp[j][i]);
  }
  print(dp[1+n%2].back());
  return 0;
}