#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

template<int MOD> struct MInt {
  long long val;
  MInt(long long val = 0) : val(val % MOD) { if (val < 0) val += MOD; }
  MInt operator-() const { return MInt(-val); }
  MInt operator+(const MInt& n) const { return MInt(val) += n; } MInt& operator+=(const MInt& n) { val = (val + n.val) % MOD; return *this; }
  MInt operator-(const MInt& n) const { return MInt(val) -= n; } MInt& operator-=(const MInt& n) { val = (MOD + val - n.val) % MOD; return *this; }
  friend ostream& operator<<(ostream& os, const MInt& n) { os<<n.val; return os; }
  friend istream& operator>>(istream& os, MInt& n) { os>>n.val; return os; }
};
using mint = MInt<1000000007>;

int N, D;
string S;
mint dp[10001][2][100];
bool visited[10001][2][100];
mint dfs(int i, bool lower, int r) {
  r %= D;
  if (visited[i][lower][r]) return dp[i][lower][r];
  if (i == N) return r == 0;

  int d = S[i]-'0';
  mint ans = 0;
  rep(j, (lower ? 9 : d)+1)
    ans += dfs(i+1, lower || (j < d), r+j);

  visited[i][lower][r] = true;
  return dp[i][lower][r] = ans;
}

int main() {
  cin >> S >> D;
  N = S.size();

  cout << dfs(0, false, 0) - 1 << endl;

  return 0;
}
