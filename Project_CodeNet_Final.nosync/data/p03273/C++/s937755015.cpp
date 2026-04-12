#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 123;

char a[N][N];
bool sc[N], sr[N];

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf(" %c", a[i]+j);
      if (a[i][j] == '#') {
	sr[i] = true;
	sc[j] = true;
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    if (!sr[i]) continue;
    for (int j = 0; j < w; ++j) {
      if (!sc[j]) continue;
      putchar(a[i][j]);
    }
    puts("");
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
