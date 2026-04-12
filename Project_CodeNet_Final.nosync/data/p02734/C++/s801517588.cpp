#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)
#define MOD 998244353

//debug
#define debug(arr) cerr<<#arr<<"(l"<<__LINE__<<") : ";for(auto x:arr)cerr<<x<<" ";cerr<<endl;


int main(){
  ll N, S;
  cin >> N >> S;
  vll A(N);
  rep(i, N) cin >> A[i];

  vector<vll> dp(2, vll(S+1, 0));
  ll ans = 0;
  rep(i, N){
    rep(s, S+1) dp[(i+1)%2][s] = dp[i%2][s];
    rep(s, S+1-A[i]) dp[(i+1)%2][s+A[i]] = (dp[(i+1)%2][s+A[i]] + dp[i%2][s]) % MOD;
    if(A[i] <= S) dp[(i+1)%2][A[i]] = (dp[(i+1)%2][A[i]] + i + 1) % MOD;
    ans = (ans + dp[(i+1)%2][S]) % MOD;
  }
  cout << ans << endl;
  return 0;
}