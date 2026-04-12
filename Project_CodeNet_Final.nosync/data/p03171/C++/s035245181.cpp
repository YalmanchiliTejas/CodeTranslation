#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i > 0; i++)

using ll=long long;

ll n;
vector<ll> a(3300);
ll dp[3300][3300];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  rep(i,n) cin >> a[i];

  for(int width = 1; width <= n; width++){
    for(int l = 0; l + width <= n; l++){
      ll r = l + width;
      if(width%2 == n%2) dp[l][r] = max(dp[l+1][r]+a[l], dp[l][r-1]+a[r-1]);
      else dp[l][r] = min(dp[l+1][r]-a[l], dp[l][r-1]-a[r-1]);
    }
  }
  cout << dp[0][n] << endl;
}