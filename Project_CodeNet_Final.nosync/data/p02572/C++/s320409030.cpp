#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

template<int MOD>
struct ModInt {
  ll x;
  ModInt():x(0){}
  ModInt(ll x):x((x%MOD+MOD)%MOD){}
  int getMod() { return MOD; }
  ModInt operator-() const { return ModInt(0) - *this;}
  ModInt& operator+=(const ModInt& a){ if((x+=a.x)>=MOD) x-=MOD; return *this;}
  ModInt& operator-=(const ModInt& a){ if((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
  ModInt& operator*=(const ModInt& a){ (x*=a.x)%=MOD; return *this;}
  ModInt operator+(const ModInt& a)const{ return ModInt(*this) += a;}
  ModInt operator-(const ModInt& a)const{ return ModInt(*this) -= a;}
  ModInt operator*(const ModInt& a)const{ return ModInt(*this) *= a;}
  bool operator<(const ModInt& a)const{ return x < a.x;}
  bool operator==(const ModInt& a)const{ return x == a.x;}
  ModInt pow(ll t) const {
    if (!t) return 1;
    ModInt a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  friend istream & operator >> (istream & in, ModInt & v) {
    ll x;
    in >> x;
    v.x = x;
    return in;
  }
  friend ostream & operator << (ostream & out, ModInt<MOD> const & v) {
    out << v.x;
    return out;
  }
};
const int MOD = 1000000007;
using mint = ModInt<MOD>;

int main() {
  int n; cin >> n;
  vector<mint> A(n);
  loop(i,0,n) cin >> A[i];
  vector<mint> acc(n+1);
  acc[0] = 0;
  loop(i,0,n) acc[i+1] = acc[i] + A[i];

  mint ans = 0;
  loop(i,0,n-1) {
    ans += A[i] * (acc[n]-acc[i+1]);
  }
  cout << ans << endl;
  return 0;
}
