#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<vector<ll>> dp(2,vector<ll>(9,LLONG_MIN/5));
  dp[0][4] = 0;

  rep(i,n){
    vector<vector<ll>> ndp(2,vector<ll>(9,LLONG_MIN/5));
    rep(l,9){
      if((i+1)%2==0){
        if(l>0){
          ndp[0][l-1] = max(ndp[0][l-1],dp[1][l]);
          ndp[0][l-1] = max(ndp[0][l-1],dp[0][l]);
        }
        ndp[1][l] = max(ndp[1][l],dp[0][l]+a[i]);
      }
      else{
        ndp[0][l] = max(ndp[0][l],dp[1][l]);
        ndp[0][l] = max(ndp[0][l],dp[0][l]);
        if(l<8) ndp[1][l+1] = max(ndp[1][l+1],dp[0][l]+a[i]);
      }
    }
    // cout << ndp[0][4] << " " << ndp[1][4] << endl;
    swap(ndp,dp);
  }
  cout << max(dp[1][4],dp[0][4]) << endl;


  return 0;
    

}
