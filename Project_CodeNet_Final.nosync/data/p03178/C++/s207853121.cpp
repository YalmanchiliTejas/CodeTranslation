#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
ll MOD = 1000000007;
ll INF = 200000000000000000;
double EPS = 1e-12;
double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

ll dp[10010][2][110];

int main(){
  string K;
  ll D,N;
  cin >> K >> D;
  N = K.size();
  dp[0][0][0] = 1;
  rep(i,N){
    ll n = K[i] - '0';
    rep(j,2){
      rep(k,D){
        for(ll l = 0;(l < 10) && (j || (l <= n));l++){
          dp[i+1][j | (l < n)][(k+l) % D] += dp[i][j][k];
        }
        dp[i+1][0][k] %= MOD;
        dp[i+1][1][k] %= MOD;
      }
    }
  }
  ll ans = (dp[N][0][0] + dp[N][1][0]) % MOD - 1;
  if(ans < 0) ans += MOD;
  cout << ans << endl;
} 