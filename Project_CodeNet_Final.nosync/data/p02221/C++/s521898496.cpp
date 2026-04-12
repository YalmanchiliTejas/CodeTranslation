#include <bits/stdc++.h>
using namespace std;

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

template<::std::size_t size, ::std::uint_fast64_t mod=1000000007>
class Factorial{
private:
  using value_type = ModInt<mod>;
  ::std::vector<value_type> fact, inv;
public:
  Factorial() : fact(size+1, 1), inv(size+1, 1){
    for(::std::size_t i = 1; i <= size; ++i){
      fact[i] = fact[i-1] * value_type(i);
      inv[i] = fact[i].inv();
    }
  }

  value_type comb(::std::int64_t a, ::std::int64_t b){
    assert(a >= b);
    assert(b >= 0);
    return fact[a]*inv[b]*inv[a-b];
  }

  value_type& operator[](::std::size_t k){ return fact[k]; }
};

constexpr int64 mod = 998244353;
using Mint = ModInt<mod>;
Factorial<112345, mod> f;

int64 N;
string S;
vector<int64> P;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  cin >> S;
  P.resize(1 << N);
  REP(i, 1 << N) cin >> P[i];

  auto dp = make_v<int>(1, 1<<N);
  REP(i, 1 << N) dp[0][i] = P[i];
  int64 m1 = 1;
  REP(i, N) {
    auto nxt = make_v<int>(dp.size()*2, dp[0].size()/2);
//    cout << nxt.size() << " " << nxt[0].size() << endl;
    REP(j, nxt.size()) {
      REP(k, nxt[j].size()) {
        int64 x = dp[j%m1][(k*2+j/m1)%dp[0].size()], y = dp[j%m1][(k*2+1+j/m1)%dp[0].size()];
//        cout << "    " << k << ": " << j/m1 << " " << (k*2+j/m1)%dp[0].size() << " " << (k*2+1+j/m1)%dp[0].size() << endl;
        if (x > y) swap(x, y);
        nxt[j][k] = (S[y-x-1] == '0' ? x : y);
      }
      REP(k, nxt[j].size()) {
//        cout << nxt[j][k] << " ";
      }
//      cout << endl;
    }
    m1 *= 2;
//    cout << endl;
    swap(nxt, dp);
  }
  REP(i, dp.size()) {
    REP(j, dp[i].size()) {
      cout << dp[i][j] << endl;
    }
  }
}

