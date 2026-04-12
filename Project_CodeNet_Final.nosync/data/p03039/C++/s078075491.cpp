#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace std;
long long mod = 1e9 + 7;

long long GetValue(long long n, long long m) {
    long long ans = 0;
    for (long long i = 1; i < n; i++) {
        ans = (ans + i * (n - i)) % mod;
    }
    ans = ans * (m * m) % mod;
    return ans;
}
 typedef long long ll;
 void exgcd(ll a,ll b,ll& d,ll& x,ll& y){
     if(!b) { d = a; x = 1; y = 0; }
     else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
 }
 ll inv(ll a, ll p){
     ll d,x,y;
    exgcd(a,p,d,x,y);
    return d == 1 ? (x % p + p)%p : p - 1;
}
long long F(long long a, long long p) {
    return inv(a, p);
}

long long C(long long n, long long m) {
    if (n == 0) { return 1; }
    long long ans = 1;
    for (long long i = 1; i <= m; i++) {
        ans = ans * (n - i + 1) % mod * F(i, mod) % mod;
    }
    return ans;
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  long long ans = 0, mod = 1e9 + 7;
  ans = GetValue(n, m) + GetValue(m, n);
  if (ans >= mod) {
    ans -= mod;
  }
  ans = ans * C(n * m - 2, k - 2) % mod;
  printf("%lld\n", ans);
  return 0;
}
