#include "bits/stdc++.h"
#define ALL(x) x.begin(), x.end()
#define LEN(x) (int)x.size()
#define iostreamBooster() do{ cin.tie(nullptr); ios_base::sync_with_stdio(false); }while(0)
using namespace std;
typedef int64_t i64;
typedef pair<int,int> pii;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF = 0x3f3f3f3f;

signed main()
{
  int h, w;
  char mat[105][105];
  cin >> h >> w;

  bool delRow[105]{};
  bool delCol[105]{};
  for (int i = 0; i < h; ++i) {
    cin >> mat[i];
    if (all_of(mat[i], mat[i]+w, [](char c){return c == '.';})) {
      delRow[i] = true;
    }
  }

  auto f = [&](int row) {
    for (int i = 0; i < h; ++i) if (mat[i][row] != '.') return false;
    return true;
  };

  for (int i = 0; i < w; ++i) {
    if (f(i)) delCol[i] = true;
  }

  for (int i = 0; i < h; ++i) {
    if (delRow[i]) continue;
    for (int j = 0; j < w; ++j) {
      if (!delCol[j]) putchar(mat[i][j]);
    }
    putchar('\n');
  }

  return 0;
}

