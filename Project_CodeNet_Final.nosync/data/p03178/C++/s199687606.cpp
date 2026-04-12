#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF = LLONG_MAX;
constexpr double DINF = DBL_MAX;
constexpr ll mod = 1e9+7;
constexpr double PI = M_PI;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
 
  long long d;
  string s;
  cin >> s >> d;
  long long n = (ll)s.size();
  vector<vector<vector<ll> > > dp(n+1, vector<vector<ll> >(d, vector<ll>(2, 0ll)));
  // dp[i+1][j][k] := 先頭からi文字目まで見たときに
  //                桁和をdで割った余りがjになるs以下の数の個数
  //                k = ( 先頭i文字目までsと一致しているか ? 1 : 0)
  dp[0][0][1] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < d; j++){
      for(int k = 0; k < 10; k++){
        for(int l = 0; l < 2; l++){
          if(l == 1 and s[i]-'0' < k) continue;
          dp[i+1][(j+k) % d][s[i]-'0' == k and l] += dp[i][j][l];
          dp[i+1][(j+k) % d][s[i]-'0' == k and l] %= mod;
        }
      }
    }
  }
  cout << (dp[n][0][0] + dp[n][0][1] - 1 + mod)%mod << endl;
  return 0;
}