#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
	for(auto &e:u) fill_v<T>(e,v...);
}
template<::std::uint_fast64_t mod>
class ModInt{
private:
  using value_type = ::std::uint_fast64_t;
  value_type n;
public:
  ModInt() : n(0) {}
  ModInt(value_type n_) : n(n_ % mod) {}
  ModInt(const ModInt& m) : n(m.n) {}

  template<typename T>
  explicit operator T() const { return static_cast<T>(n); }
  value_type get() const { return n; }

  friend ::std::ostream& operator<<(::std::ostream &os, const ModInt<mod> &a) {
    return os << a.n;
  }

  friend ::std::istream& operator>>(::std::istream &is, ModInt<mod> &a) {
    value_type x;
    is >> x;
    a = ModInt<mod>(x);
    return is;
  }

  bool operator==(const ModInt& m) const { return n == m.n; }
  bool operator!=(const ModInt& m) const { return n != m.n; }
  ModInt& operator*=(const ModInt& m){ n = n * m.n % mod; return *this; }

  ModInt pow(value_type b) const{
    ModInt ans = 1, m = ModInt(*this);
    while(b){
      if(b & 1) ans *= m;
      m *= m;
      b >>= 1;
    }
    return ans;
  }

  ModInt inv() const { return (*this).pow(mod-2); }
  ModInt& operator+=(const ModInt& m){ n += m.n; n = (n < mod ? n : n - mod); return *this; }
  ModInt& operator-=(const ModInt& m){ n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
  ModInt& operator/=(const ModInt& m){ *this *= m.inv(); return *this; }
  ModInt operator+(const ModInt& m) const { return ModInt(*this) += m; }
  ModInt operator-(const ModInt& m) const { return ModInt(*this) -= m; }
  ModInt operator*(const ModInt& m) const { return ModInt(*this) *= m; }
  ModInt operator/(const ModInt& m) const { return ModInt(*this) /= m; }
  ModInt& operator++(){ n += 1; return *this; }
  ModInt& operator--(){ n -= 1; return *this; }
  ModInt operator++(int){
    ModInt old(n);
    n += 1;
    return old;
  }
  ModInt operator--(int){
    ModInt old(n);
    n -= 1;
    return old;
  }
  ModInt operator-() const { return ModInt(mod-n); }
};

constexpr int64 mod = 998244353;
using Mint = ModInt<mod>;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64 N, X, M;
  cin >> N >> X >> M;
  int64 res = 0;
  map<int64, PLL> cnt;
  int64 step = 0;
  int64 a = X;
  while (step < N) {
    if (cnt.count(a)) break;
    cnt[a] = PLL(step++, res);
    res += a;
    a = (a * a) % M;
  }
  if (step < N) {
    int64 rem = N - step;
    int64 c_step = step - cnt[a].fs, c_val = res - cnt[a].sc;
    res += rem / c_step * c_val;
    step += rem / c_step * c_step;
  }
  while (step < N) {
    step++;
    res += a;
    a = (a * a) % M;
  }
  cout << res << endl;
}
