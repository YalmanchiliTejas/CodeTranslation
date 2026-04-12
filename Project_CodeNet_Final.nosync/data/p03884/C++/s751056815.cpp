#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

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
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

long long kk;

int read() {
  if (scanf("%lld", &kk) < 1) {
    return false;
  }
  return true;
}

const string f = "FESTIVAL";
const int p = 200;
string s;

void solve(int pos, long long k) {
  k--;
  while (k % p) {
    s += f[pos];
    k--;
  }
  if (!k) {
    return;
  }
  solve(pos - 1, k / p);
  for (int i = 0; i < p; i++) {
    s += f[pos];
  }
}

void solve() {
  s = f;
  solve(7, kk);
  printf("%s\n", s.c_str());
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
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
