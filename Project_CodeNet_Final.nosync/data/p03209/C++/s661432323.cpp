#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, X;
ll p[51], q[51];
ll ans;

void dfs(ll n, ll t) {
  if (n == 0) {
    return;
  }

  if (t + 1 <= X && X < t + 1 + q[n - 1]) {
    dfs(n - 1, t + 1);
  } else if (t + 1 + q[n - 1] == X) {
    ans += p[n - 1];
  } else if (t + 1 + q[n - 1] + 1 <= X && X < t + 1 + q[n - 1] + 1 + q[n - 1]) {
    ans += p[n - 1] + 1;
    dfs(n - 1, t + 1 + q[n - 1] + 1);
  } else if (t + 1 + q[n - 1] + 1 + q[n - 1] <= X) {
    ans += p[n - 1] + 1 + p[n - 1];
  }
}

int main(void) {
  cin >> N >> X;

  p[0] = q[0] = 1;
  REP(i, 0, N) {
    p[i + 1] = p[i] * 2 + 1;
    q[i + 1] = q[i] * 2 + 3;
  }

  dfs(N, 0);
  cout << ans << endl;
}