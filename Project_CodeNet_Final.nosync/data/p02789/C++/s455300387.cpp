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
#define bit_check(bit, i) (bit>>(i)) & 1
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL(a)), (a).end());} while(0)
#define MAX(a) *max_element(ALL(a))
#define MIN(a) *min_element(ALL(a))
#define bisect_left(a, x) lower_bound(ALL(a), (x)) - a.begin()
#define bisect_right(a, x) upper_bound(ALL(a), (x)) - a.begin()
#define INPUT(a) REP(i, a.size()) cin >> a[i];
#define INPUTP(a) REP(i, a.size()) cin >> a[i].first >> a[i].second;
#define OUTPUT_PERMUTATION(n) do{VI v(n); iota(ALL(v), 1); do{REPx(x, v) cout << x << " "; ENDL} while(next_permutation(ALL(v)));} while(0);
#define MAKE_PERMUTATION(n) do{VVI a(fact(n), VI(n)); int idx = 0; VI v(n); iota(ALL(v), 1); do{REP(i, n) a[idx][i] = v[i]; idx++; PER = a;} while(next_permutation(ALL(v)));} while(0); // int fact(), VVI PERを宣言しておく
#define ENDL cout << endl;
using namespace std;
using LL = long long;
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
using VS = vector<string>;
using VB = vector<bool>;
using VD = vector<double>;
const LL INF = 1e18;
const LL MOD = 1e9 + 7;

template<class T> inline bool chmin(T &a, T b){if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){if (a < b) {a = b; return true;} return false;}

void END(){cout << 1 << endl; exit(0);}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  if (n == m) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
