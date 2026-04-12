#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
//typedef vector<vector<ll>> Graph;

//const ll mod = 1e9 + 7;
const ll mod = 998244353;

#define REP(i,n) for(ll i=0;i<(ll)n;i++)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define spa << " " <<
#define fi first
#define se second

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

template<typename T> void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++)
{cerr<<v[i][0];for(ll j=1;j<w;j++)cerr spa v[i][j];cerr<<endl;}};
template<typename T> void debug(vector<T>&v,ll n){if(n!=0)cerr<<v[0];
for(ll i=1;i<n;i++)cerr spa v[i];
cerr<<endl;};

template <std::uint_fast64_t Modulus> class modint {
  // long long から modint を作るときは必ず正の数にしてからコンストラクタに入れること！ 
  // そうしないとバグります
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
using mint = modint<mod>;
using vm = vector<mint>;
using vvm = vector<vm>;

ostream& operator << (ostream& os, const mint v){
os << v.value(); return os;
}

template <class T, class U> constexpr T power(T x, U exp) {
  T ret = static_cast<T>(1);
  while (exp) {
    if (exp % static_cast<U>(2) == static_cast<U>(1))
      ret *= x;
    exp /= static_cast<U>(2);
    x *= x;
  }
  return ::std::move(ret);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, S;
    cin >> N >> S;
    vl A(N);
    REP(i, N) cin >> A[i];

    vvm dp(3, vm(S+1, 0));
    dp[0][0] = 1;

    REP(i, N){
        vvm td(3, vm(S+1, 0));
        REP(j, S+1){
            td[0][j] += dp[0][j];
            if(j+A[i]<=S) td[1][j+A[i]] += dp[0][j];
            td[1][j] += dp[0][j];

            if(j+A[i]<=S) td[1][j+A[i]] += dp[1][j];
            td[1][j] += dp[1][j];
            td[2][j] += dp[1][j];

            td[2][j] += dp[2][j];
        }
        swap(dp, td);
    }

    mint res = 0;
    REP(i, 3) res += dp[i][S];
    cout << res << endl;

    return 0;
}