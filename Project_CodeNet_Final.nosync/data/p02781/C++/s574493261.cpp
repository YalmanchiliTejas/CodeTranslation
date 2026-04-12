#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define double long double
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep1(i,n) for (int i=1; i<(int)(n); ++i)
#define repeq(i,n) for (int i=0; i<=(int)(n); ++i)
#define rep1eq(i,n) for (int i=1; i<=(int)(n); ++i)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; --i)
#define rrep1(i,n) for (int i=(int)(n)-1; i>0; --i)
#define rrepeq(i,n) for (int i=(int)(n); i>=0; --i)
#define rrep1eq(i,n) for (int i=(int)(n); i>0; --i)
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
const int MOD = 1e9+7;
const int MOD2 = 998244353;
// const double EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
string interval[2] = {" ", "\n"};

template<typename T> struct is_plural : false_type{};
template<typename T1, typename T2> struct is_plural<pair<T1, T2>> : true_type{};
template<typename T> struct is_plural<vector<T>> : true_type{};
template<typename T> struct is_plural<complex<T>> : true_type{};

template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
} 
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << p.first << " " << p.second;
}
template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
    is >> *itr;
  }
  return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  if (vec.empty()) return os;
  bool pl = is_plural<T>();
  os << vec.front();
  for (auto itr = ++vec.begin(); itr != vec.end(); ++itr) {
    os << interval[pl] << *itr;
  }
  return os;
}

bool CoutYN(bool a, string y = "Yes", string n = "No") {
  cout << (a ? y : n) << "\n";
  return a;
}

template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

int modpow(int a, long long n, int mod = MOD) {
  int ret = 1;
  do {
    if (n & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
  } while (n >>= 1);
  return ret;
}

template<typename T>
T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<typename T>
T LCM(T a, T b) { return a / GCD(a, b) * b; }

template<typename T1, typename T2>
bool CompareBySecond(pair<T1, T2> a, pair<T1, T2> b) {
  return a.second != b.second ? a.second < b.second : a.first < b.first;
}
template<typename T>
bool CompareBySlope(pair<T, T> a, pair<T, T> b) {
// counterclockwise from 12 o'clock direction
  if (a.first * b.first < 0) return a.first < b.first;
  if (a.first == 0) return a.second >= 0 || b.first > 0;
  if (b.first == 0) return b.second < 0 && a.first < 0;
  return a.second * b.first < a.first * b.second;
}


/* -------- <templates end> -------- */


struct ModCombination {
  vector<long long> fac, finv, inv;
  const int MAX, mod;

  ModCombination(int n, int mod) : MAX(n+1), mod(mod) {
    fac.resize(MAX);  fac[0] = fac[1] = 1;
    finv.resize(MAX); finv[0] = finv[1] = 1;
    inv.resize(MAX);  inv[1] = 1;
    for (int i=2; i<MAX; ++i) {
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
      finv[i] = finv[i-1] * inv[i] % MOD;
    }
  }

  long long value(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * (finv[r] * finv[n-r] % mod) % mod;
  }
};

void solve() {
  string s; int k; cin >> s >> k;

  int sz = s.size();
  ModCombination comb(sz, MOD);
  vi pow9 = {9, 81, 729};
  ll ans = 0;

  for (int i=k; i<sz; ++i) {
    ans += comb.value(i-1, k-1) * pow9[k-1];
  }

  if (k == 1) {
    ans += s[0] - '0';
  } else if (k == 2 && sz >= 2) {
    ans += (s[0] - '1') * comb.value(sz-1, 1) * pow9[0];
    int idx = 1;
    while (idx < sz && s[idx] == '0') ++idx;
    if (idx < sz) {
      ans += s[idx++] - '0';
      ans += comb.value(sz-idx, 1) * pow9[0];
    }
  } else if (k == 3 && sz >= 3) {
    ans += (s[0] - '1') * comb.value(sz-1, 2) * pow9[1];
    int idx = 1;
    while (idx < sz && s[idx] == '0') ++idx;
    if (idx < sz) {
      ans += (s[idx++] - '1') * comb.value(sz-idx, 1) * pow9[0];
      ans += comb.value(sz-idx, 2) * pow9[1];
    }
    while (idx < sz && s[idx] == '0') ++idx;
    if (idx < sz) {
      ans += s[idx++] - '0';
      ans += comb.value(sz-idx, 1) * pow9[0];
    }
  }

  cout << ans << endl;
}


/* -------- <programs end> -------- */


signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  solve();
  return 0;
}
