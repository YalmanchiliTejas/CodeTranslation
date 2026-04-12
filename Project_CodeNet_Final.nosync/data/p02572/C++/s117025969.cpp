
#include <iostream>
#include <iomanip> //! for setprecision(10)
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

class Mint {
public:
  typedef long long val_type;

  Mint(val_type x=0, int m=MOD) : val((x%m+m)%m), mod(m) {}
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

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<Mint> A(N);
    Mint tot = 0;
    rep(i, N) {
        int a;
        cin >> a;
        A[i] = Mint(a);
        tot += A[i];
    }

    Mint ans = 0;
    rep(i, N) {
        ans += A[i] * (tot - A[i]);
    }
    ans /= Mint(2);

    cout << ans.value() << endl;

    return 0;
}
