#include <iostream>

using namespace std;
using ll = long long;

template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const int MOD = 1e9+7;

using mint = ModInt<MOD>;

mint dp[10101][101][2];
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  string K;
  int D;
  cin >> K >> D;
  int N = K.length();

  // dp[dgt][r][isless] = 上からdgt桁目まで決めたときの総数。islessが1ならKより確定で小さい。rは総和をDで割ったあまり
  REP(i, 10005) REP(j, D) REP(k, 2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  REP(dgt, N) REP(isless, 2) REP(r, D) {
    int c = K[dgt] - '0';
    REP(d, (isless?9:c)+1) {
      dp[dgt+1][(r+d)%D][isless || (d < c)] += dp[dgt][r][isless];
    }
  }
  cout << dp[N][0][0] + dp[N][0][1] - 1 << "\n";

  return 0;
}
