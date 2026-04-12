#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

ll MOD = 1000000007;

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        ll tmp;
        cin >> tmp;
        tmp %= MOD;
        a[i] = tmp;
    }
    ll ans = 0;
    ll s = 0;
    rep(i,n) {
        s += a[i];
        s %= MOD;
    }
    rep(i,n-1){
        s = mod(s%MOD-a[i], MOD);
        ans += a[i]*s;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
