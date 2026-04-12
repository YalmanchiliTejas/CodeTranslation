#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

constexpr ll MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin>>n;
  ll sum = 0;
  ll sqsum = 0;
  REP(i,n) {
    ll a;
    cin>>a;
    sum += a;
    sum %= MOD;
    sqsum += a*a % MOD;
    sqsum %= MOD;
  }
  ll ans = sum * sum % MOD;
  ans += MOD - sqsum;
  ans %= MOD;
  ans *= (MOD + 1) / 2;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
