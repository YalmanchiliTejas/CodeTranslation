#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
//const ull mod = 1e9 + 7;
const ll mod = 998244353;
#define REP(i,n) for(int i=0;i<(int)n;++i)

// debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

// conversion number to bit
string num2bit(ll num, ll len){
  string bit = "";
  REP(i, len){
    bit += char('0'+(num>>i & 1));
  }
  return bit;
}

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

ll dp[3030][3030];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    using mint = modint<mod>;

    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    mint res = 0;
    vector<vector<mint>> dp(3030, vector<mint>(3030, 0));
    dp[0][0] = 1;
    REP(i, N){
    	REP(j, 3030){
    		dp[i+1][j] += dp[i][j];
        if(j==0){
          if(j+A[i]<3030) dp[i+1][j+A[i]] += dp[i][j] * (i+1);
        }else{
          if(j+A[i]<3030) dp[i+1][j+A[i]] += dp[i][j];
        }
    	}
      res += dp[i+1][S];
    }
    cout << res.value() << endl;

    /*
    REP(i, N+1){
      REP(j, S+1){
        cout << dp[i][j].value() << " ";
      }
      cout << endl;
    }
    */
    return 0;
}