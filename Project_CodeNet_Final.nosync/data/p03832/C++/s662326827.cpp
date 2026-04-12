#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
using LL = long long;

const int mod = 1e9 + 7;
mt19937 rng( (int)chrono::steady_clock::now().time_since_epoch().count() );

struct Mint {
  int a;
  Mint(int _a = 0) : a(_a) {}
  friend ostream& operator << (ostream &out, const Mint &_) {
    out << _.a;
    return out;
  }

  bool operator == (const Mint &_) const { return a == _.a; }
  bool operator ! () const { return !a; }

  Mint operator + (const Mint &_) const {
    int ret = a + _.a;
    return ret < mod ? Mint(ret) : Mint(ret - mod);
  }
  Mint operator - (const Mint &_) const { return *this + Mint(mod - _.a); }
  Mint operator * (const Mint &_) const { return Mint( (int)( (LL)a * _.a % mod) ); }
  friend Mint& operator += (Mint &a, const Mint &b) { return a = a + b; }
  friend Mint& operator -= (Mint &a, const Mint &b) { return a = a - b; }
  friend Mint& operator *= (Mint &a, const Mint &b) { return a = a * b; }
  Mint& operator ++ () { return *this = *this + Mint(1); }
  Mint& operator -- () { return *this = *this - Mint(1); }

  template<class T> Mint binPow(T exp) const {
    Mint ret(1), c = *this;
    for (; exp; exp >>= 1, c *= c) if (exp & 1) ret *= c;
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifdef FourLeafClover
  freopen("input", "r", stdin);
  #endif // FourLeafClover

  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

  vector<Mint> inv(n + 1); inv[1] = Mint(1);
  for (int i = 2; i < sz(inv); ++i) inv[i] = inv[mod % i] * Mint(mod - mod / i);
  vector<Mint> invFact(n + 1); invFact[0] = 1;
  for (int i = 1; i < sz(invFact); ++i) invFact[i] = invFact[i - 1] * inv[i];

  vector<vector<Mint> > f(n + 1, vector<Mint>(1) );
  f[0][0] = Mint(1);
  for (int i = a; i <= b; ++i) {
    vector<vector<Mint> > nF(n + 1, vector<Mint>(min(d, n / i) + 1) );
    for (int j = 0; j < sz(f); ++j) nF[j][0] = f[j][0] + (c < sz(f[j]) ? accumulate(f[j].begin() + c, f[j].end(), Mint() ) : 0);
    f.swap(nF);

//    cerr << "i = " << i << '\n';
//    for (int j = 0; j < sz(f); ++j) {
//      for (int k = 0; k < sz(f[j]); ++k) if (f[j][k].a) cout << j << ' ' << k << ' ' << f[j][k] << '\n';
//    }
//    cerr << "====\n";

    for (int j = 0; j + i < sz(f); ++j) {
      for (int k = 0; k + 1 < sz(f[j]); ++k) f[j + i][k + 1] += f[j][k] * inv[k + 1] * invFact[i];
    }

//    cerr << "i = " << i << '\n';
//    for (int j = 0; j < sz(f); ++j) {
//      for (int k = 0; k < sz(f[j]); ++k) if (f[j][k].a) cout << j << ' ' << k << ' ' << f[j][k] << '\n';
//    }
  }

  Mint ans = f[n][0] + (c < sz(f[n]) ? accumulate(f[n].begin() + c, f[n].end(), Mint() ) : 0);
  for (int i = 1; i <= n; ++i) ans *= Mint(i);

  cout << ans << '\n';

  return 0;
}
