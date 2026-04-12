#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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
const double EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template<typename T> struct is_pair : false_type{};
template<typename T1, typename T2> struct is_pair<pair<T1, T2>> : true_type{};
template<typename T> struct is_vector : false_type{};
template<typename T> struct is_vector<vector<T>> : true_type{};

template<typename T1, typename T2>
istream &operator >> (istream &istr, pair<T1, T2> &p) {
  istr >> p.first >> p.second;
  return istr;
} 
template<typename T1, typename T2>
ostream &operator << (ostream &ostr, const pair<T1, T2> &p) {
  ostr << p.first << " " << p.second;
  return ostr;
}
template<typename T>
istream &operator >> (istream &istr, vector<T> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
    istr >> *itr;
  }
  return istr;
}
template<typename T>
ostream &operator << (ostream &ostr, const vector<T> &vec) {
  if (vec.empty()) return ostr;
  bool vp = is_vector<T>() || is_pair<T>();
  ostr << vec.front();
  for (auto itr = ++vec.begin(); itr != vec.end(); ++itr) {
    ostr << (vp ? "\n" : " ") << *itr;
  }
  return ostr;
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


void solve() {
  int n, m; cin >> n >> m;
  cout << (n==m ? "Yes\n" : "No\n");
}


/* -------- <programs end> -------- */


signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  solve();
  return 0;
}
