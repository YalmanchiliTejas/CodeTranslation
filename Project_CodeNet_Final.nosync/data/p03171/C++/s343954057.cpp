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

ll dp[3010][3010];
ll a[3010];

int N;

ll rec(int i, int j){

  if(dp[i][j] != INF ) return dp[i][j];

  if((N - (j - i)) % 2 == 0){

    if(i >= j) return -INF;
    if(i < 0) return -INF;
    if(j > N) return -INF;

    ll res = max(rec(i, j-1) + a[j-1], rec(i+1, j) + a[i]);
    return dp[i][j] = res;

  }else{

    if(i >= j) return INF;
    if(i < 0) return INF;
    if(j > N) return INF;
    ll res = min(rec(i, j-1) - a[j-1], rec(i+1, j) - a[i]);
    return dp[i][j] = res;

  }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  rep(i, N){
    cin >> a[i];
  }

  rep(i, N+1){
    rep(j, N+1){
      dp[i][j] = INF;
    }
  }

  rep(i, N){
    if(N % 2 == 0){
      dp[i][i+1] = -a[i];
    }else{
      dp[i][i+1] = a[i];
    }
  }

  cout << rec(0, N) << endl;


  return 0;
}
