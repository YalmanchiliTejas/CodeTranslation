#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 2e5+10;
typedef long long LL;
LL fac[MAXN];

LL qpow (LL a, LL b)
{
  LL ans = 1;
  while(b)
  {
    if(b & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    b = b / 2;
  }
  return ans;
}

LL C (LL a, LL b)
{
  LL ans = fac[a] * qpow(fac[b], MOD - 2) % MOD;
  ans = ans * qpow((fac[a-b] + MOD) % MOD, MOD - 2) % MOD;
  return ans;
}

int main()
{
  int n , m , k;
  fac[0] = 1;
  for (int i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
  scanf("%d%d%d",&n,&m,&k);
  LL ans = 1;
  ans = ans * C(n*m,k) % MOD * C(k,2) % MOD * (n+m) % MOD * qpow(3,MOD-2) % MOD;
  printf("%lld\n",ans);

}