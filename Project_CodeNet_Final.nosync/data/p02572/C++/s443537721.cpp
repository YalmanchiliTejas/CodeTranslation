#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { 
    return mint(-x);
  }
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
    return mint(*this) += a;
  }
  mint operator-(const mint a) const { 
    return mint(*this) -= a;
  }
  mint operator*(const mint a) const { 
    return mint(*this) *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return *this *= a.inv();
  }
  mint operator/(const mint a) const {
    return mint(*this) /= a;
  }
};
istream& operator>>(istream& is, mint& a) { 
  return is >> a.x;
}
ostream& operator<<(ostream& os, const mint& a) { 
  return os << a.x;
}
mint f(int n){
  if(n==0) return 1;
  mint x = f(n/2);
  x *= x;
  if(n % 2 == 1) x *= 2;
  return x;
}

mint choose(int n, int a) {
  mint x = 1, y = 1;
  rep(i,a){
    x *= n-i;
    y *= i+1;
  }
  return x / y;
}

int main(){
  int n;
  cin >> n;
  vector<mint> a(n);
  vector<mint> sum(n);
  rep(i,n) {
    cin >> a[i];
  }
  sum[0] = a[0];
  for(int i=1; i<n; i++){
    sum[i] = a[i] + sum[i-1];
  }
  mint ans = 0;
  // int cnt = 0;
  rep(i,n) {
    ans += a[i] * (sum[n-1] - sum[i]);
  }
  // if (ans < 0) ans += mod;
  // cout << cnt << endl;
  cout << ans << endl;
  return 0;
}