#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using vi = vector<int>;

#define in(v) v; cin >> v;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}

#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

// debug
template<class T>ostream& operator<<(ostream& os,const vector<T>& vec){os<<"{";for(size_t i=0;i<vec.size();++i)os<<(i?", ":"")<<vec[i];os<<"}";return os;}
ostream& operator<<(ostream& os,const vector<char>&v){for(size_t i=0;i<v.size();++i)os<<v[i];return os;}
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>& rhs){os<<"("<<rhs.first<<", "<<rhs.second<<")";return os;}

#ifdef LOCAL
void debug() {cerr << "\n";}
template<class First> void debug(const First& first) {cerr<<first<<"\n";}
template<class First, class... Rest> void debug(const First& first, const Rest&... rest) {cerr<<first<<",";debug(rest...);}
void debug2() {cerr << "\n";}
template<class First> void debug2(const First& first) {cerr<<first<<" ";}
template<class First, class... Rest> void debug2(const First& first, const Rest&... rest) {cerr<<first<<" ";debug2(rest...);}
#else
#define debug(...) 42
#define debug2(...) 42
#endif

template<int MOD> struct MInt {
  long long val;
  MInt(long long val = 0) : val(val % MOD) { if (val < 0) val += MOD; }
  MInt operator-() const { return MInt(-val); }
  MInt operator+(const MInt& n) const { return MInt(val) += n; } MInt& operator+=(const MInt& n) { val = (val + n.val) % MOD; return *this; }
  MInt operator-(const MInt& n) const { return MInt(val) -= n; } MInt& operator-=(const MInt& n) { val = (MOD + val - n.val) % MOD; return *this; }
  MInt operator*(const MInt& n) const { return MInt(val) *= n; } MInt& operator*=(const MInt& n) { val = (val * n.val) % MOD; return *this; }
  MInt operator/(const MInt& n) const { return MInt(val) /= n; } MInt& operator/=(const MInt& n) { val = (*this * n.inv()).val; return *this; }
  bool operator==(const MInt& n) { return val == n.val; }
  bool operator!=(const MInt& n) { return val != n.val; }
  MInt pow(long long n) const {
    MInt pow = val, ans = 1;
    for (long long p = n; p > 0; p >>= 1, pow *= pow)
      if (p & 1) ans *= pow;
    return ans;
  }
  MInt inv() const { return pow(MOD-2); }
  friend ostream& operator<<(ostream& os, const MInt& n) { os<<n.val; return os; }
  friend istream& operator>>(istream& os, MInt& n) { os>>n.val; return os; }
};
using mint = MInt<1000000007>;

int N, D;
string S;
mint dp[10001][2][100];
bool visited[10001][2][100];
mint dfs(int i, bool lower, int r) {
  // 上からi番目までの数字を決めた。
  // r: ここまで時点での余り
  r %= D;
  if (visited[i][lower][r])
    return dp[i][lower][r];
  if (i == N)
    return r == 0;
  mint ans = 0;
  if (lower) {
    rep(j, 10)
      ans += dfs(i+1, true, r+j);
    visited[i][lower][r] = true;
    return dp[i][lower][r] = ans;
  }
  int d = S[i]-'0';
  rep(j, d+1)
    ans += dfs(i+1, j < d, r+j);
  visited[i][lower][r] = true;
  return dp[i][lower][r] = ans;
}

int main() {
  in(S);
  N = S.size();
  in(D);

  cout << dfs(0, false, 0) - 1 << endl;

  return 0;
}
