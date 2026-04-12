#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define int i64
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

template <typename T>
T in() {
  T value;
  cin >> value;
  return value;
}

#undef int
int main() {
#define int i64
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a = in<int>();
  int b = in<int>();
  int c = in<int>();
  int x = in<int>();
  int y = in<int>();
  int ans = INF;
  rep(i, pow(10, 5) + 1) {
    int tmp = i * 2 * c + max((i64)(0), x - i) * a + max((i64)(0), y - i) * b;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}