#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <ios>
#include <iomanip>
#include <algorithm>
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
#define bit_check(bit, i) ((bit>>(i)) & 1)
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL(a)), (a).end());} while(0)
#define MAX(a) *max_element(ALL(a))
#define MIN(a) *min_element(ALL(a))
#define bisect_left(a, x) lower_bound(ALL(a), (x)) - a.begin()
#define bisect_right(a, x) upper_bound(ALL(a), (x)) - a.begin()
#define INPUT(a) REP(i, a.size()) cin >> a[i];
#define INPUTP(a) REP(i, a.size()) cin >> a[i].first >> a[i].second;
#define OUTPUT_PERMUTATION(n) do{VI v(n); iota(ALL(v), 1); do{REPx(x, v) cout << x << " "; ENDL} while(next_permutation(ALL(v)));} while(0);
#define MAKE_PERMUTATION(n) do{VVI a(fact(n), VI(n)); int idx = 0; VI v(n); iota(ALL(v), 1); do{REP(roop, n) a[idx][roop] = v[roop]; idx++;} while(next_permutation(ALL(v))); PER = a;} while(0); // int fact(), VVI PERを宣言しておく
#define ENDL cout << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using PII = pair<int, int>;
using VPII = vector<PII>;
using PLL = pair<LL, LL>;
using VPLL = vector<PLL>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VC = vector<char>;
using VVC = vector<VC>;
using VS = vector<string>;
using VVS = vector<VS>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
const int INF = 1e9;
const LL MOD = 1e9 + 7;

template<class T> inline bool chmin(T &a, T b){if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){if (a < b) {a = b; return true;} return false;}

void END(){cout << 1 << endl; exit(0);}

int fact(int n)
{
  if (n == 0) return 1;
  return n * fact(n-1);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  VVB G(n, VB(n, false));
  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a][b] = true;
    G[b][a] = true;
  }
  int ans = 0;
  VVI PER;
  MAKE_PERMUTATION(n-1);
  REPx(x, PER)
  {
    if (!G[0][x[0]]) continue;
    bool flg = true;
    REP(i, n-2)
    {
      if (!G[x[i]][x[i+1]])
      {
        flg = false;
        break;
      }
    }
    if (flg) ans++;
  }
  cout << ans << endl;

  return 0;
}