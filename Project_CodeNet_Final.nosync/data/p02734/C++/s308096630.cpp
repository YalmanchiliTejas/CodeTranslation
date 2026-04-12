#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll mod = 998244353;

int main(){
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<vector<ll>> dp(s+1, vector<ll>(3,0));

  dp[0][0] = 1;
  
  for (int i = 0; i < n; i++) {
    vector<vector<ll>> ndp(s+1, vector<ll>(3,0));
    for (int j = 0; j <= s; j++) {
      //選ばない
      (ndp[j][1] += dp[j][0]) %= mod;
      (ndp[j][1] += dp[j][1]) %= mod;
      (ndp[j][2] += dp[j][1]) %= mod;
      (ndp[j][2] += dp[j][2]) %= mod;
      (ndp[j][2] += dp[j][0]) %= mod;
      (ndp[j][0] += dp[j][0]) %= mod;
      //選ぶ
      if (j + a[i] <= s) (ndp[j + a[i]][1] += dp[j][0] + dp[j][1]) %= mod;
      if (j + a[i] <= s) (ndp[j + a[i]][2] += dp[j][0] + dp[j][1]) %= mod;
    }
    swap(dp, ndp);
  }

  cout << dp[s][2] << endl;
  return 0;
} 