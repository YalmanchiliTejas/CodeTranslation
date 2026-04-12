#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <bitset>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
// const ll mod =  998244353 ;
const ll mod =  1000000007 ;
const ll inf = 1e18;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define REP_REV(i, n) for (ll i = n-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())

template<typename T> void print_vec(vector<T> a) {int n = a.size();REP(i, n) {cout >> a[i]; if(i!=n-1) cout << " "; else cout << endl;}}
ll power(ll base, ll exponent){ if(exponent % 2){ return power(base, exponent - 1) * base % mod; }else if(exponent){ ll root_ans = power(base, exponent / 2); return root_ans * root_ans % mod; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2);}
ll gcd(ll a, ll b) {if(a < b) gcd(b, a);ll r;while(r=a%b) {a=b;b=r;}return b;}
template<typename T> ll sum(T begin, T end) {return accumulate(begin, end, 0ll);}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

using Pair = pair<ll, ll>;

signed main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  string s;
  ll K;
  cin >> s >> K;
  ll n = sz(s);
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(K+1)));
  dp[0][0][0] = 1;
  REP(i, n) {
//    bound
    if(s[i] == '0') {
      REP(k, K+1) {
        dp[i + 1][0][k] += dp[i][0][k];
      }
    }
    else {
      // 0
      REP(k, K+1) {
        dp[i + 1][1][k] += dp[i][0][k];
      }
      // upper
      REP(k, K) {
        dp[i + 1][0][k+1] += dp[i][0][k];
      }
    }
    REP_FROM(j, 1, s[i] - '0') { // upperは無視
      REP(k, K) {
        dp[i+1][1][k+1] += dp[i][0][k];
      }
    }
//    unbound
    REP(k, K+1) {
      dp[i+1][1][k] += dp[i][1][k];
    }
    REP_FROM(j, 1, 10) {
      REP(k, K) {
        dp[i+1][1][k+1] += dp[i][1][k];
      }
    }
  }

  cout << dp[n][0][K] + dp[n][1][K] << endl;

  return 0;
}
