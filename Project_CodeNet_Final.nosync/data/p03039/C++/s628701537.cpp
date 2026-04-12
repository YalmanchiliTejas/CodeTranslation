
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MOD = 1000000007;

template<typename T>
T modPow(T base, T p, T mod)
{
    T ret = 1;
    T cur = base;
    T cp = 1;
    while (cp <= p) {
        if (p & cp) {
            ret = (ret * cur) % mod;
        }
        cur = cur * cur % mod;
        cp *= 2;
    }
    return ret;
}

template<typename T>
T modInvSingle(T a, T mod) {
    return modPow(a, mod-2, mod);
}

template<typename T>
T modFactSingle(T a, T mod)
{
    T f = 1;
    for (int i = 1; i <= a; ++i) {
        f = (f * i) % mod;
    }
    return f;
}

template <int DEFAULT_MOD=1000000007>
class Mint {
public:
  typedef long long val_type;

  Mint(val_type x=0, int m=DEFAULT_MOD) : val((x%m+m)%m), mod(m) {}
  val_type value() const { return val; }
  Mint& operator+=(const Mint a) {
    if ((val += a.val) >= mod) val -= mod;
    return *this;
  }
  Mint& operator-=(const Mint a) {
    if ((val += mod-a.val) >= mod) val -= mod;
    return *this;
  }
  Mint& operator*=(const Mint a) {
    (val *= a.val) %= mod;
    return *this;
  }
  Mint operator+(const Mint a) const {
    Mint res(*this);
    return res+=a;
  }
  Mint operator-(const Mint a) const {
    Mint res(*this);
    return res-=a;
  }
  Mint operator*(const Mint a) const {
    Mint res(*this);
    return res*=a;
  }
  Mint pow(val_type t) const {
    if (!t) return 1;
    Mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  Mint inv() const {
    return pow(mod-2);
  }
  Mint& operator/=(const Mint a) {
    return (*this) *= a.inv();
  }
  Mint operator/(const Mint a) const {
    Mint res(*this);
    return res/=a;
  }

private:
  val_type val;
  int mod;
};

template<typename T>
T modCombSingle(T a, T b, T mod) 
{
    return (Mint<MOD>(modFactSingle(a, mod)) / (Mint<MOD>(modFactSingle(b, mod)) * Mint<MOD>(modFactSingle(a-b, mod)))).value(); 
}

int main()
{
    LL N, M, K;
    cin >> N >> M >> K;
    
    LL dxSum = 0;
    for (int dx = 1; dx < M; ++dx) {
        dxSum = (dxSum + dx * (M-dx)) % MOD; 
    }
    dxSum = dxSum * (N * N % MOD) % MOD;

    LL dySum = 0;
    for (int dy = 1; dy < N; ++dy) {
        dySum = (dySum + dy * (N-dy)) % MOD; 
    }
    dySum = dySum * (M * M % MOD) % MOD;

    LL ans = modCombSingle(N*M-2, K-2, (LL) MOD) * ((dxSum + dySum) % MOD) % MOD;

    cout << ans << endl;

    return 0;
}
