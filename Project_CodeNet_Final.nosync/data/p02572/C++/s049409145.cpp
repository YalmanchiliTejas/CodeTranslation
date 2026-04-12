#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
  ll MOD = 1000000007;
  ll n;
  cin >> n;
  ll sum = 0;
  vl a(n);
  rep(i,n){
    cin >> a[i];
    sum += a[i];
    sum %= MOD;
  }
  ll ans = 0;
  rep(i,n){
    ll tasu = a[i] * (sum-a[i]);
    ans += tasu;
    ans %= MOD;
  }
  ans += MOD;
  cout << ans * modinv(2, MOD) % MOD << endl;
}
