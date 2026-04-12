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

const ll MOD = 998244353;

ll dp[3100][3100];


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, S;
  cin >> N >> S;

  vector<int> A(N);

  rep(i, N)cin>> A[i];

  rep(i, N){
    rep(j, S+1){
      dp[i][j] = 0;
    }
  }

  rep(i, N){
    dp[i][0]++;
    rep(j, S+1){
      // そのまま
      dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;

      if(j + A[i] <= S){
        dp[i+1][j+A[i]] = (dp[i+1][j+A[i]] + dp[i][j]) % MOD;
      }
      
    }
  }

  ll ans = 0;
  for(int i = 0; i <= N; i++){
      ans = (ans + dp[i][S]) % MOD;
  }

  cout << ans << endl;


}
