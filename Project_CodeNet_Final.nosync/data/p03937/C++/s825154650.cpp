// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <cmath>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>
// #include <windows.h>
using namespace std;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = V<VV<T>>;
template<class T1, class T2> using P = pair<T1, T2>;
using I = int;
using D = double;
using B = bool;
using C = char;
using S = string;
using LL = long long;
using LD = long double;
using ULL = unsigned long long;
using PII = P<I, I>;
using VPII = V<PII>;
using PLL = P<LL, LL>;
using VPLL = V<PLL>;
using VI = V<I>;
using VVI = VV<I>;
using VLL = V<LL>;
using VVLL = VV<LL>;
using VC = V<C>;
using VVC = VV<C>;
using VS = V<S>;
using VVS = VV<S>;
using VB = V<B>;
using VVB = VV<B>;
#define REP(type, i, n) for (type i = 0; i < (type)(n); ++i)
#define REP2(type, i, m, n) for (type i = (m); i < (type)(n); ++i)
#define REPR(type, i, n) for (type i = (n)-1; i >= 0; --i)
#define REPR2(type, i, m, n) for (type i = (n)-1; i >= (m); --i)
#define REPx(x, a) for(auto x : a)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define SORTR(a, type) sort(ALL(a), greater<type>())
#define SORTF(a, comp) sort(ALL(a), comp)
#define REVERSE(a) reverse(ALL(a))
#define SIZE(a, type) ((type)(a).size())
#define bit_search(bit, n) REP(LL, bit, 1LL<<(n))
#define bit_check(bit, i) ((bit>>(i)) & 1)
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL(a)), (a).end());} while(0)
#define MAX(a) *max_element(ALL(a))
#define MIN(a) *min_element(ALL(a))
#define bisect_left(a, x) (lower_bound(ALL(a), (x)) - a.begin())
#define bisect_right(a, x) (upper_bound(ALL(a), (x)) - a.begin())
#define INPUT(a) REPx(&x, a) cin >> x;
#define INPUT2(a) REPx(&x, a) INPUT(x);
#define INPUTP(a) REPx(&x, a) cin >> x.first >> x.second;
#define ENDL cout << endl;

const int INF = 2e9;
// const LL INF = 9e18;
const LL MOD = 1e9+7;

template<class T> using PRIORITY_QUEUE = priority_queue< T, V<T>, greater<T> >;
template<class T> inline bool chmin(T &a, T b){if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){if (a < b) {a = b; return true;} return false;}
template<class T> inline void debug1(V<T> A){REP(int, i, SIZE(A, int)){if (A[i] == INF) cout << "I ";else cout << A[i] << " ";}ENDL}
template<class T> inline void debug2(VV<T> A){REP(int, i, SIZE(A, int)){REP(int, j, SIZE(A[i], int)){if (A[i][j] == INF) cout << "I "; else cout << A[i][j] << " ";}ENDL}}

int h, w;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> h >> w;
  VS A(h);
  INPUT(A);
  bool flg = false;

  // VS track(h);
  // string tmp = "";
  // REP(int, i, w) tmp += ".";
  // REP(int, i, h) track[i] = tmp;
  // ENDL

  REP(int, i, h) REP(int, j, w)
  {
    if (A[i][j] == '#')
    {
      if (j-1 >= 0 && i+1 < h)
      {
        REP2(int, k, i+1, h)
        {
          if (A[k][j-1] == '#')
          {
            flg = true;
            break;
          }
        }
      }
    }
  }
  REP(int, j, w) REP(int, i, h)
  {
    if (A[i][j] == '#')
    {
      if (i-1 >= 0 && j+1 < w)
      {
        REP2(int, k, j+1, w)
        {
          if (A[i-1][k] == '#')
          {
            flg = true;
            break;
          }
        }
      }
    }
  }
  if (flg) cout << "Impossible" << endl;
  else cout << "Possible" << endl;

  return 0;
}
