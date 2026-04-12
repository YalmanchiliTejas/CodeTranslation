#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
using namespace std;
using ll = long long;
const ll mod =  1000000007;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (int i = (j); i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll power(ll base, ll exponent, ll module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ ll root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2, mod);}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

signed main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 1;
  int mc;
  cin >> mc;
  REP_FROM(i, 1, n) {
    int c;
    cin >> c;
    if(c >= mc) {
      ans++;
      mc = c;
    }
  }
  cout << ans <<endl;
}
