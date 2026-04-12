#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;
ll n, x, m;

vector<ll> dp;
void f(ll a, ll m){
  set<ll> s;
  for (ll i = 1; i < a; ++i) {
    dp[i] = (dp[i-1] * dp[i-1]) % m;
    if(s.count((dp[i-1] * dp[i-1]) % m) == 1) break;
    s.insert(dp[i]);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> m;

  dp = vector<ll> (m+10, -1);
  dp[0] = x;

  f(n+1, m);

  ll res = 0;
  vector<ll> mp(m+10);
  // map<ll, ll> mp;
  ll tmp = 0;
  for (ll i = 0; i < 1000000; ++i) {
    mp[dp[i]] = i;
    if(dp[i+2] == -1){
      tmp = i;
      break;
    }
  }

  // rep(i, 100) cout << dp[i] << ' ';
  // cout << endl;
  // print(mp);
  ll syu = 0;
  for (ll i = 0; i < mp[dp[tmp+1]]; ++i) {
    res += dp[i];
    n--;
  }

  // cout << res << endl;
  for (ll i = mp[dp[tmp+1]]; i <= tmp; ++i) {
    syu += dp[i];
  }

  ll len = tmp - mp[dp[tmp+1]] + 1;

  res += (n/len)*syu;
  n %= len;
  for (ll i = mp[dp[tmp+1]]; i < mp[dp[tmp+1]] + n; ++i) {
    res += dp[i];
  }

  cout << res << endl;
}
