#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

const int maxn = 2000 + 10;
int fac[maxn], invfac[maxn];

#define MOD 1000000007
long long qpow(long long a, long long b){
    long long s = 1;
    while (b > 0) {
        if (b & 1)s = s * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return s;
}
void init() {
    int n = maxn - 1;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    invfac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i) {
        invfac[i] = 1ll * invfac[i + 1] * (i + 1) % MOD;
    }
}
long long comb(int n, int m) {
    if (n < m) return 0;
    return 1ll * fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

int lp(int now, int k){
  if(!(now > 0 && k > 0 && now >= k)) return 0;
  return pow(9, k) * comb(now-1, k-1) + lp(now-1, k);
}

int main(){
  init();
  string n;
  cin >> n;
  int k;
  cin >> k;
  int m = n.length();
  long long ans = 0;
  int z_count = 0;
  for(int i = m; i > 0; i--){
    int now_top = int(n[m-i])-48;
    if(!now_top) z_count++;
    ans += (now_top > 0) * lp(i-1, k-(m-i)+z_count); //下の桁
    ans += (now_top > 0) * (now_top - 1) * lp(i-1, k-(m-i)+z_count-1); //同じ桁
    ans += now_top * (k-(m-i)+z_count == 1 && now_top != 0); //1 0 ... 0 0 の形 * now_top
  }
  cout << ans << endl;
}
