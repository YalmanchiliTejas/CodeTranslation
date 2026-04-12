#pragma region
// Author: Wenxing Mei
//   Date: 2018-08-25 20:05
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// using namespace __gnu_pbds;
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define repv(ele, vec) for (auto &ele : vec)
#define zero(mem) memset(mem, 0, sizeof(mem))
#define sd(_) scanf("%d", &_)
#define sdd(_, __) scanf("%d%d", &_, &__)
#define sddd(_, __, ___) scanf("%d%d%d", &_, &__, &___)
#define sdddd(_, __, ___, ____) scanf("%d%d%d%d", &_, &__, &___, &____)
#define sf(_) scanf("%lf", &_)
#define sff(_, __) scanf("%lf%lf", &_, &__)
#define sfff(_, __, ___) scanf("%lf%lf%lf", &_, &__, &___)
#define sffff(_, __, ___, ____) scanf("%lf%lf%lf%lf", &_, &__, &___, &____)
#define sl(_) scanf("%lld", &_)
#define sll(_, __) scanf("%lld%lld", &_, &__)
#define slll(_, __, ___) scanf("%lld%lld%lld", &_, &__, &___)
#define sllll(_, __, ___, ____) scanf("%lld%lld%lld%lld", &_, &__, &___, &____)
#define sc(_) scanf("%c", &_)
#define ss(_) scanf("%s", _)
#define sz(x) (int)(x).size()
#define mid(a, b) (((a) + (b)) >> 1)
#define lfg(x) x << 1
#define rht(x) x << 1 | 1
#define inf 0x3f3f3f3f
#define all(container) container.begin(), container.end()
//#define MOD 19260817
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define get0 get<0>
#define get1 get<1>
#define get2 get<2>
#define get3 get<3>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#pragma endregion

// Read the question correctly
// What are the exact constraints?
// Look out for SPECIAL CASES (n=1? n=1000000000?) and overflow (ull vs int?)

char g[200][200];

int main() {
  int h, w;
  sdd(h, w);
  zero(g);
  rep(i, 0, h) ss(g[i]);
  // rep(i, 0, h) { puts(g[i]); }
  set<int> empty_row, empty_col;
  rep(i, 0, h) {
    int empty = 1;
    rep(j, 0, w) {
      if (g[i][j] == '#') {
        empty = 0;
        break;
      }
    }
    if (empty) empty_row.insert(i);
  }
  rep(j, 0, w) {
    int empty = 1;
    rep(i, 0, h) {
      if (g[i][j] == '#') {
        empty = 0;
        break;
      }
    }
    if (empty) empty_col.insert(j);
  }

  rep(i, 0, h) {
    if (empty_row.count(i)) continue;
    rep(j, 0, w) {
      if (empty_col.count(j)) continue;
      putchar(g[i][j]);
    }
    puts("");
  }
  return 0;
}
