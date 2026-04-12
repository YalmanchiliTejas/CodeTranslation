#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP2(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define REPR(i, n) for (int i = (n)-1; i >= 0; --i)
#define REPR2(i, m, n) for (int i = (n)-1; i >= (m); --i)
#define REPx(x, a) for(auto x : a)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define SORTR(a) sort(ALL(a), greater<int>())
#define REVERSE(a) reverse(ALL(a))
#define bit_search(bit, n) REP(bit, 1<<(n))
#define bit_check(bit, i) (bit>>(i)) & 1
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL(a)), (a).end());} while(0)
#define MAX(a) *max_element(ALL(a))
#define MIN(a) *min_element(ALL(a))
#define bisect_left(a, x) lower_bound(ALL(a), (x)) - a.begin()
#define bisect_right(a, x) upper_bound(ALL(a), (x)) - a.begin()
#define INPUT(a) REP(i, a.size()) cin >> a[i];
#define INPUTP(a) REP(i, a.size()) cin >> a[i].first >> a[i].second;
#define ENDL cout << endl;
using namespace std;
using LL = long long;
using ld = long double;
using PII = pair<int, int>;
using VPII = vector<PII>;
using PLL = pair<LL, LL>;
using VPLL = vector<PLL>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VC = vector<char>;
using VS = vector<string>;
using VB = vector<bool>;
const LL INF = 1e14;
const LL MOD = 1e9 + 7;

template<class T> inline bool chmin(T &a, T b){if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){if (a < b) {a = b; return true;} return false;}

LL calc_dp(auto i, auto j, auto &dp, auto &N, auto &a)
{
  if (dp[i][j] != INF) return dp[i][j];
  if (i > j) return dp[i][j] = 0;
  else if(i == j)
  {
    if ((N-(j-i+1)) % 2 == 0) return dp[i][j] = a[i];
    else return dp[i][j] = -a[i];
  }
  else
  {
    if ((N-(j-i+1)) % 2 == 0) return dp[i][j] = max(calc_dp(i, j-1, dp, N, a)+a[j], calc_dp(i+1, j, dp, N, a)+a[i]);
    else return dp[i][j] = min(calc_dp(i, j-1, dp, N, a)-a[j], calc_dp(i+1, j, dp, N, a)-a[i]);
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  LL N;
  cin >> N;
  VLL a(N);
  INPUT(a);
  VVLL dp(N, VLL(N, INF));
  cout << calc_dp(0, N-1, dp, N, a) << endl;

  return 0;
}