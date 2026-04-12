#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
/*template <typename T>
T pow(T a, ll n, T e = 1) {
    T ret = e;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}
 
template <int mod>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long x_) {
        if ((x = x_ % mod + mod) >= mod) x -= mod;
    }
    ModInt& operator+=(ModInt rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        if ((x -= rhs.x) < 0) x += mod;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (unsigned long long)x * rhs.x % mod;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        x = (unsigned long long)x * rhs.inv().x % mod;
        return *this;
    }
 
    ModInt operator-() const { return -x < 0 ? mod - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    ModInt inv() const { return pow(*this, mod - 2); }
 
    friend ostream& operator<<(ostream& s, ModInt<mod> a) {
        s << a.x;
        return s;
    }
    friend istream& operator>>(istream& s, ModInt<mod>& a) {
        s >> a.x;
        return s;
    }
};
 
using mint = ModInt<1000000007>;
*/
using Graph = vector<vector<int>>;
Graph G;
/*------------------------------------------------------------------*/
int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  ll cur;
  ll ans1 = 0, ans2 = 0;
  if(n % 2 == 0){
    rep(i, n){
      if(i == 0) cur = a[n / 2];
      else{
        if(i % 2 == 1){
          ans1 += abs(a[i / 2] - cur);
          cur = a[i / 2];
        }else{
          ans1 += abs(a[n - i / 2] - cur);
          cur = a[n - i / 2];
        }
      }
    }
    rep(i, n){
      if(i == 0) cur = a[n / 2 - 1];
      else{
        if(i % 2 == 1){
          ans2 += abs(a[n - 1 - i / 2] - cur);
          cur = a[n - 1 - i / 2];
        }else{
          ans2 += abs(a[i / 2 - 1] - cur);
          cur = a[i / 2 - 1];
        }
      }
    }
  }else{
    rep(i, n){
      if(i == 0) cur = a[n / 2];
      else{
        if(i % 2 == 1){
          ans1 += abs(a[i / 2] - cur);
          cur = a[i / 2];
        }else{
          ans1 += abs(a[n - i / 2] - cur);
          cur = a[n - i / 2];
        }
      }
    }
    rep(i, n){
      if(i == 0) cur = a[n / 2];
      else{
        if(i % 2 == 1){
          ans2 += abs(a[n - 1 - i / 2] - cur);
          cur = a[n - 1 - i / 2];
        }else{
          ans2 += abs(a[i / 2 - 1] - cur);
          cur = a[i / 2 - 1];
        }
      }
    }
  }
  //cout << ans1 << " " << ans2 << endl;
  cout << max(ans1, ans2) << endl;
}