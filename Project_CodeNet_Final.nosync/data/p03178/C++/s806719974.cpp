#include <iostream>
using namespace std;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define rrep(i,n) for(long long i=(n);i>=0;--i)

template<int MOD> struct MInt {
  long long val;
  constexpr MInt(long long val = 0) : val(val % MOD) { if (val < 0) val += MOD; }
  MInt operator-() const { return MInt(-val); }
  MInt operator+(const MInt& n) const { return MInt(val) += n; }
  MInt operator-(const MInt& n) const { return MInt(val) -= n; }
  MInt& operator+=(const MInt& n) { val = (val + n.val) % MOD; return *this; }
  MInt& operator-=(const MInt& n) { val = (MOD + val - n.val) % MOD; return *this; }
  friend ostream& operator<<(ostream& os, const MInt& n) { os<<n.val; return os; }
  friend istream& operator>>(istream& os, MInt& n) { os>>n.val; return os; }
};
constexpr int MOD = 1e9+7;
using mint = MInt<MOD>;

string K;
int D;
constexpr int MAX_N = 10000, MAX_D = 100;
mint dp[MAX_N+1][MAX_D][2];

int main() {
  cin >> K >> D;

  dp[K.size()][0][0] = dp[K.size()][0][1] = 1;

  rrep(i, K.size()-1) rep(r, D) rep(lower, 2) {
    int n = K[i] - '0';
    rep(j, (lower ? 9 : n) + 1)
      dp[i][r][lower] += dp[i+1][(r+j)%D][lower||(j<n)];
  }

  cout << dp[0][0][false]-1 << endl;

  return 0;
}
