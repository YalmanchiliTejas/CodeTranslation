#include "bits/stdc++.h"
using namespace std;

const int maxn = 200005;
using ll = long long;

ll mod = 1e9 + 7;
ll a[maxn], sum = 0, pref[maxn];

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }
  for(int i = 1; i <= n; ++i){
    pref[i] = pref[i - 1] + a[i];
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ll sum = (pref[n] - pref[i] + mod) % mod;
    ll cnt = sum;
    cnt = (cnt * a[i]) % mod;
    ans = (ans + cnt) % mod;
  }
  cout << ans << endl;

  return 0;
}