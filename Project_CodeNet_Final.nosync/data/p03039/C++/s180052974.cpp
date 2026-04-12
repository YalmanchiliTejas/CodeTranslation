#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ul;
typedef signed long long ll;

ul binpow(ul n, ul x, ul mod)
{
  ul tgt = 1;
  ul dig = n;
  while (x > 0) {
    if (x%2) {
      tgt = (tgt * dig) % mod;
    }
    dig = (dig * dig) % mod;
    x /= 2;
  }
  return tgt;
}

class Comb
{
public:
  ul mod;
  vector< ul > fact;
  vector< ul > factf;
  void init(ul size, ul imod) {
    mod = imod;
    fact.resize(size+1);
    factf.resize(size+1);
    fact[0] = 1;
    factf[0] = 1;
    for (ul i = 1; i <= size; ++i) {
      fact[i] = fact[i-1]*i%mod;
      factf[i] = binpow(fact[i], mod-2, mod);
    }
  }
  ul comb(ul n, ul k) {
    if (n<k) return 0;
    if (k==0 || n==k) return 1;
    return ((fact[n] * factf[k]) % mod * factf[n-k]) % mod;
  }
};

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  Comb comb;
  comb.init(2e5, 1e9+7);

  int n, m, k;
  cin >> n >> m >> k;
  ul ans = 0;
  ul line = 0;
  for (int i=0; i<n; ++i) {
    ul left = 0;
    for (int j=0; j<m; ++j) {
      left += j;
      ul cur = j*(j+1)/2 + (m-j-1)*(m-j)/2;
      if (i>0) {
        cur = (cur+m + (cur + m*i))*i/2;
      } else {
        cur = 0;
      }
      ans += cur + left;
      ans %= 1000000007;
    }
  }
  cout << ans * comb.comb(n*m-2, k-2) % 1000000007 << endl;
  return 0;
}
