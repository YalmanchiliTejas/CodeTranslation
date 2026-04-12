#include <iostream>
using namespace std;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

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
mint dp[MAX_N][MAX_D][2];
bool visited[MAX_N][MAX_D][2];
mint dfs(int i, int r, bool lower) {
  if (!(K.size() - i)) return r == 0;
  if (visited[i][r][lower]) return dp[i][r][lower];

  int n = K[i] - '0';
  mint ans = 0;
  rep(j, (lower ? 9 : n) + 1) {
    ans += dfs(i+1, (r+j) % D, lower || (j < n));
  }
  visited[i][r][lower] = true;
  return dp[i][r][lower] = ans;
}

int main() {
  cin >> K >> D;

  cout << dfs(0, 0, false)-1 << endl;

  return 0;
}
