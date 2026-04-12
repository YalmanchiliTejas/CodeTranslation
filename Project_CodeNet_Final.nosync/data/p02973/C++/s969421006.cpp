#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()
const long long INF = 1e18;
using namespace std;
typedef long long ll;
int main() {
  ll N;
  cin >> N;
  ll A[N];
  REP(i, N) { cin >> A[i]; }
  deque<ll> d;
  REP(i, N) {
    ll p = lower_bound(ALL(d), A[i]) - d.begin();
    if (p == 0) {
      d.push_front(A[i]);
    } else {
      d[p - 1] = A[i];
    }
  }
  cout << d.size();
  return 0;
}