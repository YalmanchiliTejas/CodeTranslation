#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
#define int ll
#define IOS\
    ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SORT(name) sort(name.begin(), name.end())
#define RSORT(name)\
    SORT(name);\
    reverse(all(name));
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
template <class T> inline void print(T x){ cout << x << '\n';}
template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 998244353;
 
#pragma endregion

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
      x = (int) (1LL * x * p.x % mod);
      return *this;
  }

  ModInt &operator/=(const ModInt &p) {
      *this *= p.inverse();
      return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
      int a = x, b = mod, u = 1, v = 0, t;
      while(b > 0) {
          t = a / b;
          swap(a -= t * b, b);
          swap(u -= t * v, v);
      }
      return ModInt(u);
  }

  ModInt pow(int64_t n) const {
      ModInt ret(1), mul(x);
      while(n > 0) {
          if(n & 1) ret *= mul;
          mul *= mul;
          n >>= 1;
      }
      return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
      return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
      int64_t t;
      is >> t;
      a = ModInt< mod >(t);
      return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< MOD >;

const int MAX_N = 3010;

int N, S;
V<> A;

int dp[MAX_N][MAX_N][3];

// i 番目を見ていて、現在の値が j
// ステータスが k の時の f(L, R) の和
// k = 0: まだ左端を選んでいない
// k = 1: 左端を選んだが右端は選んでいない
// k = 2: 右端も選んだ
modint dfs(int i, int j, int k) {
    if(i >= N) {
        return (k == 2 && j == S) ? 1 : 0;
    }

    int& val = dp[i][j][k];
    if(~val) { return val; }
    modint ret(0);

    if(k == 0) {
        if(j + A[i] <= S) {
            // ここを左端にする
            ret += dfs(i + 1, j + A[i], 1) * modint(i + 1);
            // ここを左端であり右端にする（要素 1 つ）
            ret += dfs(i + 1, j + A[i], 2) * modint(i + 1) * modint(N - i);
        }
    }
    else if(k == 1) {
        if(j + A[i] <= S) {
            // ここを右端にする
            ret += dfs(i + 1, j + A[i], 2) * modint(N - i);
            // 右端にはしないが、取りはする
            ret += dfs(i + 1, j + A[i], k);
        }
    }
    // まだ選ばない／全て選択済み
    ret += dfs(i + 1, j, k);

    val = ret.x;

    return ret;
}

signed main() {
    IOS;
    cin >> N >> S;
    A.resize(N);
    REP(i, N) { cin >> A[i]; }

    MINUS(dp);
    auto ans = dfs(0, 0, 0);

    print(ans);

    return 0;
}
