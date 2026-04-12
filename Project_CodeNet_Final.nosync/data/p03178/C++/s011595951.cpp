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

ll dp[10010][2][110];
const ll MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int D;
  cin >> D;

  rep(i, s.size()+1){
    rep(j, 2){
      rep(k, D){
        dp[i][j][k] = 0;
      }
    }
  }

  dp[0][0][0] = 1;

  rep(i, s.size()){
    int nd = s[i] - '0';
    rep(j, 2){
      rep(k, D){
        rep(d, 10){

          int nj, nk;
          nj = j, nk = k;
          if(nj == 0 && d > nd) continue;
          if(nj == 0 && d < nd) nj = 1;

          nk = (k + d) % D;

          dp[i+1][nj][nk] = (dp[i+1][nj][nk] + dp[i][j][k]) % MOD;

        }
      }
    }
  }

  cout << (dp[s.size()][0][0] + dp[s.size()][1][0] + MOD - 1LL) % MOD << endl;





  return 0;
}
