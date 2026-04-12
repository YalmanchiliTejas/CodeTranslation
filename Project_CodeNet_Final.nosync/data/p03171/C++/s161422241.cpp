#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  vector<vector<ll>> dp(n+1, vector<ll>(n+1));
  for(int r=1; r<=n; r++){
    for(int l=r-1; l>=0; l--){
      if(r-l == 1) dp[l][r] = a[l];
      else dp[l][r] = max(a[l] - dp[l+1][r], a[r-1] - dp[l][r-1]);
    }
  }
  cout << dp[0][n] << endl;
}
