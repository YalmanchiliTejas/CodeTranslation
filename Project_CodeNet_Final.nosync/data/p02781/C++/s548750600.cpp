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

ll dp[110][2][4] = {0LL};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  ll K;
  cin >> K;

  dp[0][0][0] = 1LL;

  rep(i, s.length()){

    ll num = ll(s[i] - '0');

    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 2; k++){

        for(int d = 0; d < 10; d++){

          int ni = i+1, nj = j, nk = k;
          if(d != 0) nj++;
          if(nj > K) continue;
          if(k == 0){
            if(d > num) continue;
            if(d < num) nk = 1;
          }
          dp[ni][nk][nj] += dp[i][k][j];
        }
      }
    }
  }

  cout << dp[s.length()][0][K] + dp[s.length()][1][K] << endl;

  return 0;
}
