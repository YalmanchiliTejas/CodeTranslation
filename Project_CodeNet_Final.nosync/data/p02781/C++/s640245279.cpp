#include <bits/stdc++.h>
//#define TASK "file"

#define F first
#define S second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long i64;
typedef long double dbl;
const dbl PI = acos(-1.0L);
const dbl EPS = 1e-12L;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

namespace task {
string s, w;
int k;
i64 r;

int main() {
  cin >> s >> k;
  for (int i = k; i < s.size(); ++i) {
    i64 t = 9;
    for (int j = 1; j < k; ++j) {
      t *= i - j;
    }
    for (int j = 1; j < k; ++j) {
      t /= j;
      t *= 9;
    }
    r += t;
  }
  w = string(s.size(), '0');
  for (int c = 1; c < 10; ++c) {
    w[0] = char('0' + c);
    if (k == 1) {
      r += w <= s;
    } else {
      for (int i = 1; i < s.size(); ++i) {
        for (int x = 1; x < 10; ++x) {
          w[i] = char('0' + x);
          if (k == 2) {
            r += w <= s;
          } else {
            for (int j = i + 1; j < s.size(); ++j) {
              for (int y = 1; y < 10; ++y) {
                w[j] = char('0' + y);
                r += w <= s;
                w[j] = '0';
              }
            }
          }
          w[i] = '0';
        }
      }
    }
    w[0] = '0';
  }
  cout << r << '\n';
  return 0;
}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(11);
  cout.setf(ios::fixed);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#elif defined(TASK)
  freopen(TASK".in", "r", stdin);
  freopen(TASK".out", "w", stdout);
#endif
  return task::main();
}
