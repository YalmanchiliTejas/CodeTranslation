// https://atcoder.jp/contests/abc115/tasks/abc115_d

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 50;

int N;
ll X;

ll f(int n, ll x) {
  ll m = (1LL << n + 2) - 3;
  ll m2 = (1LL << n + 1) - 3;
  ll p = (1LL << n + 1) - 1;
  ll p2 = (1LL << n)  - 1;

  if (x == 1) {
    return n == 0 ? 1 : 0;
  } else if (x < m2 + 2) {
    return f(n - 1, x - 1);
  } else if (x == m2 + 2) {
    return p2 + 1;
  } else if (x < m) {
    return p2 + 1 + f(n - 1, x - m2 - 2);
  } else {
    return p;
  }
}

void solve() {
  ll ans = f(N, X);
  printf("%lld\n", ans);
}

void input() {
  scanf("%d%lld", &N, &X);
}

int main() {
  input();
  solve();
  return 0;
}
