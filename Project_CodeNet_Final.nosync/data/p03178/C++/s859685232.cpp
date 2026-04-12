#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll dp[10100][2][110];
const ll MOD = 1e9+7;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  int D;
  cin >> D;

  for(int i = 0; i <= S.length(); i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k < D; k++){
        dp[i][j][k] = 0;
      }
    }
  }

  dp[0][0][0] = 1;

  for(int i = 0; i < S.length(); i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k < 10; k++){
        int nj = j;
        if(j == 0 && k > (S[i] - '0')){
          continue;
        };
        if(j == 0 && k < (S[i] - '0')){
          nj = 1;
        }
        for(int d = 0; d < D; d++){
          dp[i+1][nj][(d+k)%D] += dp[i][j][d];
          dp[i+1][nj][(d+k)%D] = (dp[i+1][nj][(d+k)%D]) % MOD;
        }
      }
    }
  }

  ll ans = 0;
  ans = (dp[S.length()][0][0] + dp[S.length()][1][0] + MOD - 1) % MOD;
  cout << ans << endl;

  return 0;
}

