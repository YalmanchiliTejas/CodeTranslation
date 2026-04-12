#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
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

const ll MOD = 1e9+7;

ll dp[10100][2][110] = {0};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string K;
  cin >> K;
  int D;
  cin >> D;

  dp[0][0][0] = 1;
  rep(i, K.length()){

    int num = (K[i] - '0');
    for(int j = 0; j < 2; j++){
      for(int m = 0; m < D; m++){
        for(int d = 0; d < 10; d++){
          int ni = i+1, nj = j;
          int nm = (m + d) % D;

          if(j == 0){
            if(d > num) continue;
            if(d < num) nj = 1;
          }
          dp[ni][nj][nm] = (dp[ni][nj][nm] + dp[i][j][m]) % MOD;
        }
      }
    }
  }
  cout << (dp[K.length()][0][0] + dp[K.length()][1][0] + MOD - 1LL) % MOD << endl;

  return 0;
}
