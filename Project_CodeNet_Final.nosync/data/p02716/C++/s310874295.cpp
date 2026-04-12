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

ll dp[200100][3];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n+1){
    rep(j, 3){
      dp[i][j] = -INF;
    }
  }

  dp[0][0] = 0;

  rep(i, n){
    
    // そのまま
    if(i%2==0){
      chmax(dp[i+1][0], dp[i][0] + a[i]);
      chmax(dp[i+1][1], dp[i][1]);
      chmax(dp[i+1][2], dp[i][2] + a[i]);
    }else{
      chmax(dp[i+1][0], dp[i][0]);
      chmax(dp[i+1][1], dp[i][1] + a[i]);
      chmax(dp[i+1][2], dp[i][2]);
    }

    // 1個増やす
    chmax(dp[i+1][1], dp[i][0]);
    chmax(dp[i+1][2], dp[i][1]);

  }

  if(n%2==0){
    cout << dp[n][1] << endl;
  }else{
    cout << dp[n][2] << endl;
  }

  return 0;
}
