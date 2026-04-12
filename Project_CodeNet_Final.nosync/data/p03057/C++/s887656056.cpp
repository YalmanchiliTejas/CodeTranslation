#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define double long double
#define rep(i,a,b) for (int i=(int)(a); i<(int)(b); ++i)
#define repeq(i,a,b) for (int i=(int)(a); i<=(int)(b); ++i)
#define rrep(i,a,b) for (int i=(int)(a)-1; i>=(int)(b); --i)
#define rrepeq(i,a,b) for (int i=(int)(a); i>=(int)(b); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
template<typename T> using Graph = vector<vector<T>>;
template<typename T> using Spacial = vector<vector<vector<T>>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T> using greater_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const int MOD = 1e9+7;
const int MOD2 = 998244353;
// const double EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
string interval[2] = {" ", "\n"}; // {" ", "\n"}

template<typename T> struct is_plural : false_type{};
template<typename T1, typename T2> struct is_plural<pair<T1, T2>> : true_type{};
template<typename T> struct is_plural<vector<T>> : true_type{};
template<typename T> struct is_plural<complex<T>> : true_type{};
template<> struct is_plural<string> : true_type{};

template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << " " << p.second; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto itr = vec.begin(); itr != vec.end(); ++itr) is >> *itr; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { if (vec.empty()) return os; bool pl = is_plural<T>(); os << vec.front(); for (auto itr = ++vec.begin(); itr != vec.end(); ++itr) os << interval[pl] << *itr; return os; }

bool CoutYN(bool a, string y = "Yes", string n = "No") { cout << (a ? y : n) << "\n"; return a; }

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

long long modpow(int a, long long n, int mod = MOD) { long long ret = 1; do { if (n & 1) ret = ret * a % mod; a = 1LL * a * a % mod; } while (n >>= 1); return ret; }

template<typename T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<typename T> T LCM(T a, T b) { return a / GCD(a, b) * b; }

template<typename T1, typename T2> bool CompareBySecond(pair<T1, T2> a, pair<T1, T2> b) { return a.second != b.second ? a.second < b.second : a.first < b.first; }
template<typename T1, typename T2> bool CompareByInverse(pair<T1, T2> a, pair<T1, T2> b) { return a.first != b.first ? a.first < b.first : a.second > b.second; }


/* -------- <templates end> -------- */


template<uint_fast64_t Modulus = MOD>
struct Modint {
  using u64 = uint_fast64_t;
  u64 a;

  constexpr Modint(const u64 x = 0) noexcept : a(x % Modulus) {}

  constexpr Modint operator+(const Modint rhs) const noexcept {
    return Modint(*this) += rhs;
  }
  constexpr Modint operator-(const Modint rhs) const noexcept {
    return Modint(*this) -= rhs;
  }
  constexpr Modint operator*(const Modint rhs) const noexcept {
    return Modint(*this) *= rhs;
  }
  constexpr Modint operator/(const Modint rhs) const noexcept {
    return Modint(*this) /= rhs;
  }

  constexpr Modint &operator+=(const Modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) a -= Modulus;
    return *this;
  }
  constexpr Modint &operator-=(const Modint rhs) noexcept {
    if (a < rhs.a) a += Modulus;
    a -= rhs.a;
    return *this;
  }
  constexpr Modint &operator*=(const Modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr Modint &operator/=(Modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp & 1) *this *= rhs;
      rhs *= rhs;
      exp >>= 1;
    }
    return *this;
  }

  Modint pow(u64 t) const {
    if (!t) return 1;
    Modint x = pow(t>>1);
    x *= x;
    if (t&1) x *= *this;
    return x;
  }

  explicit operator bool() const {
    return a;
  }

  friend ostream &operator<<(ostream &os, const Modint &m) {
    return os << m.a;
  }
};

using mint = Modint<>;

template<typename T>
vector<pair<T, int>> prime_factor(T num) {
  vector<pair<T, int>> ret;
  for (T i=2; i*i<=num; ++i) {
    int cnt = 0;
    while (num%i == 0) {
      num /= i;
      ++cnt;
    }
    if (cnt != 0) ret.emplace_back(i, cnt);
  }
  if (num != 1) ret.emplace_back(num, 1);
  return ret;
}

// if (srt > 0), sorted by ascending order. else if (srt < 0), sorted by descending order.
template<typename T>
vector<T> divisor(const vector<pair<T, int>> &pf, int srt = 0) {
  vector<T> ret;
  ret.emplace_back(1);
  for (auto &p : pf) {
    int sz = ret.size();
    T x; int y;
    tie(x,y) = p;
    T d = 1;
    for (int i=0; i<y; ++i) {
      d *= x;
      for (int j=0; j<sz; ++j) {
        ret.emplace_back(d * ret[j]);
      }
    }
  }
  if (srt > 0) sort(ret.begin(), ret.end());
  else if (srt < 0) sort(ret.rbegin(), ret.rend());
  return ret;
}

template<typename T>
vector<T> divisor(const T &num, int srt = 0) {
  auto pf = prime_factor(num);
  return divisor(pf, srt);
}

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;

  int MAX = m;
  int now = 0;
  rep(i,0,m) {
    if (s[i] == s[0]) {
      ++now;
    } else {
      if (MAX == m) {
        MAX = now | 1;
      } else if (now & 1) {
        chmin(MAX, now);
      }
      now = 0;
    }
  }

  if (MAX == m) {
    Graph<mint> dp(n, vector<mint>(2, 0));
    dp[0][1] = 1;

    rep(i,1,n) {
      dp[i][0] = dp[i-1][0] + dp[i-1][1];
      dp[i][1] = dp[i-1][0];
    }

    mint ans = dp[n-1][0];

    dp.assign(n, vector<mint>(2, 0));
    dp[0][0] = 1;

    rep(i,1,n) {
      dp[i][0] = dp[i-1][0] + dp[i-1][1];
      dp[i][1] = dp[i-1][0];
    }

    ans += dp[n-1][0] + dp[n-1][1];

    cout << ans << endl;
    return;
  }

  if (n & 1) {
    cout << 0 << endl;
    return;
  }

  n /= 2;
  (MAX /= 2) += 1;

  auto div = divisor(n, 1);
  vector<pair<int, mint>> memo;

  for (auto &d : div) {
    vector<mint> dp(d+1, 0);
    dp[0] = 1;
    mint now = 1;

    repeq(i,1,d) {
      now += dp[i] = now;
      if (i >= MAX) now -= dp[i - MAX];
    }

    vector<mint> sum(d+2, 0);
    rep(i,1,d+2) sum[i] = sum[i-1] + dp[i-1];

    mint tmp = dp[d];
    int MIN = min(MAX, d);
    rep(i,1,MIN) {
      tmp += sum[d-i] - sum[d-MIN];
    }

    memo.emplace_back(d, tmp);
  }

  int sz = memo.size();

  rep(i,0,sz) {
    rep(j,i+1,sz) {
      if (memo[j].first % memo[i].first == 0) {
        memo[j].second -= memo[i].second;
      }
    }
  }

  mint ans = 0;
  for (auto &p : memo) {
    ans += p.second;
  }
  cout << ans * 2 << endl;
}


/* -------- <programs end> -------- */


signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
