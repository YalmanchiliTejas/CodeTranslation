#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define range(a) a.begin(), a.end()

constexpr ll INF = 1e18;

void chmax(ll &x, ll y) {
  x = max(x, y);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N; cin >> N;
  vector<ll> A(N); rep(i, N) cin >> A[i];
  vector<ll> LF(N + 1, -INF);
  vector<ll> RF(N + 1, -INF);
  vector<ll> LB(N + 1, -INF);
  vector<ll> RB(N + 1, -INF);
  LF[0] = 0;
  for (int i = 0; i + 2 <= N; i += 2) {
    chmax(LF[i + 2], LF[i] + A[i]);
    chmax(RF[i + 2], LF[i] + A[i + 1]);
    chmax(RF[i + 2], RF[i] + A[i + 1]);
  }
  RB[N] = 0;
  for (int i = N; i - 2 >= 0; i -= 2) {
    chmax(RB[i - 2], RB[i] + A[i - 1]);
    chmax(LB[i - 2], RB[i] + A[i - 2]);
    chmax(LB[i - 2], LB[i] + A[i - 2]);
  }
  ll ans = LLONG_MIN;
  if (N % 2 == 1) {
    for (int i = 0; i < N; i += 2) {
      chmax(ans, max(LF[i], RF[i]) + max(LB[i + 1], RB[i + 1]));
    }
  } else {
    for (int i = 0; i <= N; i += 2) {
      chmax(ans, LF[i] + LB[i]);
      chmax(ans, LF[i] + RB[i]);
      chmax(ans, RF[i] + RB[i]);
    }
  }
  cout << ans << endl;
}