#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define double long double
#define rep(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define repeq(i,a,b) for(int i=(int)(a); i<=(int)(b); ++i)
#define rrep(i,a,b) for(int i=(int)(a)-1; i>=(int)(b); --i)
#define rrepeq(i,a,b) for(int i=(int)(a); i>=(int)(b); --i)
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
template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for(auto itr = vec.begin(); itr != vec.end(); ++itr) is >> *itr; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { if(vec.empty()) return os; bool pl = is_plural<T>(); os << vec.front(); for(auto itr = ++vec.begin(); itr != vec.end(); ++itr) os << interval[pl] << *itr; return os; }

bool CoutYN(bool a, string y = "Yes", string n = "No") { cout << (a ? y : n) << "\n"; return a; }

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

long long modpow(int a, long long n, int mod = MOD) { long long ret = 1; do { if(n & 1) ret = ret * a % mod; a = 1LL * a * a % mod; } while(n >>= 1); return ret; }

template<typename T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<typename T> T LCM(T a, T b) { return a / GCD(a, b) * b; }

template<typename T1, typename T2> bool CompareBySecond(pair<T1, T2> a, pair<T1, T2> b) { return a.second != b.second ? a.second < b.second : a.first < b.first; }
template<typename T1, typename T2> bool CompareByInverse(pair<T1, T2> a, pair<T1, T2> b) { return a.first != b.first ? a.first < b.first : a.second > b.second; }


/* -------- <templates end> -------- */


void solve() {
  ll n; int x, m; cin >> n >> x >> m;

  int cnt = 0;
  vi dp({x}); dp.reserve(m);
  vi pos(m, -1);
  pos[x] = 0;

  while(++cnt < n) {
    x = 1LL * x * x % m;

    if(pos[x] != -1) {
      ll loop = (n - cnt) / (cnt - pos[x]);
      int rest = (n - cnt) % (cnt - pos[x]);
      ll sum = accumulate(begin(dp) + pos[x], end(dp), 0LL);
      ll ans = accumulate(ALL(dp), 0LL);
      ans += sum * loop;
      ans += accumulate(begin(dp) + pos[x], begin(dp) + (pos[x] + rest), 0LL);
      cout << ans << endl;
      return;
    }

    dp.emplace_back(x);
    pos[x] = cnt;
  }

  cout << accumulate(ALL(dp), 0LL) << endl;
}


/* -------- <programs end> -------- */


signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
