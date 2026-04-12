#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}


int main() {
  fac[0] = 1;
  ifac[0] = 1;
  for(ll i = 0; i<300000; i++){
      fac[i+1] = fac[i]*(i+1) % mod; // n!(mod M)
      ifac[i+1] = ifac[i]*mpow(i+1, mod-2) % mod; // k!^{M-2} (mod M) ←累乗にmpowを採用
  }
  int n,m,k;
  cin >> n >> m >> k;
  mint ans;
  for (int d = 1; d <= n; d++) {
    ans += (mint)d * (n-d) * m * m * comb(n*m-2,k-2);
  }
  for (int d = 1; d <= m; d++) {
    ans += (mint)d * (m-d) * n * n * comb(n*m-2,k-2);
  }
  cout << ans.x << endl;
  return 0;
}
