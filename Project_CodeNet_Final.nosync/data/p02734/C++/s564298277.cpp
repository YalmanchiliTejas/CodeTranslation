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

void step(string& s) {
  string t(s.size()-1, '0');
  REP(i, s.size()-1) {
    t[i] += abs(s[i]-s[i+1]);
  }
  swap(s, t);
}

// 1-stepすすめると0, 1, 2だけになる
//

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

int comb_parity(int64 a, int64 b) {
  int64 ret = 1;
  while (a) {
    if (a%2 == 0 && b%2) ret = 0;
    a /= 2;
    b /= 2;
  }
  return ret;
}

bool is_palindrome(const string& s) {
  REP(i, s.size()/2) {
    if (s[i] != s[s.size()-i-1]) return 0;
  }
  return 1;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64 N, S;
  cin >> N >> S;
  vector<int64> A(N);
  REP(i, N) cin >> A[i];

  Mint res = 0;

  auto dp = make_v<Mint>(N+1, S+1);
  fill_v<Mint>(dp, 0);
  dp[0][0] = 1;
  REP(i, N) {
    REP(j, S) {
      int64 nxt = j + A[i];
      dp[i+1][j] += dp[i][j];
      if (nxt > S) continue;
      if (nxt == S) {
        res += dp[i][j] * (N-i);
      } else {
        dp[i+1][nxt] += dp[i][j];
      }
    }
    dp[i+1][0]++;
  }
  cout << res << endl;
}

