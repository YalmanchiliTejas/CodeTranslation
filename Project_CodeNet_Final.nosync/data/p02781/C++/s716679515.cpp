#include <bits/stdc++.h>
template <long long mod>
class Combination
{
    std::vector<long long> fact, finv, inv;
public:
    Combination(int sz)
    {
        fact.resize(sz);
        finv.resize(sz);
        inv.resize(sz);
        fact[0] = 1;
        for (int i = 1; i < sz; ++i)
        {
            fact[i] = fact[i - 1] * i % mod;
        }
        inv[0] = 0;
        inv[1] = 1;
        for (int i = 2; i < sz; ++i)
        {
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        }
        finv[0] = 1;
        for (int i = 1; i < sz; ++i)
        {
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    long long C(long long n, long long k)
    {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return (fact[n] * finv[k] % mod) * finv[n - k] % mod;
    }
    long long P(long long n, long long k)
    {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fact[n] * finv[n - k] % mod;
    }
    long long H(long long n, long long k)
    {
        return this->C(n + k - 1, k);
    }
    long long getfact(int i)
    {
        return fact[i];
    }
    long long getinv(int i)
    {
        return inv[i];
    }
    long long getfinv(int i)
    {
        return finv[i];
    }
};
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  Combination<MOD> comb(100000);
  string s; cin >> s;
  int k; cin >> k;
  int dig = (int)(s.size());
  vector<int> a(dig);
  for(int i=0;i<dig;++i) {
    a[i] = s[i] - '0';
  }
  ll ans = 0;
  ll mul = 1;
  for(int i=0;i<k;++i) {
    mul *= 9;
  }
  for(int i=k;i<dig;++i) {
    ans += mul * comb.C(i-1, k-1);
  }
  vector<vector<vector<ll>>> dp(dig, vector<vector<ll>>(k+1, vector<ll>(2, 0)));
  if(a[0] > 0) {
    dp[0][1][1] = 1;
    dp[0][1][0] = a[0] - 1;
  }
  for(int i=0;i<dig-1;++i) {
    for(int j=0;j<k+1;++j) {
      dp[i+1][j][0] += dp[i][j][0];
      if(j > 0) dp[i+1][j][0] += 9 * dp[i][j-1][0];
      if(a[i+1] > 0) {
        dp[i+1][j][0] += dp[i][j][1];
        if(j > 0) dp[i+1][j][0] += (a[i+1]-1) * dp[i][j-1][1];
      }
      if(a[i+1] == 0) dp[i+1][j][1] += dp[i][j][1];
      else if(j > 0) dp[i+1][j][1] += dp[i][j-1][1];
    }
  }
  ans += dp[dig-1][k][1] + dp[dig-1][k][0];
  cout << ans << endl;
}
