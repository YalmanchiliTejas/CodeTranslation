#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

void precalc() {
}

long long x;

int read() {
  if (scanf("%lld", &x) < 1) {
    return 0;
  }
  return 1;
}

const int len = 8;
const char str[] = "FESTIVAL";

const int k = 180;

void solve() {
  string ans = str;
  --x;
  for (int iter = 0; x && iter < len; ++iter) {
    int rem = x % k;
    x /= k;
    ans += string(rem, str[len - 1]);
    if (iter < len - 1) {
      for (int i = len - 2; i >= iter; --i) {
        if (i - 1 >= iter) {
          ans += string(k - 2, str[i - 1]);
          ans += str[i];
          ans += str[i - 1];
          --i;
        } else {
          ans += string(k - 1, str[i]);
        }
      }
    }
  }
  assert(!x);
  printf("%s\n", ans.c_str());
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
