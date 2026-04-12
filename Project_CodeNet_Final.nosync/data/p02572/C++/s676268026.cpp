#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 2e5+9;

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}
template <unsigned M> struct modular {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
  static constexpr unsigned mod = M;
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
#pragma GCC diagnostic pop
};
using mint = modular<inf>;
mint A[N];

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    cin>>n;
    mint m = 0;
    for(int i=0;i<n;++i) {
        cin>>A[i].v;
        m += A[i];
    }

    mint res = 0;
    for(int i=0;i<n-1;++i) {
        m -= A[i];
        res += m*A[i];
    }
    cout<<res.v<<endl;
    return 0;
}