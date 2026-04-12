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
#define REP(i,a,b) for (int i=(int)(a); i<=(int)(b); ++i)
#define RREP(i,a,b) for (int i=(int)(a); i>=(int)(b); --i)
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
string interval[2] = {" ", "\n"}; // {" ", "\n"}

template<typename T> struct is_plural : false_type{};
template<typename T1, typename T2> struct is_plural<pair<T1, T2>> : true_type{};
template<typename T> struct is_plural<vector<T>> : true_type{};
template<typename T> struct is_plural<complex<T>> : true_type{};
 
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
// counterclockwise from 12 o'clock direction
template<typename T> bool CompareBySlope(pair<T, T> a, pair<T, T> b) { if (a.first * b.first < 0) return a.first < b.first; if (a.first == 0) return a.second >= 0 || b.first > 0; if (b.first == 0) return b.second < 0 && a.first < 0; return a.second * b.first < a.first * b.second; }


/* -------- <templates end> -------- */


void solve() {
  int n; cin >> n;
  vi s(n), t(n); cin >> s >> t;
  vector<bitset<64>> u(n), v(n);
  rep(i,n) {
    uint64_t p; cin >> p;
    u[i] = p;
  }
  rep(i,n) {
    uint64_t p; cin >> p;
    v[i] = p;
  }

  Spacial<int> g(64, Graph<int>(n, vi(n, -1)));

  rep(i,64) {
    vi unused_s, unused_t;

    rep(j,n) {
      if (s[j] ^ u[j][i]) {
        int tmp = u[j][i];
        rep(k,n) {
          g[i][j][k] = tmp;
        }
      } else {
        unused_s.emplace_back(j);
      }
    }

    rep(k,n) {
      if (t[k] ^ v[k][i]) {
        int tmp = v[k][i];
        rep(j,n) {
          if (g[i][j][k] == 1 - tmp) {
            cout << -1 << endl;
            return;
          }
          g[i][j][k] = tmp;
        }
      } else {
        unused_t.emplace_back(k);
      }
    }

    int cnt_s = unused_s.size();
    int cnt_t = unused_t.size();

    if (cnt_s == 0) {
      for (auto &k : unused_t) {
        int tmp = v[k][i];
        bool p = false;
        rep(j,n) {
          p |= g[i][j][k] == tmp;
        }
        if (!p) {
          cout << -1 << endl;
          return;
        }
      }
    }

    else if (cnt_t == 0) {
      for (auto &j : unused_s) {
        int tmp = u[j][i];
        bool p = false;
        rep(k,n) {
          p |= g[i][j][k] == tmp;
        }
        if (!p) {
          cout << -1 << endl;
          return;
        }
      }
    }

    else if (cnt_s == 1) {
      int a = unused_s[0];
      int tar = u[a][i];
      for (auto &k : unused_t) {
        int tmp = v[k][i];
        bool p = false;
        rep(j,n) {
          p |= g[i][j][k] == tmp;
        }
        g[i][a][k] = p ? tar : tmp;
      }
      bool p = false;
      rep(k,n) {
        p |= g[i][a][k] == tar;
      }
      if (!p) {
        cout << -1 << endl;
        return;
      }
    }

    else if (cnt_t == 1) {
      int a = unused_t[0];
      int tar = v[a][i];
      for (auto &j : unused_s) {
        int tmp = u[j][i];
        bool p = false;
        rep(k,n) {
          p |= g[i][j][k] == tmp;
        }
        g[i][j][a] = p ? tar : tmp;
      }
      bool p = false;
      rep(j,n) {
        p |= g[i][j][a] == tar;
      }
      if (!p) {
        cout << -1 << endl;
        return;
      }
    }

    else {
      int tar = 1;
      for (auto &j : unused_s) {
        int tmp = tar;
        for (auto &k : unused_t) {
          g[i][j][k] = tmp;
          tmp = 1 - tmp;
        }
        tar = 1 - tar;
      }
    }
  }

  Graph<uint64_t> ans(n, vector<uint64_t>(n, 0));
  rep(i,64) {
    rep(j,n) {
      rep(k,n) {
        if (g[i][j][k]) ans[j][k] += 1ULL << i;
      }
    }
  }

  cout << ans << endl;
}


/* -------- <programs end> -------- */


signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
