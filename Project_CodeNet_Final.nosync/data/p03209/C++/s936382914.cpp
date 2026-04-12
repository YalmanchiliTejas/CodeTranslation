#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define INF 2e9
#define MOD (1000000007)
#define EPS 1e-9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long long int lli;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  lli N, X;
  cin >> N >> X;
  vector< lli > P(N);
  vector< lli > S(N);
  P[0] = 1, S[0] = 1;
  REP(i, N - 1) {
    P[i + 1] = 2 * P[i] + 1;
    S[i + 1] = 2 * S[i] + 3;
    // cout << P[i + 1] << " " << S[i + 1] << "\n";
  }
  //  int i = N - 1;
  X--;
  lli ans = 0;
  REPR(i, N - 1) {
    if (X == 0) {
      break;
    } else if (1 <= X && X <= S[i]) {
      X--;
      if (i == 0)
        ans++;
    } else if (S[i] + 1 == X) {
      ans += P[i] + 1;
      break;
    } else if (S[i] + 2 <= X && X <= 2 * S[i] + 1) {
      X -= S[i] + 2;
      ans += P[i] + 1;
      if (i == 0)
        ans++;
    } else {
      ans += 2 * P[i] + 1;
      break;
    }
  }
  cout << ans << "\n";
}