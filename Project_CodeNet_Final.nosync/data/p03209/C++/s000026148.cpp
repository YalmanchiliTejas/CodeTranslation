#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

using ll = int_fast64_t;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<T>;
using vi = vt<int>;
using vvi = vvt<int>;
using vl = vt<ll>;
using vvl = vvt<ll>;
using pi = pair<int, int>;

constexpr int INF = 1 << 29; // 2倍するとオーバーフローする
// constexpr ll INFL = 1 << 58;
constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

// [a, b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (b)-1; i >= (a); i--)
// [a, b]
#define RANGE(i, a, b) for (int i = (a); i <= (b); i++)
#define RANGER(i, a, b) for (int i = (b); i >= (a); i--)
// [0, n)
#define REP(i, n) FOR(i, 0, (n))
#define REPR(i, n) RFOR(i, 0, (n))

#define ALL(i) i.begin(), i.end()

inline int gint() {
  int a;
  cin >> a;
  return a;
}

int main() {
  int N;
  ll X; // [1,4503599627370493]
  cin >> N >> X;
  auto all_count = vl(N);
  all_count[0] = 1;
  FOR(i, 1, N) all_count[i] = all_count[i - 1] * 2 + 3;

  auto pate_count = vl(N);
  pate_count[0] = 1;
  FOR(i, 1, N) pate_count[i] = pate_count[i - 1] * 2 + 1;

  ll result = 0;
  FORR(i, 0, N) {
    X -= 1;                  // 最下層のパン
    if (X >= all_count[i]) { // 下のレベル低いバーガーをすべて食べる
      X -= all_count[i];
      result += pate_count[i];
      cerr << "Eat 1 #" << i << " X:" << X << endl;
      if (X > 0) {
        X--; // 間のパンを食べる
        result++;
      } else
        break; // 食べきった
      cerr << "Eat 2 #" << i << " X:" << X << endl;

      if (X >= all_count[i]) { // 上のレベル低いバーガーをすべて食べる
        X -= all_count[i];
        result += pate_count[i];
        cerr << "Eat 3 #" << i << " X:" << X << endl;

        break; // Xは、1か0なはず。
      }
    }
  }

  cout << result << endl;
}