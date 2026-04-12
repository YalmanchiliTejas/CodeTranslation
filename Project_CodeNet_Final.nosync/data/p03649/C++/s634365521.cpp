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


/* -------- <templates end> -------- */


void solve() {
  int n; cin >> n;
  vl arr(n); cin >> arr;

  ll ans = 0;
  ll MIN;

  do {
    ll cnt = 0;

    rep(i,n) {
      if (arr[i] < n) continue;

      ll tmp = (arr[i] - n) / (n + 1);
      cnt += tmp;
      arr[i] -= tmp * (n + 1);
    }

    if (cnt == 0) break;

    ans += cnt;

    rep(i,n) {
      arr[i] += cnt;
    }

    MIN = *min_element(ALL(arr));

  } while (MIN < n);

  if (MIN > n) {
    ll dec = MIN - n;

    ans += dec * n;

    rep(i,n) {
      arr[i] -= dec;
    }
  }

  ll comp = -1;

  while (comp != ans) {
    comp = ans;

    rep(i,n) {
      if (arr[i] < n) continue;

      ans++;

      arr[i] -= n + 1;

      rep(j,n) {
        arr[j]++;
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
