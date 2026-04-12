// 問題の URL を書いておく
// 

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

using ll = int64_t;

template<int Mod>
struct MintBase {
  int64_t x; // typedef long long int64_t;
  MintBase(int64_t x=0):x((x%Mod+Mod)%Mod){}
  MintBase operator-() const { return MintBase(-x);}
  MintBase& operator+=(const MintBase a) {
    if ((x += a.x) >= Mod) x -= Mod;
    return *this;
  }
  MintBase& operator-=(const MintBase a) {
    if ((x += Mod-a.x) >= Mod) x -= Mod;
    return *this;
  }
  MintBase& operator*=(const MintBase a) { (x *= a.x) %= Mod; return *this;}
  MintBase operator+(const MintBase a) const { return MintBase(*this) += a;}
  MintBase operator-(const MintBase a) const { return MintBase(*this) -= a;}
  MintBase operator*(const MintBase a) const { return MintBase(*this) *= a;}
  MintBase pow(int64_t t) const {
    if (!t) return 1;
    MintBase a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime Mod
  MintBase inv() const { return pow(Mod-2);}
  MintBase& operator/=(const MintBase a) { return *this *= a.inv();}
  MintBase operator/(const MintBase a) const { return MintBase(*this) /= a;}
};

//const int Mod = 1000000007;
//const int Mod = 998244353;

using mint = MintBase<1000000007>;

istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main(int, const char**)
{
    int n;
    cin >> n;
    mint ans = 0;
    mint sums = 0;
    ll a0;
    cin >> a0;
    sums.x = a0; 
    rep(i, n - 1)
    {
        mint a;
        ll aa;
        cin >> aa;
        a.x = aa;
        ans += sums * a;
        sums += a;
    }
    cout << ans.x << endl;
    return 0;
}
