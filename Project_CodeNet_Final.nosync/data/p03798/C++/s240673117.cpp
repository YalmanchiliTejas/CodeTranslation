#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

//------------------------------------------------------------------------------
const int N_MAX = 100000;

int N;
char s[N_MAX + 1];
char t[N_MAX + 2];

void input() {
  scanf("%d", &N);
  scanf("%s", s);
}

void solve() {
  REP(i, 4) {
    int f[2];
    fill(t, t + N + 2, 0);
    REP(k, 2) {
      f[k] = i >> k & 1;
      t[k] = (f[k] == 0 ? 'S' : 'W');
    }
    // printf("%d: %s\n", i, t);
    REP(k, N) {
      int g = f[0] ^ f[1] ^ (s[k] == 'o' ? 0 : 1);
      t[k + 2] = (g == 0 ? 'S' : 'W');
      f[0] = f[1]; f[1] = g;
      // printf("%d:%c:%d%d:%s\n", k, s[k], f[0], f[1], t);
    }
    bool ok = true;
    REP(k, 2) {
      if (t[k] != t[N + k]) ok = false;
    }
    if (ok) {
      t[N + 1] = '\0';
      puts(t + 1);
      return;
    }
  }
  puts("-1");
}

int main() {
  input();
  solve();
  return 0;
}
