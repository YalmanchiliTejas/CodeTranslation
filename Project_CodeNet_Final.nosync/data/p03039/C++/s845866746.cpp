#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
const int MAX_N = 200010;

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

template< typename T >
class NumberOfCase {
    public:
        // 初期化 O(n log m) m は素数
        // n : 求めたい組み合わせの最大値
        NumberOfCase(ll n) : m_Size(n) {
            m_Fact.resize(m_Size + 1);
            m_FInv.resize(m_Size + 1);
            m_Inv.resize(m_Size + 1);
            // 0! ～ m_Size! までの階乗を保管する配列の作成 (mod m_Mod をとってある)
            m_Fact[0] = 1;
            for(int i = 1; i <= m_Size; ++i) { m_Fact[i] = m_Fact[i-1] * i; }
            // m_Size! の逆元 1/m_Size! を二分累乗法で求める
            // フェルマーの小定理より a^-1 = a^(p-2) mod p -> (m_Size!)^-1 = (m_Size!)^(p-2) mod p
            m_FInv[m_Size] = T(1) / m_Fact[m_Size];
            // 以下 1 / (N-1)! = N / N! であることを利用
            for(int i = m_Size - 1; i >= 0; --i) { m_FInv[i] = m_FInv[i + 1] * (i + 1); }
            // 逆元の作成（割り算のとき利用）
            m_Inv[0] = 1;
            for(int i = 1; i <= m_Size; ++i) { m_Inv[i] = m_FInv[i] * m_Fact[i - 1]; }
        }
        // 階乗 n! の取得 O(1)
        T Factorial(ll n) const { return m_Fact[n]; }
        // n! の逆元の取得 O(1)
        T FInverse(ll n) const { return m_FInv[n]; }
        // 逆元の取得 O(1) or O(log MOD)
        T Inverse(ll n) const { return m_Inv[n]; }
        // 順列 nPr の取得 O(1)
        T Permutation(ll n, ll r) const {
            if(r < 0 || n < r) { return 0; }
            return m_Fact[n] * m_FInv[n - r];
        }
        // 組み合わせ nCr の取得 O(1)
        T Combination(ll n, ll r) const {
            if(r < 0 || n < r) { return 0; }
            return m_Fact[n] * m_FInv[r]  * m_FInv[n - r];
        }
        // 重複組み合わせ nHr の取得 O(1)
        T Homogen(ll n, ll r) const {
            if(n < 0 || r < 0) { return 0; }
            return (r == 0) ? 1 : Combination(r + n - 1, r);
        }
    private:
        const ll    m_Size;     // 導出する範囲 (10^5 くらいまでにして欲しい)
        vector<T>  m_Fact;     // 階乗
        vector<T>  m_FInv;     // 階乗の逆元
        vector<T>  m_Inv;      // 逆元
};

int N, M, K;

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;

    NumberOfCase<modint> noc(MAX_N);

    // 2 つのコマを使う
    // 2 つのコマ以外の置き方のパターン数
    modint another = noc.Combination(N * M - 2, K - 2);

    modint ans(0);
    // x 座標について
    for(int i = 1; i < M; ++i) {
        // 2 つのコマの x 座標の差が i になるパターン数
        modint pat((M - i) * N * N);
        pat *= i;
        
        ans += pat;
    }

    // y 座標について
    for(int i = 1; i < N; ++i) {
        modint pat((N - i) * M * M);
        pat *= i;
        ans += pat;
    }

    ans *= another;

    cout << ans << endl;

    return 0;
}