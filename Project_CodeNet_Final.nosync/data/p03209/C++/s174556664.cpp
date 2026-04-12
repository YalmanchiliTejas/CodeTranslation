#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(type, i, a, b) for (type i = (a); i < (b); ++i)

ll l[51];
ll p[51];

ll solve(int N, ll X) {
  if (X == 0) return 0;
  else if (N == 0) return 1;
  else if (X == l[N]) return p[N];
  else if (X >= l[N]/2+1) return p[N-1]+1 + solve(N-1, X - (l[N]/2+1));
  else if (X > 1) return solve(N-1, X-1);
  else return 0;
}

int main(void) {
  l[0] = 1;
  FOR(int, i, 1, 51) l[i] = l[i-1]*2+3;
  p[0] = 1;
  FOR(int, i, 1, 51) p[i] = p[i-1]*2+1;


  int N; ll X; cin >> N >> X;
  cout << solve(N, X) << endl;

  return 0;
}
